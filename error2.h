#ifndef ERROR2_H
#define ERROR2_H

#include <QDialog>
#include "MemberCollection.h"

namespace Ui {
class error2;
}

class error2 : public QDialog
{
    Q_OBJECT

public:
    explicit error2(QString id,QString pw, QString reg, MemberCollection*, QWidget *parent = nullptr);
    ~error2();

private slots:
    void on_okay_clicked();

    void on_cancel_clicked();

private:
    Ui::error2 *ui;
    MemberCollection* memcollect;
    QString id, pw, reg;
};

#endif // ERROR2_H
