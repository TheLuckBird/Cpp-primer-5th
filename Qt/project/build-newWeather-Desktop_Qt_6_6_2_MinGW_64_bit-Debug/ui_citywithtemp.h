/********************************************************************************
** Form generated from reading UI file 'citywithtemp.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CITYWITHTEMP_H
#define UI_CITYWITHTEMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cityWithTemp
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *citylbl;
    QLabel *piclbl;
    QLabel *templbl;

    void setupUi(QWidget *cityWithTemp)
    {
        if (cityWithTemp->objectName().isEmpty())
            cityWithTemp->setObjectName("cityWithTemp");
        cityWithTemp->resize(320, 50);
        cityWithTemp->setMinimumSize(QSize(0, 50));
        cityWithTemp->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(cityWithTemp);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(5, 0, 0, 0);
        citylbl = new QLabel(cityWithTemp);
        citylbl->setObjectName("citylbl");
        citylbl->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(citylbl);

        piclbl = new QLabel(cityWithTemp);
        piclbl->setObjectName("piclbl");
        piclbl->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(piclbl);

        templbl = new QLabel(cityWithTemp);
        templbl->setObjectName("templbl");

        horizontalLayout->addWidget(templbl);


        retranslateUi(cityWithTemp);

        QMetaObject::connectSlotsByName(cityWithTemp);
    } // setupUi

    void retranslateUi(QWidget *cityWithTemp)
    {
        cityWithTemp->setWindowTitle(QCoreApplication::translate("cityWithTemp", "Form", nullptr));
        citylbl->setText(QCoreApplication::translate("cityWithTemp", "city", nullptr));
        piclbl->setText(QCoreApplication::translate("cityWithTemp", "Icon", nullptr));
        templbl->setText(QCoreApplication::translate("cityWithTemp", "temp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cityWithTemp: public Ui_cityWithTemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CITYWITHTEMP_H
