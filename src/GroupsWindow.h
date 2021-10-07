#ifndef GROUPSWINDOW_H
#define GROUPSWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QVariant>
#include <QKeyEvent>

namespace Ui {
class GroupsWindow;
}

class GroupsWindow : public QMainWindow
{
   Q_OBJECT

public:
   explicit GroupsWindow(QWidget *parent = nullptr);
   ~GroupsWindow();

signals:
   void windowClosed(const QWidget*);

private slots:
   void on_actionExit_triggered();

   void on_actionNew_triggered();

   void on_actionDelete_triggered();

   void on_actionEdit_triggered();

   void on_tableView_doubleClicked(const QModelIndex &index);

   void updateGroupView();

   void closeEvent(QCloseEvent *) override;

private:
   Ui::GroupsWindow *ui;

   QLabel* statusLabel;
   QSqlTableModel* setTableViewModel();

   void init();
   void showTable();
   void showGroupDialog(const int key);

   void deleteEntry(const QModelIndex index);
   void updateLabel();


};

#endif // GROUPSWINDOW_H
