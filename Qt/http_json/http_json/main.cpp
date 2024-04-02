#include "mainwindow.h"

#include <QApplication>
#include <QNetworkAccessManager>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QNetworkAccessManager *mNetworkManager;
    w.show();
    return a.exec();
}
