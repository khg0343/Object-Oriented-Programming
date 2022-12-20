#include "window_31.h"
#include "ui_window_31.h"
#include "window_22.h"
#include <iostream>
#include <QString>
#include <QTime>
#include <QTableWidgetSelectionRange>

#define SEAT_NUM 46

window_31::window_31(MemberCollection* mem, SeatCollection* seat, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window_31),
    memcollect(mem),
    seatcollect(seat)
{
    ui->setupUi(this);
    for(int i=1;i<=SEAT_NUM;i++)
    {
        ui->SeatComboBox->addItem(QString::number(i));
    }

    ui->tableWidget->setVisible(false);
    ui->SelectText->setVisible(false);
    ui->ConfirmButton->setVisible(false);
}

window_31::~window_31()
{
    delete ui;
    window_22 w(memcollect, seatcollect);
    w.setModal(true);
    w.exec();
}

void window_31::on_SelectButton_clicked()
{
    ui->tableWidget->setVisible(true);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->SelectText->setVisible(true);
    ui->ConfirmButton->setVisible(true);

    int time = QTime::currentTime().hour();
    for(int i=0;i<24;i++)
    {
        ui->tableWidget->setItem(0,i,new QTableWidgetItem);
        ui->tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem());
        ui->tableWidget->horizontalHeaderItem(i)->setText(QString::number((time+i)%24));
    }

    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(30);

    int selection = ui->SeatComboBox->currentIndex();

    for(int i=0;i<24;i++)
    {
        ui->tableWidget->item(0,i)->setBackgroundColor(Qt::white);
    }

    for(int i=0;i<24;i++)
    {
        if(seatcollect->GetSeat(selection)->isReserved((time+i)%24))
        {
            ui->tableWidget->item(0,i)->setBackgroundColor(Qt::red);
        }
    }
}


void window_31::on_ConfirmButton_clicked()
{
    int selectseat = ui->SeatComboBox->currentIndex();
    int reservehour = 0;
    int startingtime = QTime::currentTime().hour();
    for(int i=0;i<24;i++)
    {
        if(ui->tableWidget->item(0,i)->isSelected())
        {
            if(reservehour == 0)
                startingtime = (startingtime + i)%24;
            reservehour++;
        }
    }

    for(int i=0;i<24;i++)
    {
        if(ui->tableWidget->item(0,i)->isSelected())
        {
            ui->tableWidget->item(0,i)->setSelected(false);
        }
    }

    if(reservehour>4)
    {
        ui->ResultText->setText(QString::fromStdString("4시간 초과"));
    }
    else if(seatcollect->GetSeat(selectseat)->Reserve(startingtime,reservehour,memcollect->GetLoginMember()))
    {
        ui->ResultText->setText(QString::fromStdString("예약되었습니다"));
        int time = (startingtime-QTime::currentTime().hour()+24)%24;
        for(int i=time;i<time+reservehour;i++)
        {
            ui->tableWidget->item(0,i)->setBackgroundColor(Qt::red);
        }
    }
    else
    {
        ui->ResultText->setText(QString::fromStdString("예약 실패"));
    }

}

void window_31::timeChanged(const QTime& current)
{
    int old = current.hour() - 1;

    Member* mem = seatcollect->GetSeat(old)->GetReserveMember(old);
    seatcollect->GetSeat(old)->Cancel(old, 1, mem);
}
