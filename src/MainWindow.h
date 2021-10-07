#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QDir>
#include <QFileDialog>
#include <QDebug>
#include <QCloseEvent>
#include <QTranslator>
#include <QLibraryInfo>
#include <QDialog>
#include <QSqlQuery>
#include <QTranslator>
#include <QActionGroup>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "GroupsWindow.h"
#include "ContactDialog.h"
#include "BirthdayWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   MainWindow(QWidget *parent = nullptr);
   ~MainWindow();

private slots:
   void on_actionImportContacts_triggered();

   void on_actionGroupsEdit_triggered();

   void on_tableView_doubleClicked(const QModelIndex &index);

   void on_actionEnd_triggered();

   void on_actionNew_triggered();

   void on_actionEdit_triggered();

   void on_textSearch_returnPressed();

   void updateTableView(const qint64 cid);

   void on_actionDelete_triggered();

   void on_actionBirthdaysTable_triggered();

   void on_boxGroup_activated(int index);

   void onWindowClosed(const QWidget*);

   void on_boxGroup_currentIndexChanged(int index);

private:
   Ui::MainWindow *ui;

   QLabel* statusLabel;
   QProgressBar* progressBar;
   GroupsWindow* gWindow;
   BirthdayWindow* bWindow;
   QSqlQuery* query;
   QTranslator* sysTranslator;
   QTranslator* plTranslator;
   QTranslator* deTranslator;

   QString actFile;
   QString xmlConfigFile;
   QString currentLanguage;

   bool bSysTranslatorLoaded;
   bool bPlTranslatorLoaded;
   bool bDeTranslatorLoaded;

   bool importIsRunning;
   bool stopImport;

   void init();
   void enableDatabase(bool);
   bool openDatabase(const QString& server, const QString& database);
   void closeEvent(QCloseEvent* event) override;

   void readXmlSettings(const QString& file);
   void writeXmlSettings(const QString& file);
   void openVcfFile();
   void readVcfFile(const QString &filename);
   void exportContactToXml(const QString& filename);
   bool questionSaveFile();
   qint64 getFileSize(const QString& fileName);
   QString resetValue(QString &value);
   QDate dateFromString(QString cBday);

   QSqlTableModel* setTableViewModel();
   void showTable();
   void showContactDialog(const qint64 key);
   void findItemInTableView(const QString& columnName, const QVariant& value);
   void showBoxGroupList();

   void deleteEntry(const QModelIndex index);
   void loadLanguage(const QString& lang);
   void removeAllTranslators();

   bool eventFilter(QObject* sender, QEvent* event) override;
   void updateLabel();

   QSqlTableModel *searchContacts(QString searchName);
   void searchByGroup(int groupName);

   void reject();

};
#endif // MAINWINDOW_H
