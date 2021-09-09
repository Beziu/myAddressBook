#include "BirthdayDialog.h"
#include "ui_BirthdayDialog.h"

BirthdayDialog::BirthdayDialog(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::BirthdayDialog)
{
   ui->setupUi(this);
}

BirthdayDialog::~BirthdayDialog()
{
   delete ui;
}
