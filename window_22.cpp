#include "window_22.h"
#include "ui_window_22.h"

#include "window_31.h"
#include "window_32.h"
#include "window_33.h"
#include "error1.h"

window_22::window_22(MemberCollection* mem, SeatCollection* seat, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window_22),
    memcollect(mem),
    seatcollect(seat)
{
    ui->setupUi(this);
    //'지금의 나는?' 항목 설정
    if (memcollect->GetLoginMember()->GetSeatNum() >= 0)
    {
        QString str = QString::number(memcollect->GetLoginMember()->GetSeatNum()+1);
        str += "번 자리!";
        ui->CurrentStatus->setText(str);
    }
    else {
        ui->CurrentStatus->setText("사용하지않음!");
    }

    //경고횟수 설정
    QString str = QString::number(memcollect->GetLoginMember()->GetWarncount());
    str += "회";
    ui->CurrentWarn->setText(str);

    //student id 설정
    ui->CurrentReg->setText(memcollect->GetLoginMember()->GetStudentID());

    //id설정
    ui->CurrentID->setText(memcollect->GetLoginMember()->GetID());

}

window_22::~window_22()
{
    delete ui;
}

void window_22::on_ReserveButton_clicked() //열람실 예약하기
{
    this->close();
    window_31 w(memcollect, seatcollect);
    w.setModal(true);
    w.exec();

}

void window_22::on_WarningButton_clicked() //자리독점 신고하기
{
    this->close();
    window_32 w(memcollect, seatcollect);
    w.setModal(true);
    w.exec();
}

void window_22::on_outButton_clicked() //외출하기
{
    if(memcollect->GetLoginMember()->GetSeatNum() < 0)
    {
        error1 warn("현재 좌석을 사용하고 있지 않습니다.");
        warn.setModal(true);
        warn.exec();
    }
    else {
        this->close();
        window_33 w(memcollect, seatcollect);
        w.setModal(true);
        w.exec();
    }

}

void window_22::on_LogoutButton_clicked() //로그아웃
{
    memcollect->getLogout();
    this->close();
}


