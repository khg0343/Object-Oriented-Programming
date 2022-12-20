#include "error1.h"
#include "ui_error1.h"

error1::error1(QString str, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::error1)
{
    ui->setupUi(this);
    ui->label->setText(str);
}

error1::~error1()
{
    delete ui;
}

void error1::on_pushButton_clicked()
{
    this->close();
}
