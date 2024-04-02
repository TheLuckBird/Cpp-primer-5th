#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::onReplied);

    QUrl url("http://t.weather.itboy.net/api/weather/city/101010100");
    manager->get(QNetworkRequest(url));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onReplied(QNetworkReply *reply)
{
    qDebug() << "operation:" << reply->operation();
    qDebug() << "status code:" <<reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "url:" << reply->url();
    qDebug() << "raw header:" << reply->rawHeaderList();

    if(reply->error() != QNetworkReply::NoError || reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() != 200)
    {
        qDebug() << "请求失败";
    }
    else
    {
        QByteArray data = QString(reply->readAll()).toUtf8();

        qDebug() << data.data();
    }

}
