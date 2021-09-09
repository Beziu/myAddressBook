#ifndef BIRTHDAYDIALOG_H
#define BIRTHDAYDIALOG_H

#include <QDialog>

namespace Ui {
class BirthdayDialog;
}

class BirthdayDialog : public QDialog
{
   Q_OBJECT

public:
   explicit BirthdayDialog(QWidget *parent = nullptr);
   ~BirthdayDialog();

private:
   Ui::BirthdayDialog *ui;
};

#endif // BIRTHDAYDIALOG_H
