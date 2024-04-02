/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MyDialog
{
public:
    QPushButton *acceptbt;
    QPushButton *rejectbt;
    QPushButton *donebt;

    void setupUi(QDialog *MyDialog)
    {
        if (MyDialog->objectName().isEmpty())
            MyDialog->setObjectName("MyDialog");
        MyDialog->resize(400, 300);
        acceptbt = new QPushButton(MyDialog);
        acceptbt->setObjectName("acceptbt");
        acceptbt->setGeometry(QRect(20, 20, 92, 28));
        rejectbt = new QPushButton(MyDialog);
        rejectbt->setObjectName("rejectbt");
        rejectbt->setGeometry(QRect(20, 70, 92, 28));
        donebt = new QPushButton(MyDialog);
        donebt->setObjectName("donebt");
        donebt->setGeometry(QRect(20, 120, 92, 28));

        retranslateUi(MyDialog);

        QMetaObject::connectSlotsByName(MyDialog);
    } // setupUi

    void retranslateUi(QDialog *MyDialog)
    {
        MyDialog->setWindowTitle(QCoreApplication::translate("MyDialog", "Dialog", nullptr));
        acceptbt->setText(QCoreApplication::translate("MyDialog", "Accept", nullptr));
        rejectbt->setText(QCoreApplication::translate("MyDialog", "Reject", nullptr));
        donebt->setText(QCoreApplication::translate("MyDialog", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyDialog: public Ui_MyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
