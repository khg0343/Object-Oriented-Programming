#ifndef WINDOW_33_H
#define WINDOW_33_H

#include <QDialog>
#include "MemberCollection.h"
#include "seat.h"

namespace Ui {
class window_33;
}

class window_33 : public QDialog
{
    Q_OBJECT

public:
    explicit window_33(MemberCollection* mem, SeatCollection* seat, QWidget *parent = nullptr);
    ~window_33();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::window_33 *ui;
    MemberCollection* memcollect;
    SeatCollection* seatcollect;
};

#endif // WINDOW_33_H
