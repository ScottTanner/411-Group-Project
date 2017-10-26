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
	void set_Container(double cX, double cY, double cZ, double boxX, double boxY, double boxZ);
    ~Calculate();

private slots:
    void on_pushButton_clicked();
	void on_pushButton_2_clicked();
private:
	Ui::Calculate *ui;
	double containerX;
	double containerY;
	double containerZ;
	double boxX;
	double boxY;
	double boxZ;
};

#endif // CALCULATE_H
