#ifndef BIRTHDAYWINDOW_H
#define BIRTHDAYWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QVariant>
#include <QKeyEvent>

namespace Ui {
class BirthdayWindow;
}

class BirthdayWindow : public QMainWindow
{
   Q_OBJECT

public:
   explicit BirthdayWindow(QWidget *parent = nullptr);
   ~BirthdayWindow();

private:
   Ui::BirthdayWindow *ui;

   QLabel* statusLabel;
   QSqlQueryModel *setQueryModel();

   void init();
   void showTable();

   void updateLabel();

};

#endif // BIRTHDAYWINDOW_H
