#ifndef WINDOW_31_H
#define WINDOW_31_H

#include <QDialog>
#include <QTimeEdit>
#include "MemberCollection.h"
#include "seat.h"

namespace Ui {
class window_31;
}

class window_31 : public QDialog
{
    Q_OBJECT

public:
    explicit window_31(MemberCollection*, SeatCollection*, QWidget *parent = nullptr);
    ~window_31();

private slots:
    void on_SelectButton_clicked();

    void on_ConfirmButton_clicked();
    void timeChanged(const QTime&);

private:
    Ui::window_31 *ui;
    MemberCollection* memcollect;
    SeatCollection* seatcollect;
};

#endif // WINDOW_31_H
