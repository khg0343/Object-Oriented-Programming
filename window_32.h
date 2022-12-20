#ifndef WINDOW_32_H
#define WINDOW_32_H

#include <QDialog>
#include <QTime>
#include "MemberCollection.h"
#include "seat.h"

namespace Ui {
class window_32;
}

class window_32 : public QDialog
{
    Q_OBJECT

public:
    explicit window_32(MemberCollection*, SeatCollection*, QWidget *parent = nullptr);
    ~window_32();

private slots:
    void on_ConfirmButton_clicked();

    void on_WarnButton_clicked();

    void on_SeatComboBox_currentIndexChanged(int index);

private:
    Ui::window_32 *ui;
    MemberCollection* memcollect;
    SeatCollection* seatcollect;
};

#endif // WINDOW_32_H
