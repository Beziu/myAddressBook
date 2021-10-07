/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEnd;
    QAction *actionNew;
    QAction *actionEdit;
    QAction *actionDelete;
    QAction *actionImportContacts;
    QAction *actionGroupsEdit;
    QAction *actionBirthdaysTable;
    QAction *actionEnglisch;
    QAction *actionPolisch;
    QAction *actionDeutsch;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblSearch;
    QLineEdit *textSearch;
    QHBoxLayout *horizontalLayout;
    QLabel *lblGroups;
    QComboBox *boxGroup;
    QTableView *tableView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuGroups;
    QMenu *menuLanguage;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(940, 600);
        MainWindow->setMinimumSize(QSize(940, 600));
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        actionEnd = new QAction(MainWindow);
        actionEnd->setObjectName(QString::fromUtf8("actionEnd"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionImportContacts = new QAction(MainWindow);
        actionImportContacts->setObjectName(QString::fromUtf8("actionImportContacts"));
        actionGroupsEdit = new QAction(MainWindow);
        actionGroupsEdit->setObjectName(QString::fromUtf8("actionGroupsEdit"));
        actionBirthdaysTable = new QAction(MainWindow);
        actionBirthdaysTable->setObjectName(QString::fromUtf8("actionBirthdaysTable"));
        actionEnglisch = new QAction(MainWindow);
        actionEnglisch->setObjectName(QString::fromUtf8("actionEnglisch"));
        actionPolisch = new QAction(MainWindow);
        actionPolisch->setObjectName(QString::fromUtf8("actionPolisch"));
        actionDeutsch = new QAction(MainWindow);
        actionDeutsch->setObjectName(QString::fromUtf8("actionDeutsch"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lblSearch = new QLabel(centralwidget);
        lblSearch->setObjectName(QString::fromUtf8("lblSearch"));
        lblSearch->setMinimumSize(QSize(80, 25));
        lblSearch->setMaximumSize(QSize(80, 25));

        horizontalLayout_2->addWidget(lblSearch);

        textSearch = new QLineEdit(centralwidget);
        textSearch->setObjectName(QString::fromUtf8("textSearch"));
        textSearch->setMinimumSize(QSize(400, 25));
        textSearch->setMaximumSize(QSize(1088880, 25));

        horizontalLayout_2->addWidget(textSearch);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lblGroups = new QLabel(centralwidget);
        lblGroups->setObjectName(QString::fromUtf8("lblGroups"));
        lblGroups->setMinimumSize(QSize(80, 25));
        lblGroups->setMaximumSize(QSize(80, 25));

        horizontalLayout->addWidget(lblGroups);

        boxGroup = new QComboBox(centralwidget);
        boxGroup->setObjectName(QString::fromUtf8("boxGroup"));
        boxGroup->setMinimumSize(QSize(180, 25));
        boxGroup->setMaximumSize(QSize(180, 25));

        horizontalLayout->addWidget(boxGroup);


        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_3);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMaximumSize(QSize(16777215, 16777209));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        tableView->setFont(font1);
        tableView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tableView->setTabKeyNavigation(false);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setTextElideMode(Qt::ElideNone);
        tableView->setSortingEnabled(true);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 940, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuGroups = new QMenu(menubar);
        menuGroups->setObjectName(QString::fromUtf8("menuGroups"));
        menuLanguage = new QMenu(menuGroups);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuGroups->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionEdit);
        menuFile->addAction(actionDelete);
        menuFile->addSeparator();
        menuFile->addAction(actionEnd);
        menuGroups->addAction(actionBirthdaysTable);
        menuGroups->addSeparator();
        menuGroups->addAction(actionGroupsEdit);
        menuGroups->addSeparator();
        menuGroups->addAction(actionImportContacts);
        menuGroups->addAction(menuLanguage->menuAction());
        menuLanguage->addAction(actionEnglisch);
        menuLanguage->addAction(actionPolisch);
        menuLanguage->addAction(actionDeutsch);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "AddressBook", nullptr));
        actionEnd->setText(QCoreApplication::translate("MainWindow", "&Exit", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "&New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEdit->setText(QCoreApplication::translate("MainWindow", "&Edit", nullptr));
#if QT_CONFIG(shortcut)
        actionEdit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDelete->setText(QCoreApplication::translate("MainWindow", "&Delete", nullptr));
#if QT_CONFIG(shortcut)
        actionDelete->setShortcut(QCoreApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionImportContacts->setText(QCoreApplication::translate("MainWindow", "&Import contacts", nullptr));
        actionGroupsEdit->setText(QCoreApplication::translate("MainWindow", "&Groups edit", nullptr));
        actionBirthdaysTable->setText(QCoreApplication::translate("MainWindow", "&Birthdays Table", nullptr));
        actionEnglisch->setText(QCoreApplication::translate("MainWindow", "Englisch", nullptr));
        actionPolisch->setText(QCoreApplication::translate("MainWindow", "Polisch", nullptr));
        actionDeutsch->setText(QCoreApplication::translate("MainWindow", "Deutsch", nullptr));
        lblSearch->setText(QCoreApplication::translate("MainWindow", "Search:", nullptr));
        lblGroups->setText(QCoreApplication::translate("MainWindow", "Groups:", nullptr));
        boxGroup->setCurrentText(QString());
        boxGroup->setPlaceholderText(QCoreApplication::translate("MainWindow", "none", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menuGroups->setTitle(QCoreApplication::translate("MainWindow", "E&xtras", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("MainWindow", "Language", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
