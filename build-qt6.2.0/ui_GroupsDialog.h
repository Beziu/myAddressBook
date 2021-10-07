/********************************************************************************
** Form generated from reading UI file 'GroupsDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPSDIALOG_H
#define UI_GROUPSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupsDialog
{
public:
    QLabel *lblGroup;
    QLineEdit *lineEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnSave;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *GroupsDialog)
    {
        if (GroupsDialog->objectName().isEmpty())
            GroupsDialog->setObjectName(QString::fromUtf8("GroupsDialog"));
        GroupsDialog->resize(450, 110);
        GroupsDialog->setMinimumSize(QSize(450, 110));
        GroupsDialog->setMaximumSize(QSize(450, 110));
        QFont font;
        font.setPointSize(10);
        GroupsDialog->setFont(font);
        lblGroup = new QLabel(GroupsDialog);
        lblGroup->setObjectName(QString::fromUtf8("lblGroup"));
        lblGroup->setGeometry(QRect(10, 10, 120, 30));
        lblGroup->setFont(font);
        lineEdit = new QLineEdit(GroupsDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 10, 300, 30));
        layoutWidget = new QWidget(GroupsDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 55, 247, 37));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCancel = new QPushButton(layoutWidget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        btnSave = new QPushButton(layoutWidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        QWidget::setTabOrder(lineEdit, btnSave);
        QWidget::setTabOrder(btnSave, btnCancel);

        retranslateUi(GroupsDialog);

        QMetaObject::connectSlotsByName(GroupsDialog);
    } // setupUi

    void retranslateUi(QDialog *GroupsDialog)
    {
        GroupsDialog->setWindowTitle(QCoreApplication::translate("GroupsDialog", "Dialog", nullptr));
        lblGroup->setText(QCoreApplication::translate("GroupsDialog", "Group Name:", nullptr));
        btnCancel->setText(QCoreApplication::translate("GroupsDialog", "Cancel", nullptr));
        btnSave->setText(QCoreApplication::translate("GroupsDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupsDialog: public Ui_GroupsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPSDIALOG_H
