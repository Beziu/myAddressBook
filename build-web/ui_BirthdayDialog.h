/********************************************************************************
** Form generated from reading UI file 'BirthdayDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIRTHDAYDIALOG_H
#define UI_BIRTHDAYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BirthdayDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;

    void setupUi(QDialog *BirthdayDialog)
    {
        if (BirthdayDialog->objectName().isEmpty())
            BirthdayDialog->setObjectName(QString::fromUtf8("BirthdayDialog"));
        BirthdayDialog->resize(507, 571);
        verticalLayout = new QVBoxLayout(BirthdayDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(BirthdayDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(BirthdayDialog);

        QMetaObject::connectSlotsByName(BirthdayDialog);
    } // setupUi

    void retranslateUi(QDialog *BirthdayDialog)
    {
        BirthdayDialog->setWindowTitle(QCoreApplication::translate("BirthdayDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BirthdayDialog: public Ui_BirthdayDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIRTHDAYDIALOG_H
