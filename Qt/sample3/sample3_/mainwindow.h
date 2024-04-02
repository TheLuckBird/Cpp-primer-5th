#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <String.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QVariant dataplus(QVariant a,QVariant b);

private:
    Ui::MainWindow *ui;
};

struct Person
{
    int id;
    std::string name;
};
Q_DECLARE_METATYPE(Person)

#endif // MAINWINDOW_H
