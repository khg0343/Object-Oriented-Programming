#ifndef WINDOW_21_H
#define WINDOW_21_H

#include <QDialog>
#include "MemberCollection.h"
#include "seat.h"

namespace Ui {
class window_21;
}

class window_21 : public QDialog
{
    Q_OBJECT

public:
    explicit window_21(MemberCollection*, QWidget *parent = nullptr);
    ~window_21();

private slots:
    void on_pushButton_clicked();

private:
    Ui::window_21 *ui;
    MemberCollection* memcollect;
};

#endif // WINDOW21_H
