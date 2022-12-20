#include "mainwindow.h"
#include "window_21.h"
#include "window_22.h"
#include "ui_mainwindow.h"
#include "error1.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    memcollect = new MemberCollection;
    seatcollect = new SeatCollection;

    /*add test member*/
    memcollect->GetMember("id1","pw","20180001");
    memcollect->GetMember("id2","pw","20180002");
    memcollect->GetMember("id3","pw","20180003");
    /*test members*/

    oldtime = QTime::currentTime().hour();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete memcollect;
    delete seatcollect;
}

void MainWindow::on_pushButton_clicked() //join button
{
    window_21 w(memcollect);
    w.setModal(true);
    w.exec();
}

void MainWindow::on_pushButton_2_clicked() //login button
{
    int inx = -1;

    int curtime = QTime::currentTime().hour();

       //std::cout<<oldtime<<" "<<curtime<<std::endl;
       if(oldtime!=curtime)
       {
           for (int i = 0; i<MAX_SEATS; i++)
           {
               if(seatcollect->GetSeat(i)->isReserved(oldtime))
               {
                   memcollect->refresh(oldtime);
                   seatcollect->refresh(oldtime);
               }
           }

           oldtime = curtime;
       }

    QString id = ui->idEdit->text();
    QString pw = ui->pwEdit->text();
    inx = memcollect->CheckMember(id, pw);
    if (inx<0)
    {
        error1 w("잘못된 로그인 정보입니다!");
        w.setModal(true);
        w.exec();
    }
    else
    {
        memcollect->GetLogin(inx);
        window_22 w(memcollect, seatcollect);
        w.setModal(true);
        w.exec();
    }

    ui->idEdit->clear();
    ui->pwEdit->clear();
}
