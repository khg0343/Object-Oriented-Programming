#include "window_41.h"
#include "ui_window_41.h"

#include "window_22.h"

window_41::window_41(MemberCollection* mem, SeatCollection* seat, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window_41),
  memcollect(mem),
  seatcollect(seat)
{
    ui->setupUi(this);
    ui->CurrentID->setText(mem->GetLoginMember()->GetID());
    ui->CurrentSeat->setText(QString::number(mem->GetLoginMember()->GetSeatNum()+1));
    ui->CurrentTime->setText(QString::number(mem->GetLoginMember()->GetReserveTime()));
    int time = QTime::currentTime().hour();
    for(int i=time+1;i<=mem->GetLoginMember()->GetReserveTime();i++)
    {
       ui->TimeComboBox->addItem(QString::number(i));
    }
    if(mem->GetLoginMember()->GetReserveTime()<time)
    {
        for(int i=time+1;i<24;i++)
        {
           ui->TimeComboBox->addItem(QString::number(i));
        }
        for(int i=0;i<=mem->GetLoginMember()->GetReserveTime();i++)
        {
           ui->TimeComboBox->addItem(QString::number(i));
        }
    }
}

window_41::~window_41()
{
    delete ui;
}

void window_41::on_SelectButton_clicked()
{
    int seatnum = memcollect->GetLoginMember()->GetSeatNum();
    int start = QTime::currentTime().hour();
    int duration = ui->TimeComboBox->currentIndex()+1;
    seatcollect->GetSeat(seatnum)->Cancel(start, duration, memcollect->GetLoginMember());
    memcollect->GetLoginMember()->Raon2();
    this->close();
}
