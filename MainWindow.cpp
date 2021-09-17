#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "DAOLib.h"
#include "AddressBookDAO.h"
#include "AddressBookContact.h"
#include "ContactDialog.h"
#include "DateStyledItemDelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    gWindow = nullptr;
    bWindow = nullptr;
    importIsRunning = false;

    statusLabel = new QLabel(this);
    statusLabel->setIndent(5);
    statusBar()->addWidget(statusLabel, 1);

    progressBar = new QProgressBar(this);
    QString styleSheet = "QProgressBar{border: 2px solid grey; border-radius: 5px; text-align: center;}";
    styleSheet += "QProgressBar::chunk{background-color: lightgreen;margin: 1px;}";
    progressBar->setStyleSheet(styleSheet);
    progressBar->setFixedWidth(200);
    progressBar->setVisible(false);

    statusBar()->addPermanentWidget(progressBar);

    enableDatabase(openDatabase("ZENBOOK\\SQLEXPRESS", "AddressBook"));
    QString gName = "#Default";

    if (AddressBookDAO::getGroupsCount() == 0)
        AddressBookDAO::insertGroup(gName);

    ui->tableView->installEventFilter(this);

    showTable();

    showBoxGroupList();
    setTableViewModel();

}

void MainWindow::enableDatabase(bool bEnable)
{
    if (bEnable)
        statusLabel->setText(tr("Database: ") + DAOLib::getDatabaseName());
    else
        statusLabel->setText(tr("Database: (none)"));

}

bool MainWindow::openDatabase(const QString &server, const QString &database)
{
    QString driver = "QODBC";
    QString driverName = "DRIVER={SQL Server}";

    return DAOLib::connectToDatabase(driver, driverName, server, database);

}

void MainWindow::openVcfFile()
{
    QString actDir;
    QString defaultFilter = tr("File VCF-contacts (*.vcf)");

    actDir = QDir::homePath();

    QString filename = QFileDialog::getOpenFileName(this, tr("File VCF-Contacts"), actDir,
                                                    tr("All files (*.*);;") + defaultFilter, &defaultFilter);
    if (!filename.isEmpty())
        readVcfFile(filename);

}

void MainWindow::readVcfFile(const QString &fileName)
{
    QString cName, cSurname, cTelCell, cTelHome, cEmail, cAdrPLZ, cAdrCity, cAdrStr, cBday;
    QString line, statusText;
    int recordCounter = 0, insertCounter = 0, lineCounter = 0, msgValue, progressValue = 0;

    importIsRunning = true;
    stopImport = false;

    qint64 fileSize = getFileSize(fileName);

    progressBar->setRange(0, 100);
    progressBar->setValue(0);
    progressBar->setVisible(true);

    QFile file(fileName);

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(this, tr("File open"),
                              QString(tr("File %1 can not be open. \n%2"))
                              .arg(fileName.arg(file.errorString())));
        return;
    }
    else
    {
        statusLabel->setText(fileName);

        QTextStream in(&file);

        while (!in.atEnd())
        {
            if (stopImport)
            {
                msgValue = QMessageBox::question(this, tr("Import contacts"),
                                                 tr("Cancel the current process?"),
                                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
                if (msgValue == QMessageBox::Yes)
                    break;

                stopImport = false;
            }

            line = in.readLine();
            lineCounter++;

            progressValue += line.length() + 2;

            progressBar->setValue(static_cast<int>((progressValue * 100) / fileSize));
            QApplication::processEvents();

            if (line.size() >= 11 && line.sliced(0, 11) == QString("BEGIN:VCARD"))
            {
                recordCounter++;
            }
            else if ((line.size() >= 2) && (line.sliced(0,2) == QString("N:")))
            {
                QStringList splitList = line.split(QLatin1Char(':'));
                QString splitName = splitList[1];

                QStringList splitNameList = splitName.split(QLatin1Char(';'));
                cSurname = splitNameList[0];
                cName = splitNameList[1];

            }
            else if (line.size() >= 6 && line.sliced(0, 6) == QString("EMAIL;"))
            {
                QStringList splitList = line.split(QLatin1Char(':'));
                cEmail = splitList[1];

            }
            else if (line.size() >= 14 && line.sliced(0, 14) == QString("TEL;TYPE=CELL:"))
            {
                QStringList splitList = line.split(QLatin1Char(':'));
                cTelCell = splitList[1];

            }
            else if (line.size() >= 14 && line.sliced(0, 14) == QString("TEL;TYPE=HOME:"))
            {
                QStringList splitList = line.split(QLatin1Char(':'));
                cTelHome = splitList[1];

            }
            else if (line.size() >= 5 && line.sliced(0, 5) == QString("BDAY:"))
            {
                QStringList splitList = line.split(QLatin1Char(':'));
                cBday = splitList[1];
                cBday.insert(6, "-");
                cBday.insert(4, "-");

            }
            else if (line.size() >= 14 && line.sliced(0, 14) == QString("ADR;TYPE=HOME:"))
            {
                QStringList splitList = line.split(QLatin1Char(':'));
                QString splitAddress = splitList[1];

                QStringList splitAddressList = splitAddress.split(QLatin1Char(';'));
                if (splitAddressList.size() > 7)
                {
                    cAdrCity = splitAddressList[3];
                    cAdrPLZ = splitAddressList[5];
                    QString splitStr = splitAddressList[7];

                    QStringList splitAddStr = splitStr.split(QLatin1Char('\n'));

                    cAdrStr = splitAddStr[0];

                }

            }

            if (line.size() >= 9 && line.sliced(0, 9) == QString("END:VCARD"))
            {
                if (AddressBookDAO::contactExists(cName, cSurname, cTelCell, cTelHome,
                                                  cEmail, cAdrPLZ, cAdrCity, cAdrStr, cBday))
                    continue;

                if (AddressBookDAO::insertContact(cName, cSurname, cTelCell, cTelHome,
                                                  cEmail, cAdrPLZ, cAdrCity, cAdrStr, cBday))
                {
                    insertCounter++;
                    qint64 key = AddressBookDAO::getLastIdentity();

                    if (cBday.length() != 0)
                    {
                        int dayOfYear = dateFromString(cBday).dayOfYear();

                        if (AddressBookDAO::insertContactToBirthdayTable(key, dayOfYear))
                            continue;

                        //                        QSqlQuery* query = new QSqlQuery(DAOLib::getDatabaseConnection());
                        //                        query->prepare("INSERT INTO ContactsBirthdays (CID, BDAYOFYEAR) VALUES (?, ?)");
                        //                        query->addBindValue(key);
                        //                        query->addBindValue(dayOfYear);
                        //                        query->exec();
                        //                        delete query;

                    }

                    if (AddressBookDAO::insertContactToGroup(key, 1))
                        continue;

                    //                    QSqlQuery* query = new QSqlQuery(DAOLib::getDatabaseConnection());
                    //                    query->prepare("INSERT INTO ContactGroup (CID, GID) VALUES (?, 1)");
                    //                    query->addBindValue(key);
                    //                    query->exec();
                    //                    delete query;

                }

                resetValue(cName);
                resetValue(cSurname);
                resetValue(cTelCell);
                resetValue(cTelHome);
                resetValue(cEmail);
                resetValue(cAdrPLZ);
                resetValue(cAdrCity);
                resetValue(cAdrStr);
                resetValue(cBday);

            }
        }
    }

    file.close();

    progressBar->setVisible(false);
    statusLabel->setText(statusText);

    if (stopImport)
    {
        QMessageBox::information(this, tr("Import contacts"),
                                 tr("The import of the data records was canceled by the user"));

    }
    else
    {
        QMessageBox::information(this, tr("Import contacts"),
                                 QString(tr("%L1 records were read.\n%L2 records were imported successfully"))
                                 .arg(recordCounter).arg(insertCounter));

    }

    importIsRunning = false;

    setTableViewModel();
    updateLabel();

}

QDate MainWindow::dateFromString(QString cBday)
{
    int bDayY, bDayM, bDayD;

    bDayY = cBday.sliced(0, 4).toInt();
    bDayM = cBday.sliced(5, 2).toInt();
    bDayD = cBday.sliced(8, 2).toInt();

    return QDate(bDayY, bDayM, bDayD);

}

qint64 MainWindow::getFileSize(const QString &fileName)
{
    qint64 retValue = 0;

    QFile file(fileName);
    if (file.open(QFile::ReadOnly))
    {
        retValue = file.size();
        file.close();
    }

    return retValue;

}

QString MainWindow::resetValue(QString &value)
{
    return (value = "");

}

QSqlTableModel *MainWindow::setTableViewModel()
{
    delete ui->tableView->model();

    QSqlTableModel* model = AddressBookDAO::readContactsIntoTableModel();

    model->sort(model->record().indexOf("CSURNAME"), Qt::SortOrder::AscendingOrder);

    model->setHeaderData(model->record().indexOf("CNAME"), Qt::Horizontal, "Name");
    model->setHeaderData(model->record().indexOf("CSURNAME"), Qt::Horizontal, "Surname");
    model->setHeaderData(model->record().indexOf("CTELEPHONECELL"), Qt::Horizontal, "Number Cell");
    model->setHeaderData(model->record().indexOf("CTELEPHONEHOME"), Qt::Horizontal, "Number Home");
    model->setHeaderData(model->record().indexOf("CEMAIL"), Qt::Horizontal, "Email");
    model->setHeaderData(model->record().indexOf("CADDRESSPLZ"), Qt::Horizontal, "PLZ");
    model->setHeaderData(model->record().indexOf("CADDRESSCITY"), Qt::Horizontal, "City");
    model->setHeaderData(model->record().indexOf("CADDRESSSTREET"), Qt::Horizontal, "Street");
    model->setHeaderData(model->record().indexOf("CBIRTHDAY"), Qt::Horizontal, "Birthday");

    //DateStyledItemDelegate* delegate = new DateStyledItemDelegate(this, "dd.MM.yyyy");
    //ui->tableView->setItemDelegateForColumn(model->record().indexOf("CBIRTHDAY"), delegate);

    ui->tableView->setModel(model);

    updateLabel();

    return model;

}

void MainWindow::showTable()
{
    QSqlTableModel* model = setTableViewModel();

    ui->tableView->setStyleSheet("QHeaderView::section {background-color: lightgrey;}");

    ui->tableView->horizontalHeader()->setStyleSheet("color: Black;");
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->tableView->hideColumn(model->record().indexOf("CID"));

    if (model->rowCount() > 0)
        ui->tableView->selectRow(0);

}

void MainWindow::showContactDialog(const qint64 key)
{
    ContactDialog cDialog(key, this);

    connect(&cDialog, SIGNAL(refreshData(const qint64)), this, SLOT(updateTableView(const qint64)));

    cDialog.exec();

}

void MainWindow::findItemInTableView(const QString &columnName, const QVariant &value)
{
    bool found = false;

    QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableView->model());

    QSqlQuery query = model->query();

    int colIndex = model->record().indexOf(columnName);

    if (colIndex < 0)
        return;

    query.first();

    int row = query.at();

    do
    {
        if (query.value(colIndex).toString().contains(value.toString(), Qt::CaseInsensitive))
        {
            found = true;
            break;
        }

        row++;

    } while (query.next());


    if (found)
        ui->tableView->selectRow(row);
    else
        ui->tableView->selectRow(0);

}

void MainWindow::showBoxGroupList()
{
    QSqlQueryModel *query = new QSqlQueryModel;

    QString SQL = "SELECT GNAME, GID FROM Groups ORDER BY GNAME";

    query->setQuery(SQL, DAOLib::getDatabaseConnection());

    ui->boxGroup->setModel(query);

    ui->boxGroup->show();

}

void MainWindow::deleteEntry(const QModelIndex index)
{

    QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableView->model());

    qint64 key = model->record(index.row()).value("CID").toLongLong();

    QString name = model->record(index.row()).value("CNAME").toString();
    QString surname = model->record(index.row()).value("CSURNAME").toString();

    int msgValue = QMessageBox::question(this, this->windowTitle(),
                                         tr("Do you want to remove entry\n") + name + " " + surname,
                                         QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

    if (msgValue == QMessageBox::No)
        return;

    if (!AddressBookDAO::deleteContact(key))
        return;

    AddressBookDAO::deleteContactFromAllGroups(key);

    setTableViewModel();
    updateLabel();

    int row = (index.row() - 1 < 0) ? 0 : index.row() - 1;

    if (ui->tableView->model()->rowCount() > 0)
        ui->tableView->selectRow(row);

}

QSqlTableModel *MainWindow::searchContacts(QString searchVal)
{
    delete ui->tableView->model();

    QSqlTableModel* model = AddressBookDAO::searchContacts(searchVal);

    model->setHeaderData(model->record().indexOf("CNAME"), Qt::Horizontal, "Name");
    model->setHeaderData(model->record().indexOf("CSURNAME"), Qt::Horizontal, "Surname");
    model->setHeaderData(model->record().indexOf("CTELEPHONECELL"), Qt::Horizontal, "Number Cell");
    model->setHeaderData(model->record().indexOf("CTELEPHONEHOME"), Qt::Horizontal, "Number Home");
    model->setHeaderData(model->record().indexOf("CEMAIL"), Qt::Horizontal, "Email");
    model->setHeaderData(model->record().indexOf("CADDRESSPLZ"), Qt::Horizontal, "PLZ");
    model->setHeaderData(model->record().indexOf("CADDRESSCITY"), Qt::Horizontal, "City");
    model->setHeaderData(model->record().indexOf("CADDRESSSTREET"), Qt::Horizontal, "Street");
    model->setHeaderData(model->record().indexOf("CBIRTHDAY"), Qt::Horizontal, "Birthday");

    ui->tableView->setModel(model);

    while(model->canFetchMore())
        model->fetchMore();

    updateLabel();
    ui->textSearch->selectAll();

    return model;

}

void MainWindow::searchByGroup(int gid)
{
    delete ui->tableView->model();

    QSqlQueryModel* model = AddressBookDAO::readContactsFromSelectedGroup(gid);

    model->setHeaderData(model->record().indexOf("CNAME"), Qt::Horizontal, "Name");
    model->setHeaderData(model->record().indexOf("CSURNAME"), Qt::Horizontal, "Surname");
    model->setHeaderData(model->record().indexOf("CTELEPHONECELL"), Qt::Horizontal, "Number Cell");
    model->setHeaderData(model->record().indexOf("CTELEPHONEHOME"), Qt::Horizontal, "Number Home");
    model->setHeaderData(model->record().indexOf("CEMAIL"), Qt::Horizontal, "Email");
    model->setHeaderData(model->record().indexOf("CADDRESSPLZ"), Qt::Horizontal, "PLZ");
    model->setHeaderData(model->record().indexOf("CADDRESSCITY"), Qt::Horizontal, "City");
    model->setHeaderData(model->record().indexOf("CADDRESSSTREET"), Qt::Horizontal, "Street");
    model->setHeaderData(model->record().indexOf("CBIRTHDAY"), Qt::Horizontal, "Birthday");

    ui->tableView->setModel(model);
    ui->tableView->setStyleSheet("QHeaderView::section {background-color: lightgrey;}");
    ui->tableView->hideColumn(model->record().indexOf("CID"));

    ui->tableView->horizontalHeader()->setStyleSheet("color: Black;");
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    while(model->canFetchMore())
        model->fetchMore();

    ui->textSearch->setText("");

    statusLabel->setText(tr("Refreshing..."));

    QApplication::processEvents();

    QString msg = QString(tr("Total count: %1")).arg(AddressBookDAO::getContactsInGroupCount(gid));
    statusLabel->setText(msg);

}


bool MainWindow::eventFilter(QObject *sender, QEvent *event)
{
    if (sender == ui->tableView)
    {
        if (event->type() == QEvent::KeyPress)
        {

            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

            // klawisz Home ustawia z powrotem na pozycje 1
            if (keyEvent->key() == Qt::Key_Home)
            {
                ui->tableView->scrollToTop();
                ui->tableView->selectRow(0);
            }
            else if (keyEvent->key() == Qt::Key_End)
            {
                ui->tableView->scrollToBottom();
                ui->tableView->selectRow(ui->tableView->model()->rowCount() - 1);
            }
            else if (keyEvent->key() == Qt::Key_Return)
            {
                on_tableView_doubleClicked(ui->tableView->currentIndex());
            }
            else if (keyEvent->key() == Qt::Key_Delete)
            {
                deleteEntry(ui->tableView->currentIndex());
            }
        }
    }

    return QObject::eventFilter(sender, event);

}

void MainWindow::updateLabel()
{
    statusLabel->setText(tr("Refreshing..."));
    QApplication::processEvents();

    QString msg = QString(tr("Total count: %1")).arg(AddressBookDAO::getContactsCount());
    statusLabel->setText(msg);

}

void MainWindow::on_actionGroupsEdit_triggered()
{
    delete gWindow;

    gWindow = new GroupsWindow(this);

    connect(gWindow, SIGNAL(windowClosed(const QWidget*)), this, SLOT(onWindowClosed(const QWidget*)));

    gWindow->show();

}

void MainWindow::onWindowClosed(const QWidget * widget)
{
    showBoxGroupList();
    setTableViewModel();

    if (widget == gWindow)
    {
        delete gWindow;

        gWindow = nullptr;
    }

}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableView->model());

    showContactDialog(model->record(index.row()).value("CID").toLongLong());

}

void MainWindow::closeEvent(QCloseEvent * event)
{
    if (importIsRunning)
        event->ignore();
    else
    {
        DAOLib::closeConnection();
        event->accept();
    }

}

void MainWindow::on_actionImportContacts_triggered()
{
    openVcfFile();
}

void MainWindow::on_actionEnd_triggered()
{
    close();
}

void MainWindow::on_actionNew_triggered()
{
    showContactDialog(-1);

}

void MainWindow::on_actionEdit_triggered()
{
    QModelIndex index = ui->tableView->currentIndex();

    on_tableView_doubleClicked(index);

}

void MainWindow::on_textSearch_returnPressed()
{
    setTableViewModel();
    // set group list box to delauft group
    ui->boxGroup->setCurrentIndex(0);

    if (ui->textSearch->text() != "")
        searchContacts(ui->textSearch->text());
    else
        setTableViewModel();

}

void MainWindow::updateTableView(const qint64 cid)
{
    setTableViewModel();
    updateLabel();
    findItemInTableView("CID", QVariant(cid));

}

void MainWindow::on_actionDelete_triggered()
{
    deleteEntry(ui->tableView->currentIndex());

}

void MainWindow::on_actionBirthdaysTable_triggered()
{
    delete bWindow;

    bWindow = new BirthdayWindow(this);
    bWindow->show();

}

void MainWindow::on_boxGroup_currentIndexChanged(int index)
{
    searchByGroup(index);

}

void MainWindow::on_boxGroup_activated(int)
{
    // Gets selected groups name
    QString gName = ui->boxGroup->currentText();

    // Gets gid from name
    int groupID = AddressBookDAO::getGroupID(gName);

    // call table view filtered by groupid
    searchByGroup(groupID);

}

void MainWindow::reject()
{
    close();
}










