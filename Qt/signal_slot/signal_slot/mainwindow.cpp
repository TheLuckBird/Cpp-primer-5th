#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    me = new Me;
    m_girl = new GirlFriend;

    connect(m_girl,&GirlFriend::hungry,me,&Me::eat);
    connect(m_girl,&GirlFriend::hungry,this,&MainWindow::eatslot);
    // connect(ui->hungry,&QPushButton::clicked,m_girl,&GirlFriend::hungry);
    connect(ui->hungry,&QPushButton::clicked,this,
            [=](){emit m_girl->hungry();}
            );
    // connect(ui->hungry,&QPushButton::clicked,this,&MainWindow::hungryslot);

    connect(ui->closebt,&QPushButton::clicked,this,&MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hungryslot()
{
   emit m_girl->hungry();
}

void MainWindow::eatslot()
{
    qDebug() << "吃火锅";
}
