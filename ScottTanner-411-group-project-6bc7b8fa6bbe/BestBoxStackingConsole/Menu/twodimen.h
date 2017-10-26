#ifndef TWODIMEN_H
#define TWODIMEN_H

#include <QDialog>

namespace Ui {
class TwoDimen;
}

class TwoDimen : public QDialog
{
    Q_OBJECT

public:
    explicit TwoDimen(QWidget *parent = 0);
    ~TwoDimen();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::TwoDimen *ui;
};

#endif // TWODIMEN_H
