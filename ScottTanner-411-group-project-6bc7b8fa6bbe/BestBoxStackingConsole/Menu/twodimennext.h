#ifndef TWODIMENNEXT_H
#define TWODIMENNEXT_H

#include <QDialog>

namespace Ui {
class TwoDimenNext;
}

class TwoDimenNext : public QDialog
{
    Q_OBJECT

public:
    explicit TwoDimenNext(QWidget *parent = 0);
    ~TwoDimenNext();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::TwoDimenNext *ui;
};

#endif // TWODIMENNEXT_H
