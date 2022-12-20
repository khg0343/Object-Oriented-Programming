#include "window_32.h"
#include "ui_window_32.h"
#include "window_22.h"
#include "error1.h"

window_32::window_32(MemberCollection* mem, SeatCollection* seat, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window_32),
    memcollect(mem),
    seatcollect(seat)
{
    ui->setupUi(this);
    for(int i=1;i<=MAX_SEATS;i++)
    {
       ui->SeatComboBox->addItem(QString::number(i));
    }
    ui->WarnButton->setVisible(false);
}

window_32::~window_32()
{
    delete ui;
    window_22 w(memcollect, seatcollect);
    w.setModal(true);
    w.exec();
}

void window_32::on_ConfirmButton_clicked()
{
    ui->WarnButton->setVisible(true);
}

void window_32::on_SeatComboBox_currentIndexChanged(int index)
{
    ui->WarnButton->setVisible(false);
}

void window_32::on_WarnButton_clicked()
{
    int seatnum = ui->SeatComboBox->currentIndex();
    int time = QTime::currentTime().hour();
    error1 warn(QString::number(seatnum+1)+"번 자리의 사용자를 신고합니다.");
    warn.setModal(true);
    warn.exec();

    int mode = seatcollect->GetSeat(seatnum)->Warn(time, memcollect->GetLoginMember());

    if (mode == 1)
    {
        error1 errorcase1("본인 좌석입니다.");
        errorcase1.setModal(true);
        errorcase1.exec();
    }
    else if (mode == 2)
    {
        error1 errorcase2("현재 예약된 좌석이 아닙니다.");
        errorcase2.setModal(true);
        errorcase2.exec();
    }
    else if (mode == 3)
    {
        error1 errorcase3("곧 돌아올 좌석입니다.");
        errorcase3.setModal(true);
        errorcase3.exec();
    }
    else
    {
        error1 success(QString::number(seatnum+1)+"번 자리의 사용자를 신고하였습니다.");
        success.setModal(true);
        success.exec();
    }
}

