#include "GroupsWindow.h"
#include "ui_GroupsWindow.h"

#include "AddressBookDAO.h"
#include "GroupsDialog.h"

GroupsWindow::GroupsWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::GroupsWindow)
{
   ui->setupUi(this);

   init();
}

GroupsWindow::~GroupsWindow()
{
   delete ui;
}

void GroupsWindow::init()
{

   statusLabel = new QLabel(this);
   statusLabel->setAlignment(Qt::AlignLeft);
   statusBar()->addWidget(statusLabel, 1);

   showTable();
}

QSqlTableModel *GroupsWindow::setTableViewModel()
{
   delete ui->tableView->model();

   QSqlTableModel* model = AddressBookDAO::readGroupsIntoTableModel();

   model->sort(model->record().indexOf("GNAME"), Qt::SortOrder::AscendingOrder);

   model->setHeaderData(model->record().indexOf("GNAME"), Qt::Horizontal, "Groups");

   ui->tableView->setModel(model);

   while(model->canFetchMore())
       model->fetchMore();

   return model;
}


void GroupsWindow::showTable()
{
   QSqlTableModel* model = setTableViewModel();

   QFont font = ui->tableView->horizontalHeader()->font();
   font.setPixelSize(14);
   ui->tableView->setFont(font);

   QPalette palette = ui->tableView->palette();
   palette.setColor(QPalette::HighlightedText, Qt::white);
   palette.setColor(QPalette::Highlight, QColor(0, 112, 255));

   ui->tableView->setPalette(palette);

   ui->tableView->hideColumn(model->record().indexOf("GID"));

   ui->tableView->horizontalHeader()->setStretchLastSection(true);

   updateLabel();
}


void GroupsWindow::showGroupDialog(const int key)
{
   GroupsDialog gDialog(key, this);

   connect(&gDialog, SIGNAL(refreshData()), this, SLOT(updateGroupView()));

   gDialog.exec();
}


void GroupsWindow::deleteEntry(const QModelIndex index)
{
   QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableView->model());

   int gid = model->record(index.row()).value("GID").toInt();

   QString gName = model->record(index.row()).value("GNAME").toString();

   int msgValue = QMessageBox::question(this, this->windowTitle(),
                                       tr("Delete entry: ") + gName,
                                       QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

   if (msgValue == QMessageBox::No)
       return;

   if (!AddressBookDAO::deleteGroup(gid))
       return;

   AddressBookDAO::deleteAllContactsReletionWhitGroup(gid);
   updateGroupView();
}


void GroupsWindow::updateLabel()
{
   statusLabel->setText(tr("Refreshing..."));
   QApplication::processEvents();

   QString msg = QString("Total count: %1").arg(AddressBookDAO::getGroupsCount());
   statusLabel->setText(msg);
}


void GroupsWindow::updateGroupView()
{
   setTableViewModel();

   updateLabel();
}

void GroupsWindow::closeEvent(QCloseEvent *)
{
    emit windowClosed(this);
}


void GroupsWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
   QSqlTableModel* model = static_cast<QSqlTableModel*>(ui->tableView->model());

   showGroupDialog(model->record(index.row()).value("GID").toInt());
}


void GroupsWindow::on_actionEdit_triggered()
{
   QModelIndex index = ui->tableView->currentIndex();

   on_tableView_doubleClicked(index);
}


void GroupsWindow::on_actionDelete_triggered()
{
   deleteEntry(ui->tableView->currentIndex());
}


void GroupsWindow::on_actionNew_triggered()
{
   showGroupDialog(-1);
}


void GroupsWindow::on_actionExit_triggered()
{
   //emit windowClosed(this);
   close();
}

