/********************************************************************************
** Form generated from reading UI file 'worldlistwea.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORLDLISTWEA_H
#define UI_WORLDLISTWEA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorldListWea
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_2;
    QListWidget *listWidget;
    QListWidget *stateWidget;
    QPushButton *listBtn;
    QPushButton *backBtn;
    QMenuBar *menubar;

    void setupUi(QMainWindow *WorldListWea)
    {
        if (WorldListWea->objectName().isEmpty())
            WorldListWea->setObjectName("WorldListWea");
        WorldListWea->resize(790, 440);
        centralwidget = new QWidget(WorldListWea);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-10, 0, 800, 445));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"	border-image: url(:/res/bg.jpg);\n"
"}"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(150, 0, 141, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:transparent;"));

        verticalLayout_2->addWidget(pushButton_2);

        listWidget = new QListWidget(widget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(13, 25, 783, 391));
        listWidget->setStyleSheet(QString::fromUtf8("\n"
"QListView \n"
"{\n"
"      show-decoration-selected: 1; \n"
"}\n"
"\n"
" \n"
"QListView::item:selected \n"
"{\n"
"      border: 1px solid #6a6ea9;\n"
"}\n"
" \n"
"QListView::item:selected:!active \n"
"{\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #ABAFE5, stop: 1 #8588B2);\n"
"}\n"
" \n"
"QListView::item:selected:active\n"
"{\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #6a6ea9, stop: 1 #888dd9);\n"
"	  border-left: 3px solid black;\n"
"}\n"
" \n"
"QListView::item:hover\n"
"{\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #FAFBFE, stop: 1 #DCDEF1);\n"
"	  border-left: 3px solid rgb(130, 130, 130);\n"
"}\n"
""));
        stateWidget = new QListWidget(widget);
        stateWidget->setObjectName("stateWidget");
        stateWidget->setGeometry(QRect(13, 25, 783, 390));
        stateWidget->setStyleSheet(QString::fromUtf8("QListView::item {\n"
"    height: 70px;\n"
"}\n"
"QListView {\n"
"   border: 10px solid white; \n"
"	border-radius: 10px;\n"
"}\n"
" \n"
"QListView::item:selected \n"
"{\n"
"   	  margin-left: 5px;\n"
"	  border-left: 3px solid black;\n"
"}\n"
" \n"
"QListView::item:selected:!active \n"
"{\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #ABAFE5, stop: 1 #8588B2);\n"
"}\n"
" \n"
"QListView::item:selected:active\n"
"{\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #6a6ea9, stop: 1 #888dd9);\n"
"}\n"
" \n"
"QListView::item:hover\n"
"{\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #FAFBFE, stop: 1 #DCDEF1);\n"
"   	  margin-left: 5px;\n"
"	  border-left: 3px solid black;\n"
"}\n"
""));
        listBtn = new QPushButton(widget);
        listBtn->setObjectName("listBtn");
        listBtn->setGeometry(QRect(49, 5, 28, 24));
        listBtn->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0,1);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/list.png"), QSize(), QIcon::Normal, QIcon::Off);
        listBtn->setIcon(icon);
        backBtn = new QPushButton(widget);
        backBtn->setObjectName("backBtn");
        backBtn->setGeometry(QRect(15, 5, 28, 24));
        backBtn->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0,1);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        backBtn->setIcon(icon1);
        WorldListWea->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WorldListWea);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 790, 28));
        WorldListWea->setMenuBar(menubar);

        retranslateUi(WorldListWea);

        QMetaObject::connectSlotsByName(WorldListWea);
    } // setupUi

    void retranslateUi(QMainWindow *WorldListWea)
    {
        WorldListWea->setWindowTitle(QCoreApplication::translate("WorldListWea", "MainWindow", nullptr));
        pushButton_2->setText(QString());
        listBtn->setText(QString());
        backBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WorldListWea: public Ui_WorldListWea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORLDLISTWEA_H
