#include "error2.h"
#include "ui_error2.h"
#include "window_21.h"

error2::error2(QString id, QString pw, QString reg, MemberCollection* mem, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::error2),
    memcollect(mem),
    id(id),
    pw(pw),
    reg(reg)
{
    ui->setupUi(this);
    ui->CurrentID->setText(id);
    ui->CurrentPW->setText(pw);
    ui->CurrentReg->setText(reg);
}

error2::~error2()
{
    delete ui;
}

void error2::on_okay_clicked()
{
    memcollect->GetMember(id, pw, reg);
    this->setResult(true);
    this->close();
}

void error2::on_cancel_clicked()
{
    this->setResult(false);
    this->close();
    window_21 w(memcollect);
    w.setModal(true);
    w.exec();
}
