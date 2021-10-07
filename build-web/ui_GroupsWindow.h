/********************************************************************************
** Form generated from reading UI file 'GroupsWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPSWINDOW_H
#define UI_GROUPSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupsWindow
{
public:
    QAction *actionExit;
    QAction *actionNew;
    QAction *actionDelete;
    QAction *actionEdit;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GroupsWindow)
    {
        if (GroupsWindow->objectName().isEmpty())
            GroupsWindow->setObjectName(QString::fromUtf8("GroupsWindow"));
        GroupsWindow->resize(300, 400);
        GroupsWindow->setMinimumSize(QSize(300, 400));
        GroupsWindow->setMaximumSize(QSize(300, 400));
        QFont font;
        font.setPointSize(10);
        GroupsWindow->setFont(font);
        actionExit = new QAction(GroupsWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionNew = new QAction(GroupsWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionDelete = new QAction(GroupsWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionEdit = new QAction(GroupsWindow);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        centralwidget = new QWidget(GroupsWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setTabKeyNavigation(false);
        tableView->setAlternatingRowColors(true);
        tableView->horizontalHeader()->setDefaultSectionSize(150);
        tableView->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(tableView);

        GroupsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GroupsWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 300, 34));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        GroupsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(GroupsWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GroupsWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionEdit);
        menuFile->addAction(actionDelete);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(GroupsWindow);

        QMetaObject::connectSlotsByName(GroupsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GroupsWindow)
    {
        GroupsWindow->setWindowTitle(QCoreApplication::translate("GroupsWindow", "Groups", nullptr));
        actionExit->setText(QCoreApplication::translate("GroupsWindow", "E&xit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("GroupsWindow", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew->setText(QCoreApplication::translate("GroupsWindow", "&New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("GroupsWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDelete->setText(QCoreApplication::translate("GroupsWindow", "&Delete", nullptr));
#if QT_CONFIG(shortcut)
        actionDelete->setShortcut(QCoreApplication::translate("GroupsWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEdit->setText(QCoreApplication::translate("GroupsWindow", "&Edit", nullptr));
#if QT_CONFIG(shortcut)
        actionEdit->setShortcut(QCoreApplication::translate("GroupsWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        menuFile->setTitle(QCoreApplication::translate("GroupsWindow", "&File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupsWindow: public Ui_GroupsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPSWINDOW_H
