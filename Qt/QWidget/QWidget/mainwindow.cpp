#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "mydialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QProgressDialog>
#include <QTimer>
#include <QLineEdit>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setMaximumSize(600,600);

    setMinimumSize(300,300);

    setWindowTitle("fucking life");

    setWindowIcon(QIcon(":/pic.jpg"));

    connect(this,&MainWindow::windowTitleChanged,this,[=](const QString &title){qDebug() << title;});

    setContextMenuPolicy(Qt::CustomContextMenu);

    connect(this,&MainWindow::customContextMenuRequested,this,[=](const QPoint &pos)
    {
        QMenu menu;
        menu.addAction("属性");
        menu.exec(QCursor::pos());
    });

    connect(ui->open_action,&QAction::triggered,this,[=]()
    {
        QMessageBox::information(this,"clicked","fuck");
    });

    ui->toolBar->addWidget(new QPushButton("搜索"));
    QLineEdit *edit = new QLineEdit;
    edit->setMaximumWidth(150);
    ui->toolBar->addWidget(edit);

    ui->statusbar->showMessage("我是状态栏",3000);
    QPushButton *bt = new QPushButton("按钮");
    ui->statusbar->addWidget(bt);
    QLabel *lb = new QLabel("fuck world");
    ui->statusbar->addWidget(lb);

    QTimer::singleShot(5000,this,[=]()
    {
        bt->show();
        lb->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_infobt_clicked()
{
    QRect rect = this->frameGeometry();
    qDebug() << rect.topLeft()
             << rect.topRight()
             << rect.bottomLeft()
             << rect.bottomRight()
             << rect.height()
             << rect.width();

}


void MainWindow::on_movebt_clicked()
{
    QRect rect = this->frameGeometry();
    move(rect.topLeft() + QPoint(10,20));
}


void MainWindow::on_identifybt_clicked()
{
    setWindowTitle("你好Qt");
}


void MainWindow::on_modaldialog_clicked()
{
    MyDialog md;
    connect(&md,&MyDialog::finished,this,[=](int res){qDebug() << res;});

    int ret = md.exec();
    if(ret == QDialog::Accepted)
    {
        qDebug() << "accept button clicked";
    }
    else if(ret == QDialog::Rejected)
    {
        qDebug() << "reject button clicked";
    }
    else
    {
        qDebug() << "done button clicked";
    }
}


void MainWindow::on_msgbox_clicked()
{
    QMessageBox::about(this,"about","这是一个简单的消息提示框!");
    QMessageBox::critical(this,"critial","这是一个错误的对话框");
    int ret = QMessageBox::question(this,"question","这是一个问题对话框：",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel);
    if(ret == QMessageBox::Save)
    {
        QMessageBox::information(this,"information","恭喜你保存成功了, o(*￣︶￣*)o!!!");
    }
    else if(ret == QMessageBox::Cancel)
    {
        QMessageBox::warning(this,"warning","你放弃了保存, ┭┮﹏┭┮ !!!");
    }

}


void MainWindow::on_filebox_clicked()
{
    QString dirname = QFileDialog::getExistingDirectory(this,"打开目录","d:\\");
    QMessageBox::information(this,"打开目录：",dirname);

    // QString filepath = QFileDialog::getOpenFileName(this,"文件路径","d:\\2024秋招","MD(*.md)");
    // QMessageBox::information(this,"打开文件：",filepath);

    // QStringList filepaths = QFileDialog::getOpenFileNames(this,"文件路径s","D:\\小论文\\文献\\malconv","PDF(*.pdf)");
    // QString name;
    // for(int i = 0;i<filepaths.size();++i)
    // {
    //     name += filepaths.at(i) + "\n";
    // }
    // QMessageBox::information(this,"打开文件s",name);

    // QString filename = QFileDialog::getSaveFileName(this,"保存文件","D:\\小论文\\文献\\malconv","PDF(*.pdf)");
    // QMessageBox::information(this,"文件保存路径:",filename);


}


void MainWindow::on_processbt_clicked()
{
    QProgressDialog *progress = new QProgressDialog("正在拷贝数据","取消拷贝",1,100,this);

    progress->setWindowTitle("请稍后");

    progress->setWindowModality(Qt::WindowModal);

    progress->show();

    static int value = 0;

    QTimer *timer = new QTimer;

    connect(timer,&QTimer::timeout,this,[=]()
    {
        progress->setValue(value);
        value++;

        if(value > progress->maximum())
        {
            timer->stop();
            value = 0;
            delete progress;
            delete timer;
        }
    });

    connect(progress, &QProgressDialog::canceled, this, [=]()
    {
        timer->stop();
        value = 0;
        delete progress;
        delete timer;
    });

    timer->start(50);
}

