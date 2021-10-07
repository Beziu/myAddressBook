/********************************************************************************
** Form generated from reading UI file 'ContactDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTDIALOG_H
#define UI_CONTACTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ContactDialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *lbName;
    QLineEdit *textName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblSurname;
    QLineEdit *textSurname;
    QHBoxLayout *horizontalLayout_9;
    QLabel *lbPhone1;
    QLineEdit *textPhone1;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lbPhone2;
    QLineEdit *textPhone2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lblEmail;
    QLineEdit *textEmail;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lblAddressPLZ;
    QLineEdit *textPLZ;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lblAddressCity;
    QLineEdit *textCity;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblAddressStreet;
    QLineEdit *textStreet;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBirthday;
    QCalendarWidget *calendarWidget;
    QVBoxLayout *verticalLayout;
    QLabel *lblGroups;
    QListWidget *listGroups;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnSave;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *ContactDialog)
    {
        if (ContactDialog->objectName().isEmpty())
            ContactDialog->setObjectName(QString::fromUtf8("ContactDialog"));
        ContactDialog->resize(800, 600);
        ContactDialog->setMinimumSize(QSize(800, 600));
        ContactDialog->setMaximumSize(QSize(800, 600));
        QFont font;
        font.setPointSize(10);
        ContactDialog->setFont(font);
        verticalLayout_5 = new QVBoxLayout(ContactDialog);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lbName = new QLabel(ContactDialog);
        lbName->setObjectName(QString::fromUtf8("lbName"));
        lbName->setMinimumSize(QSize(220, 25));
        lbName->setMaximumSize(QSize(220, 25));
        lbName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lbName);

        textName = new QLineEdit(ContactDialog);
        textName->setObjectName(QString::fromUtf8("textName"));
        textName->setMinimumSize(QSize(250, 25));
        textName->setMaximumSize(QSize(250, 25));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("MS Shell Dlg 2")});
        font1.setPointSize(10);
        textName->setFont(font1);
        textName->setMaxLength(50);

        horizontalLayout->addWidget(textName);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lblSurname = new QLabel(ContactDialog);
        lblSurname->setObjectName(QString::fromUtf8("lblSurname"));
        lblSurname->setMinimumSize(QSize(220, 25));
        lblSurname->setMaximumSize(QSize(220, 25));
        lblSurname->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lblSurname);

        textSurname = new QLineEdit(ContactDialog);
        textSurname->setObjectName(QString::fromUtf8("textSurname"));
        textSurname->setMinimumSize(QSize(250, 25));
        textSurname->setMaximumSize(QSize(250, 25));
        textSurname->setFont(font1);
        textSurname->setMaxLength(50);

        horizontalLayout_2->addWidget(textSurname);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lbPhone1 = new QLabel(ContactDialog);
        lbPhone1->setObjectName(QString::fromUtf8("lbPhone1"));
        lbPhone1->setMinimumSize(QSize(220, 25));
        lbPhone1->setMaximumSize(QSize(220, 25));
        lbPhone1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(lbPhone1);

        textPhone1 = new QLineEdit(ContactDialog);
        textPhone1->setObjectName(QString::fromUtf8("textPhone1"));
        textPhone1->setMinimumSize(QSize(250, 25));
        textPhone1->setMaximumSize(QSize(250, 25));
        textPhone1->setFont(font1);
        textPhone1->setMaxLength(50);

        horizontalLayout_9->addWidget(textPhone1);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lbPhone2 = new QLabel(ContactDialog);
        lbPhone2->setObjectName(QString::fromUtf8("lbPhone2"));
        lbPhone2->setMinimumSize(QSize(220, 25));
        lbPhone2->setMaximumSize(QSize(220, 25));
        lbPhone2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(lbPhone2);

        textPhone2 = new QLineEdit(ContactDialog);
        textPhone2->setObjectName(QString::fromUtf8("textPhone2"));
        textPhone2->setMinimumSize(QSize(250, 25));
        textPhone2->setMaximumSize(QSize(250, 25));
        textPhone2->setFont(font1);
        textPhone2->setMaxLength(50);

        horizontalLayout_8->addWidget(textPhone2);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lblEmail = new QLabel(ContactDialog);
        lblEmail->setObjectName(QString::fromUtf8("lblEmail"));
        lblEmail->setMinimumSize(QSize(220, 25));
        lblEmail->setMaximumSize(QSize(220, 25));
        lblEmail->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(lblEmail);

        textEmail = new QLineEdit(ContactDialog);
        textEmail->setObjectName(QString::fromUtf8("textEmail"));
        textEmail->setMinimumSize(QSize(250, 25));
        textEmail->setMaximumSize(QSize(250, 25));
        textEmail->setFont(font1);
        textEmail->setMaxLength(50);

        horizontalLayout_7->addWidget(textEmail);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lblAddressPLZ = new QLabel(ContactDialog);
        lblAddressPLZ->setObjectName(QString::fromUtf8("lblAddressPLZ"));
        lblAddressPLZ->setMinimumSize(QSize(220, 25));
        lblAddressPLZ->setMaximumSize(QSize(220, 25));
        lblAddressPLZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(lblAddressPLZ);

        textPLZ = new QLineEdit(ContactDialog);
        textPLZ->setObjectName(QString::fromUtf8("textPLZ"));
        textPLZ->setMinimumSize(QSize(250, 25));
        textPLZ->setMaximumSize(QSize(250, 25));
        textPLZ->setFont(font1);
        textPLZ->setMaxLength(50);

        horizontalLayout_6->addWidget(textPLZ);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lblAddressCity = new QLabel(ContactDialog);
        lblAddressCity->setObjectName(QString::fromUtf8("lblAddressCity"));
        lblAddressCity->setMinimumSize(QSize(220, 25));
        lblAddressCity->setMaximumSize(QSize(220, 25));
        lblAddressCity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(lblAddressCity);

        textCity = new QLineEdit(ContactDialog);
        textCity->setObjectName(QString::fromUtf8("textCity"));
        textCity->setMinimumSize(QSize(250, 25));
        textCity->setMaximumSize(QSize(250, 25));
        textCity->setFont(font1);
        textCity->setMaxLength(50);

        horizontalLayout_5->addWidget(textCity);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lblAddressStreet = new QLabel(ContactDialog);
        lblAddressStreet->setObjectName(QString::fromUtf8("lblAddressStreet"));
        lblAddressStreet->setMinimumSize(QSize(220, 25));
        lblAddressStreet->setMaximumSize(QSize(220, 25));
        lblAddressStreet->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lblAddressStreet);

        textStreet = new QLineEdit(ContactDialog);
        textStreet->setObjectName(QString::fromUtf8("textStreet"));
        textStreet->setMinimumSize(QSize(250, 25));
        textStreet->setMaximumSize(QSize(250, 25));
        textStreet->setFont(font1);
        textStreet->setMaxLength(50);

        horizontalLayout_4->addWidget(textStreet);


        verticalLayout_4->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkBirthday = new QCheckBox(ContactDialog);
        checkBirthday->setObjectName(QString::fromUtf8("checkBirthday"));

        verticalLayout_2->addWidget(checkBirthday);

        calendarWidget = new QCalendarWidget(ContactDialog);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setMinimumSize(QSize(250, 200));
        calendarWidget->setMaximumSize(QSize(250, 200));

        verticalLayout_2->addWidget(calendarWidget);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblGroups = new QLabel(ContactDialog);
        lblGroups->setObjectName(QString::fromUtf8("lblGroups"));
        lblGroups->setMinimumSize(QSize(220, 25));
        lblGroups->setMaximumSize(QSize(220, 25));
        lblGroups->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(lblGroups);

        listGroups = new QListWidget(ContactDialog);
        listGroups->setObjectName(QString::fromUtf8("listGroups"));
        listGroups->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listGroups->setAlternatingRowColors(true);
        listGroups->setSelectionMode(QAbstractItemView::ExtendedSelection);
        listGroups->setSelectionBehavior(QAbstractItemView::SelectRows);
        listGroups->setSelectionRectVisible(true);

        verticalLayout->addWidget(listGroups);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        btnCancel = new QPushButton(ContactDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(120, 30));
        btnCancel->setMaximumSize(QSize(120, 30));

        horizontalLayout_10->addWidget(btnCancel);

        btnSave = new QPushButton(ContactDialog);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(120, 30));
        btnSave->setMaximumSize(QSize(120, 30));

        horizontalLayout_10->addWidget(btnSave);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_10);


        retranslateUi(ContactDialog);

        QMetaObject::connectSlotsByName(ContactDialog);
    } // setupUi

    void retranslateUi(QDialog *ContactDialog)
    {
        ContactDialog->setWindowTitle(QCoreApplication::translate("ContactDialog", "Contact", nullptr));
        lbName->setText(QCoreApplication::translate("ContactDialog", "Name: ", nullptr));
        lblSurname->setText(QCoreApplication::translate("ContactDialog", "Surname: ", nullptr));
        lbPhone1->setText(QCoreApplication::translate("ContactDialog", "Phone number, cell: ", nullptr));
        lbPhone2->setText(QCoreApplication::translate("ContactDialog", "Phone number, home: ", nullptr));
        lblEmail->setText(QCoreApplication::translate("ContactDialog", "E-mail: ", nullptr));
        lblAddressPLZ->setText(QCoreApplication::translate("ContactDialog", "Address, ZIP-code: ", nullptr));
        lblAddressCity->setText(QCoreApplication::translate("ContactDialog", "Address, City: ", nullptr));
        lblAddressStreet->setText(QCoreApplication::translate("ContactDialog", "Address, Street: ", nullptr));
        checkBirthday->setText(QCoreApplication::translate("ContactDialog", "Birthday: ", nullptr));
        lblGroups->setText(QCoreApplication::translate("ContactDialog", "Groups: ", nullptr));
        btnCancel->setText(QCoreApplication::translate("ContactDialog", "Cancel", nullptr));
        btnSave->setText(QCoreApplication::translate("ContactDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactDialog: public Ui_ContactDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTDIALOG_H
