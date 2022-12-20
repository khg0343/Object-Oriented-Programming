#include "window_33.h"
#include "ui_window_33.h"
#include "window_41.h"
#include "window_42.h"
#include "window_22.h"

window_33::window_33(MemberCollection* mem,  SeatCollection* seat, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window_33),
  memcollect(mem),
  seatcollect(seat)
{
    ui->setupUi(this);
}

window_33::~window_33()
{
    delete ui;
    window_22 w(memcollect, seatcollect);
    w.setModal(true);
    w.exec();
}

void window_33::on_pushButton_clicked()
{
    this->close();
    window_42 w(memcollect, seatcollect);
    w.setModal(true);
    w.exec();
}

void window_33::on_pushButton_2_clicked()
{
    this->close();
    window_41 w(memcollect, seatcollect);
    w.setModal(true);
    w.exec();
}
