/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *loopbt;
    QLabel *currtime;
    QPushButton *oncebt;
    QLabel *oncetime;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        loopbt = new QPushButton(centralwidget);
        loopbt->setObjectName("loopbt");
        loopbt->setGeometry(QRect(170, 150, 92, 28));
        currtime = new QLabel(centralwidget);
        currtime->setObjectName("currtime");
        currtime->setGeometry(QRect(330, 140, 101, 51));
        oncebt = new QPushButton(centralwidget);
        oncebt->setObjectName("oncebt");
        oncebt->setGeometry(QRect(170, 280, 92, 28));
        oncetime = new QLabel(centralwidget);
        oncetime->setObjectName("oncetime");
        oncetime->setGeometry(QRect(330, 270, 101, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loopbt->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        currtime->setText(QCoreApplication::translate("MainWindow", "time", nullptr));
        oncebt->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        oncetime->setText(QCoreApplication::translate("MainWindow", "time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
