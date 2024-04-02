#include "widget.h"
#include "ui_widget.h"
#include "testwidget.h"
#include "testdialog.h"
#include "testmainwindow.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

#if 0
    TestWidget *tw = new TestWidget;
    tw->show();
#else
    TestWidget *tw = new TestWidget(this);
#endif

#if 0
    TestDialog *td = new TestDialog(this);
    td->show();
#else
    TestDialog *td = new TestDialog(this);
    td->exec();
#endif

    TestMainWindow *tmw = new TestMainWindow(this);
    tmw->show();

}
Widget::~Widget()
{
    delete ui;
}
