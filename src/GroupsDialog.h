#ifndef GROUPSDIALOG_H
#define GROUPSDIALOG_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class GroupsDialog;
}

class GroupsDialog : public QDialog
{
   Q_OBJECT

public:
   explicit GroupsDialog(int key, QWidget *parent = nullptr);
   ~GroupsDialog();

signals:
   void refreshData();

private slots:
   void on_btnCancel_clicked();

   void on_btnSave_clicked();

   void on_lineEdit_textChanged(const QString &);

   void on_lineEdit_returnPressed();

private:
   Ui::GroupsDialog *ui;

   int dlgGID;
   bool isModified;

   void init();
   void readEntry(int key);

   bool entryIsValid();
   bool saveEntry();

   bool updateEntry(int key);
   bool insertEntry();


};

#endif // GROUPSDIALOG_H
