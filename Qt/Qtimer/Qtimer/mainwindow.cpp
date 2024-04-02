#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    timer->setTimerType(Qt::PreciseTimer);

    connect(ui->loopbt,&QPushButton::clicked,this,[=]()
    {
        if(timer->isActive())
        {
            timer->stop();
            ui->loopbt->setText("开始");
        }
        else
        {
            ui->loopbt->setText("关闭");
            timer->start();
        }

    });

    connect(timer,&QTimer::timeout,this,[=]()
    {
        QTime tm = QTime::currentTime();

        QString tmstr = tm.toString("hh:mm:ss.zzz");

        ui->currtime->setText(tmstr);
    });

    connect(ui->oncebt,&QPushButton::clicked,this,[=]()
    {
        QTimer::singleShot(2000,this,[=]()
        {
            QTime tm = QTime::currentTime();

            QString tmstr = tm.toString("hh:mm:ss.zzz");

            ui->oncetime->setText(tmstr);
        });
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
