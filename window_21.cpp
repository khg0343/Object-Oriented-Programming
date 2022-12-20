#include "window_21.h"
#include "ui_window_21.h"
#include "error1.h"
#include "error2.h"

#include <iostream>

window_21::window_21(MemberCollection* mem, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window_21),
    memcollect(mem)
{
    ui->setupUi(this);
}

window_21::~window_21()
{
    delete ui;
}

void window_21::on_pushButton_clicked()
{
    QString reg = ui->regInput->text();
    QString id = ui->idInput->text();
    QString pw = ui->pwInput->text();
    if(id == ""||pw == ""||reg=="")		//ID,PW,REG 값 중 하나라도 입력하지 않았을 경우
    {
        error1 errorcase1("회원정보를 모두 입력해주세요!");
        errorcase1.setModal(true);
        errorcase1.exec();
    }
    else if (memcollect->CheckMember2(reg, id))		//입력된 RRN, ID 값 중 하나라도 중복 될 경우
    {
        error1 errorcase2("존재하는 학번 또는 ID입니다.");
        errorcase2.setModal(true);
        errorcase2.exec();
    }
    else
    {
        error2 success(id,pw,reg,memcollect);
        success.setModal(true);
        success.exec();
        this->close();
    }

    ui->regInput->clear();
    ui->idInput->clear();
    ui->pwInput->clear();
}
