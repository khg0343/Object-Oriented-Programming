#ifndef ERROR1_H
#define ERROR1_H

#include <QDialog>

namespace Ui {
class error1;
}

class error1 : public QDialog
{
    Q_OBJECT

public:
    explicit error1(QString, QWidget *parent = nullptr);
    ~error1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::error1 *ui;
};

#endif // ERROR1_H
