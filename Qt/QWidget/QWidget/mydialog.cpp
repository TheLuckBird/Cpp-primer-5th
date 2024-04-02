#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_acceptbt_clicked()
{
    this->accept();
}


void MyDialog::on_rejectbt_clicked()
{
    this->reject();
}


void MyDialog::on_donebt_clicked()
{
    this->done(10);
}




