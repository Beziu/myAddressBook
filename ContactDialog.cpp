#include "ContactDialog.h"
#include "ui_ContactDialog.h"

#include "AddressBookDAO.h"
#include "AddressBookContact.h"
#include "AddressBookGroup.h"

ContactDialog::ContactDialog(qint64 key, QWidget *parent) :
   QDialog(parent),
   ui(new Ui::ContactDialog)
{
   ui->setupUi(this);

   dlgCID = key;

   init();

}

ContactDialog::~ContactDialog()
{
   delete ui;
}

void ContactDialog::init()
{
   if (dlgCID > 0)
      readEntry(dlgCID);

   setBirthday = false;

   showGroupList();
   //selectGroupsToContact(dlgCID);

}

void ContactDialog::readEntry(qint64 key)
{
   AddressBookContact* answerDB = AddressBookDAO::readContact(key);

   if (answerDB == nullptr)
      return;

   ui->textName->setText(answerDB->getContactName());
   ui->textSurname->setText(answerDB->getContactSurname());
   ui->textPhone1->setText(answerDB->getContactTelephoneNumberCell());
   ui->textPhone2->setText(answerDB->getContactTelephoneNumberHome());
   ui->textEmail->setText(answerDB->getContactEmail());
   ui->textCity->setText(answerDB->getContactAddressCity());
   ui->textPLZ->setText(answerDB->getContactAddressPLZ());
   ui->textStreet->setText(answerDB->getContactAddressStreet());

   if (answerDB->getContactBirthday() == "")
      ui->calendarWidget->setSelectedDate(QDate::currentDate());
   else
      ui->calendarWidget->setSelectedDate(dateFromString(answerDB->getContactBirthday()));

   isModified = false;

   delete answerDB;

}

bool ContactDialog::saveEntry()
{
   bool retValue = 0;

   if (dlgCID > 0)
      retValue = updateEntry(dlgCID);
   else
      retValue = insertEntry();

   if (retValue)
      emit refreshData(dlgCID);

   isModified = !retValue;

   return retValue;

}

void ContactDialog::showGroupList()
{
   QString SQL = "SELECT GID, GNAME FROM Groups ORDER BY GNAME";

   QSqlQuery query (SQL, DAOLib::getDatabaseConnection());

   while (query.next()) {

      QListWidgetItem* item = new QListWidgetItem();

      item->setFlags(item->flags() | Qt::ItemIsUserCheckable);

      if (AddressBookDAO::checkContactInGroup(dlgCID, query.value("GID").toInt()))
         item->setCheckState(Qt::Checked);
      else
         item->setCheckState(Qt::Unchecked);

      item->setText(query.value("GNAME").toString());
      item->setData(1, query.value("GID").toInt());

      ui->listGroups->addItem(item);

   }

}

void ContactDialog::on_listGroups_itemClicked(QListWidgetItem *)
{
   for (int i = 0; i < ui->listGroups->count(); i++)
   {

       if (ui->listGroups->item(i)->checkState() == Qt::Checked)
       {
          if (!AddressBookDAO::checkContactInGroup(dlgCID, ui->listGroups->item(i)->data(1).toInt()))
             AddressBookDAO::insertContactToGroup(dlgCID, ui->listGroups->item(i)->data(1).toInt());
       }

       //qDebug() << "numery w if: " + QString::number(ui->listGroups->item(i)->data(1).toInt());
       if (ui->listGroups->item(i)->checkState() == Qt::Unchecked)
       {
          if (AddressBookDAO::checkContactInGroup(dlgCID, ui->listGroups->item(i)->data(1).toInt()))
             AddressBookDAO::deleteContactFromGroup(dlgCID, ui->listGroups->item(i)->data(1).toInt());
       }

   }

}

bool ContactDialog::updateEntry(qint64 key)
{
   bool retValue = false;
   QString BdayString;
   QDate Bday = ui->calendarWidget->selectedDate();

   if (setBirthday == true)
      BdayString = dateToString(Bday);
   else
      BdayString = "";

   int dayOfYear = Bday.dayOfYear();

   QSqlQuery* query = new QSqlQuery(DAOLib::getDatabaseConnection());
   query->prepare("INSERT INTO ContactsBirthdays (CID, BDAYOFYEAR) VALUES (?, ?)");
   query->addBindValue(key);
   query->addBindValue(dayOfYear);
   query->exec();
   delete query;

   return AddressBookDAO::updateContact(key, ui->textName->text(), ui->textSurname->text(),
                                        ui->textPhone1->text(), ui->textPhone2->text(),
                                        ui->textEmail->text(), ui->textPLZ->text(),
                                        ui->textCity->text(), ui->textStreet->text(),
                                        BdayString);
   {
      dlgCID = AddressBookDAO::getLastIdentity();
      retValue = true;
   }

   return retValue;

}

bool ContactDialog::insertEntry()
{
   bool retValue = false;
   QString BdayString;
   QDate Bday = ui->calendarWidget->selectedDate();

   if (setBirthday == true)
      BdayString = dateToString(Bday);
   else
      BdayString = "";

   if (AddressBookDAO::insertContact(ui->textName->text(), ui->textSurname->text(),
                                     ui->textPhone1->text(), ui->textPhone2->text(),
                                     ui->textEmail->text(), ui->textPLZ->text(),
                                     ui->textCity->text(), ui->textStreet->text(),
                                     BdayString))
   {
      dlgCID = AddressBookDAO::getLastIdentity();

      // Wstawiania kontakt domyslnie do grupy pierwszej
      QSqlQuery* query = new QSqlQuery(DAOLib::getDatabaseConnection());
      query->prepare("INSERT INTO ContactGroup (CID, GID) VALUES (?, 1)");
      query->addBindValue(dlgCID);
      query->exec();
      delete query;

      retValue = true;
   }

   return retValue;

}

QDate ContactDialog::dateFromString(QString cBday)
{
   int bDayY, bDayM, bDayD;

   bDayY = cBday.sliced(0, 4).toInt();
   bDayM = cBday.sliced(5, 2).toInt();
   bDayD = cBday.sliced(8, 2).toInt();

   return QDate(bDayY, bDayM, bDayD);

}

QString ContactDialog::dateToString(QDate cBday)
{
   QString retVal = QString::number(cBday.year()) + "-";
   retVal += QString::number(cBday.month()) + "-";
   retVal += QString::number(cBday.day());

   return retVal;

}

void ContactDialog::on_btnSave_clicked()
{
   if (isModified)
   {
      if (!saveEntry())
         return;
   }

   close();

}

void ContactDialog::on_btnCancel_clicked()
{
   close();

}

void ContactDialog::on_textName_textChanged(const QString &)
{
    ui->btnSave->setEnabled(true);
    isModified = true;

}

void ContactDialog::on_textSurname_textChanged(const QString &)
{
   ui->btnSave->setEnabled(true);
   isModified = true;

}

void ContactDialog::on_textPhone1_textChanged(const QString &)
{
   ui->btnSave->setEnabled(true);
   isModified = true;

}

void ContactDialog::on_textPhone2_textChanged(const QString &)
{
   ui->btnSave->setEnabled(true);
   isModified = true;

}

void ContactDialog::on_textEmail_textChanged(const QString &)
{
   ui->btnSave->setEnabled(true);
   isModified = true;

}

void ContactDialog::on_textPLZ_textChanged(const QString &)
{
   ui->btnSave->setEnabled(true);
   isModified = true;

}

void ContactDialog::on_textCity_textChanged(const QString &)
{
   ui->btnSave->setEnabled(true);
   isModified = true;

}

void ContactDialog::on_textStreet_textChanged(const QString &)
{
   ui->btnSave->setEnabled(true);
   isModified = true;

}

void ContactDialog::on_calendarWidget_selectionChanged()
{
   on_checkBirthday_toggled(true);
   ui->checkBirthday->setChecked(true);
   isModified = true;
}


void ContactDialog::on_checkBirthday_toggled(bool checked)
{
   if (checked)
   {
      setBirthday = true;
      isModified = true;
   }

}




