#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *bt1 = new QPushButton(this);
    bt1->move(100,100);
    bt1->setFixedSize(100,100);

    QPushButton *bt2 = new QPushButton(bt1);
    bt2->move(20,20);
    bt2->setFixedSize(50,50);

    QPushButton *bt3 = new QPushButton(bt2);
    bt3->move(100,100);
    bt3->setFixedSize(10,10);

    qDebug() << "fuck you lives";

    QString temp = "fuck you life";
    qDebug() << temp << temp.size();

    QByteArray temp1 = "去你妈的世界...";
    qDebug() << temp1 << temp1.length();
}

MainWindow::~MainWindow()
{
    delete ui;
}
