/********************************************************************************
** Form generated from reading UI file 'BirthdayWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIRTHDAYWINDOW_H
#define UI_BIRTHDAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BirthdayWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BirthdayWindow)
    {
        if (BirthdayWindow->objectName().isEmpty())
            BirthdayWindow->setObjectName(QString::fromUtf8("BirthdayWindow"));
        BirthdayWindow->resize(380, 455);
        BirthdayWindow->setMinimumSize(QSize(380, 0));
        BirthdayWindow->setMaximumSize(QSize(380, 16777215));
        QFont font;
        font.setPointSize(10);
        BirthdayWindow->setFont(font);
        centralwidget = new QWidget(BirthdayWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(350, 400));
        tableView->setMaximumSize(QSize(350, 151111));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);

        BirthdayWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(BirthdayWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BirthdayWindow->setStatusBar(statusbar);

        retranslateUi(BirthdayWindow);

        QMetaObject::connectSlotsByName(BirthdayWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BirthdayWindow)
    {
        BirthdayWindow->setWindowTitle(QCoreApplication::translate("BirthdayWindow", "Birthdays Table", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BirthdayWindow: public Ui_BirthdayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIRTHDAYWINDOW_H
