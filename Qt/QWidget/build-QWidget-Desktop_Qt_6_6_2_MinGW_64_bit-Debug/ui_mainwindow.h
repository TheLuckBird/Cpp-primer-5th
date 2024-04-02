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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *open_action;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *modaldialog;
    QVBoxLayout *verticalLayout;
    QPushButton *msgbox;
    QPushButton *filebox;
    QPushButton *processbt;
    QPushButton *movebt;
    QPushButton *infobt;
    QPushButton *identifybt;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(737, 538);
        open_action = new QAction(MainWindow);
        open_action->setObjectName("open_action");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        open_action->setIcon(icon);
        open_action->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        modaldialog = new QPushButton(centralwidget);
        modaldialog->setObjectName("modaldialog");

        horizontalLayout->addWidget(modaldialog);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        msgbox = new QPushButton(centralwidget);
        msgbox->setObjectName("msgbox");

        verticalLayout->addWidget(msgbox);

        filebox = new QPushButton(centralwidget);
        filebox->setObjectName("filebox");

        verticalLayout->addWidget(filebox);

        processbt = new QPushButton(centralwidget);
        processbt->setObjectName("processbt");

        verticalLayout->addWidget(processbt);


        horizontalLayout->addLayout(verticalLayout);

        movebt = new QPushButton(centralwidget);
        movebt->setObjectName("movebt");

        horizontalLayout->addWidget(movebt);

        infobt = new QPushButton(centralwidget);
        infobt->setObjectName("infobt");

        horizontalLayout->addWidget(infobt);

        identifybt = new QPushButton(centralwidget);
        identifybt->setObjectName("identifybt");

        horizontalLayout->addWidget(identifybt);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 737, 24));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setIconSize(QSize(50, 50));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName("dockWidget");
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::BottomDockWidgetArea, dockWidget);

        menubar->addAction(menu->menuAction());
        menu->addAction(open_action);
        menu->addSeparator();
        toolBar->addAction(open_action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        open_action->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        open_action->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        modaldialog->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\250\241\346\200\201\345\257\271\350\257\235\346\241\206", nullptr));
        msgbox->setText(QCoreApplication::translate("MainWindow", "msgbox", nullptr));
        filebox->setText(QCoreApplication::translate("MainWindow", "filebox", nullptr));
        processbt->setText(QCoreApplication::translate("MainWindow", "process", nullptr));
        movebt->setText(QCoreApplication::translate("MainWindow", "\347\247\273\345\212\250\347\252\227\345\217\243", nullptr));
        infobt->setText(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243\344\277\241\346\201\257", nullptr));
        identifybt->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\347\252\227\345\217\243", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        dockWidget->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\265\256\345\212\250\347\252\227\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
