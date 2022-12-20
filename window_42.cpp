#include "window_42.h"
#include "ui_window_42.h"

#include "window_22.h"

window_42::window_42(MemberCollection* mem,  SeatCollection* seat, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window_42),
  memcollect(mem),
  seatcollect(seat)
{
    ui->setupUi(this);
    ui->CurrentID->setText(mem->GetLoginMember()->GetID());
    ui->CurrentSeat->setText(QString::number(mem->GetLoginMember()->GetSeatNum()+1));
    ui->CurrentTime->setText(QString::number(mem->GetLoginMember()->GetReserveTime()));
    ui->CurrentTime_2->setText(QString::number((QTime::currentTime().hour()+1)%24));
}

window_42::~window_42()
{
    delete ui;
}

void window_42::on_SelectButton_clicked()
{
    memcollect->GetLoginMember()->Raon1(0);
    this->close();
}
