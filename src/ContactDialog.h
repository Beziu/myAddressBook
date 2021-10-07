#ifndef CONTACTDIALOG_H
#define CONTACTDIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QDebug>
#include <QModelIndexList>
#include <QItemSelectionModel>
#include <QListWidgetItem>
#include <QListWidget>


namespace Ui {
class ContactDialog;
}

class ContactDialog : public QDialog
{
   Q_OBJECT

public:
   explicit ContactDialog(qint64 key, QWidget *parent = nullptr);
   ~ContactDialog();

signals:
    void refreshData(const qint64 key);

private slots:
   void on_btnCancel_clicked();

   void on_btnSave_clicked();

   void on_textName_textChanged(const QString &arg1);

   void on_textSurname_textChanged(const QString &arg1);

   void on_textPhone1_textChanged(const QString &arg1);

   void on_textPhone2_textChanged(const QString &arg1);

   void on_textEmail_textChanged(const QString &arg1);

   void on_textPLZ_textChanged(const QString &arg1);

   void on_textCity_textChanged(const QString &arg1);

   void on_textStreet_textChanged(const QString &arg1);

   void on_calendarWidget_selectionChanged();

   void on_checkBirthday_toggled(bool checked);

   void on_listGroups_itemClicked(QListWidgetItem *item);

private:
   Ui::ContactDialog *ui;

   qint64 dlgCID;
   bool isModified;
   bool setBirthday;

   void init();
   void readEntry(qint64 key);

   bool saveEntry();
   void showGroupList();

   bool updateEntry(qint64 key);
   bool insertEntry();

   QDate dateFromString(QString cBday);
   QString dateToString(QDate cBday);

   void readGroupsList();


};

#endif // CONTACTDIALOG_H
