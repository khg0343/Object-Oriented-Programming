#ifndef WINDOW_41_H
#define WINDOW_41_H

#include <QDialog>
#include "MemberCollection.h"
#include "seat.h"

namespace Ui {
class window_41;
}

class window_41 : public QDialog
{
    Q_OBJECT

public:
    explicit window_41(MemberCollection*, SeatCollection*, QWidget *parent = nullptr);
    ~window_41();

private slots:
    void on_SelectButton_clicked();

private:
    Ui::window_41 *ui;
    MemberCollection* memcollect;
    SeatCollection* seatcollect;
};

#endif // WINDOW_41_H
