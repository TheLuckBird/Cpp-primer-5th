#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int sum = dataplus(1,1).toInt();
    qDebug() << sum;
    QString s = dataplus("fuck ","you lives").toString();
    qDebug() << s;

    Person p;
    p.id = 250;
    p.name = "fuck you lives";

#if 1
    QVariant qv;
    qv.setValue(p);
#else
    QVariant qv = QVariant::fromValue(p);
#endif

    if(qv.canConvert<Person>())
    {
        Person tmp = qv.value<Person>();
        qDebug() << tmp.id << tmp.name;
    }
}

QVariant MainWindow::dataplus(QVariant a,QVariant b)
{
    QVariant tmp;
    if(a.type() == QVariant::Int && b.type() == QVariant::Int)
        tmp = QVariant(a.toInt() + b.toInt());
    else if(a.type() == QVariant::String && b.type() == QVariant::String)
        tmp.setValue(a.toString() + b.toString());

    return tmp;
}

MainWindow::~MainWindow()
{
    delete ui;
}
