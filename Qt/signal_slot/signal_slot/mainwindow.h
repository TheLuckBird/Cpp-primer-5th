#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "me.h"
#include "girlfriend.h"

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

    void hungryslot();
    void eatslot();

private:
    Ui::MainWindow *ui;
    Me *me;
    GirlFriend *m_girl;
};
#endif // MAINWINDOW_H
