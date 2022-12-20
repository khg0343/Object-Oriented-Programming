#ifndef WINDOW_42_H
#define WINDOW_42_H

#include <QDialog>
#include "MemberCollection.h"
#include "seat.h"

namespace Ui {
class window_42;
}

class window_42 : public QDialog
{
    Q_OBJECT

public:
    explicit window_42(MemberCollection*, SeatCollection*, QWidget *parent = nullptr);
    ~window_42();

private slots:
    void on_SelectButton_clicked();

private:
    Ui::window_42 *ui;
    MemberCollection* memcollect;
    SeatCollection* seatcollect;
};

#endif // WINDOW_42_H
