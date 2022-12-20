#ifndef WINDOW_22_H
#define WINDOW_22_H

#include <QDialog>
#include <string>
#include "MemberCollection.h"
#include "seat.h"

namespace Ui {
class window_22;
}

class window_22 : public QDialog
{
    Q_OBJECT

public:
    explicit window_22(MemberCollection*, SeatCollection*, QWidget *parent = nullptr);
    ~window_22();

private slots:
    void on_ReserveButton_clicked();

    void on_WarningButton_clicked();

    void on_outButton_clicked();

    void on_LogoutButton_clicked();


private:
    Ui::window_22 *ui;
    MemberCollection* memcollect;
    SeatCollection* seatcollect;
};

#endif // window_22_H
