#ifndef BOXSTACK2_H
#define BOXSTACK2_H

#include <QDialog>

namespace Ui {
class BoxStack2;
}

class BoxStack2 : public QDialog
{
    Q_OBJECT

public:
    explicit BoxStack2(QWidget *parent = 0);
	void set_container(double cX, double cY, double cZ, double boxX, double boxY, double boxZ);
	~BoxStack2();

private slots:

void on_pushButton_Config_clicked();
void on_pushButton_Exit_clicked();

private:
    Ui::BoxStack2 *ui;
	double containerX;
	double containerY;
	double containerZ;
	double boxX;
	double boxY;
	double boxZ;
};

#endif // BOXSTACK2_H
