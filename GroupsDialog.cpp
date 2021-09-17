#include "GroupsDialog.h"
#include "ui_GroupsDialog.h"

#include "AddressBookDAO.h"
#include "AddressBookGroup.h"

GroupsDialog::GroupsDialog(int key, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupsDialog)
{
    ui->setupUi(this);

    dlgGID = key;

    init();

}

GroupsDialog::~GroupsDialog()
{
    delete ui;
}

void GroupsDialog::init()
{
    if (dlgGID > 0)
        readEntry(dlgGID);

}

void GroupsDialog::readEntry(int key)
{
    AddressBookGroup* answerDB = AddressBookDAO::readGroup(key);
    if (answerDB == nullptr)
        return;

    ui->lineEdit->setText(answerDB->getGroupName());
    ui->btnSave->setEnabled(false);
    isModified = false;

    delete answerDB;

}

bool GroupsDialog::entryIsValid()
{
    bool retValue = true;

    // sprawdzanie czy pole nie jest puste
    if (ui->lineEdit->text().length() == 0)
    {
        QMessageBox::critical(this, this->windowTitle(), tr("Entry missing"));
        ui->lineEdit->setFocus();
        retValue = false;
    }
    // spr czy wpis istnieje, nie mozna dublowac
    else if (AddressBookDAO::groupExists(ui->lineEdit->text()))
    {
        QMessageBox::critical(this, this->windowTitle(), tr("Group name already exists. Give another one"));
        ui->lineEdit->setFocus();
        retValue = false;
    }

    return retValue;

}

bool GroupsDialog::saveEntry()
{
    bool retValue = false;

    if (!entryIsValid())
        return retValue;

    if (dlgGID > 0)
        retValue = updateEntry(dlgGID);
    else
        retValue = insertEntry();

    if (retValue)
        emit refreshData();

    isModified = !retValue;

    return retValue;

}

bool GroupsDialog::updateEntry(int key)
{
    return AddressBookDAO::updateGroup(key, ui->lineEdit->text());

}

bool GroupsDialog::insertEntry()
{
    bool retValue = false;

    if (AddressBookDAO::insertGroup(ui->lineEdit->text()))
    {
        dlgGID = AddressBookDAO::getLastIdentity();
        retValue = true;
    }

    return retValue;

}

void GroupsDialog::on_btnSave_clicked()
{
    if (isModified)
    {
        if (!saveEntry())
            return;
    }

    close();

}

void GroupsDialog::on_lineEdit_textChanged(const QString &)
{
    ui->btnSave->setEnabled(true);
    isModified = true;

}

void GroupsDialog::on_lineEdit_returnPressed()
{
    this->focusNextChild();

}

void GroupsDialog::on_btnCancel_clicked()
{
    close();
}

