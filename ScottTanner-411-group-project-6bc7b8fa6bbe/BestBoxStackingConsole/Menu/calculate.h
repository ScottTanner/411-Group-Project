#ifndef CALCULATE_H
#define CALCULATE_H

#include <QDialog>

namespace Ui {
class Calculate;
}

class Calculate : public QDialog
{
    Q_OBJECT

public:
    explicit Calculate(QWidget *parent = 0);
    ~Calculate();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Calculate *ui;
};

#endif // CALCULATE_H
