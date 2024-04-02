#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:
    void on_infobt_clicked();

    void on_movebt_clicked();

    void on_identifybt_clicked();

    void on_modaldialog_clicked();

    void on_msgbox_clicked();

    void on_filebox_clicked();

    void on_processbt_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
