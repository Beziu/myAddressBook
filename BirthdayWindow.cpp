#include "BirthdayWindow.h"
#include "ui_BirthdayWindow.h"

#include "AddressBookDAO.h"

BirthdayWindow::BirthdayWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::BirthdayWindow)
{
   ui->setupUi(this);

   init();
}

BirthdayWindow::~BirthdayWindow()
{
   delete ui;
}

void BirthdayWindow::init()
{
   statusLabel = new QLabel(this);
   statusLabel->setAlignment(Qt::AlignLeft);
   statusBar()->addWidget(statusLabel, 1);

   showTable();

}

QSqlQueryModel *BirthdayWindow::setQueryModel()
{
   delete ui->tableView->model();

   QSqlQueryModel *model = new QSqlQueryModel;

   int todayOfYear = QDate::currentDate().dayOfYear();

   QString SQL = "SELECT TOP (5) CNAME, CSURNAME, CBIRTHDAY, BDAYOFYEAR FROM ";
   SQL += "Contacts, ContactsBirthdays WHERE Contacts.CID = ContactsBirthdays.CID AND ";
   SQL += "BDAYOFYEAR > " + QString::number(todayOfYear) + " ORDER BY BDAYOFYEAR";

   model->setQuery(SQL, DAOLib::getDatabaseConnection());
   model->setHeaderData(model->record().indexOf("CNAME"), Qt::Horizontal, "Name");
   model->setHeaderData(model->record().indexOf("CSURNAME"), Qt::Horizontal, "Surname");
   model->setHeaderData(model->record().indexOf("CBIRTHDAY"), Qt::Horizontal, "Birthday");

   updateLabel();

   return model;

}

void BirthdayWindow::showTable()
{
   QSqlQueryModel *model = setQueryModel();

   ui->tableView->setModel(model);
   ui->tableView->hideColumn(model->record().indexOf("BDAYOFYEAR"));
   ui->tableView->horizontalHeader()->setStretchLastSection(true);
   ui->tableView->show();

}

void BirthdayWindow::updateLabel()
{

}




