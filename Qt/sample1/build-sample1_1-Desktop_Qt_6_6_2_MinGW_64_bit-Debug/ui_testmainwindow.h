/********************************************************************************
** Form generated from reading UI file 'testmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMAINWINDOW_H
#define UI_TESTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestMainWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TestMainWindow)
    {
        if (TestMainWindow->objectName().isEmpty())
            TestMainWindow->setObjectName("TestMainWindow");
        TestMainWindow->resize(800, 600);
        centralwidget = new QWidget(TestMainWindow);
        centralwidget->setObjectName("centralwidget");
        TestMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        TestMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TestMainWindow);
        statusbar->setObjectName("statusbar");
        TestMainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(TestMainWindow);
        toolBar->setObjectName("toolBar");
        TestMainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(TestMainWindow);

        QMetaObject::connectSlotsByName(TestMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TestMainWindow)
    {
        TestMainWindow->setWindowTitle(QCoreApplication::translate("TestMainWindow", "MainWindow", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("TestMainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestMainWindow: public Ui_TestMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMAINWINDOW_H
