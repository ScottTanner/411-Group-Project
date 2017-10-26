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
	void set_container(double cX, double cY, double cZ, double boxX, double boxY, double boxZ);
    ~TwoDimenNext();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_exit_clicked();
	
	void update_values();

private:
    Ui::TwoDimenNext *ui;
	double containerX;
	double containerY;
	double containerZ;
	std::list<std::pair<std::string, std::list<double>>> listItems;
	double boxX;
	double boxY;
	double boxZ;
	void fill_ComboBox();
};

#endif // TWODIMENNEXT_H
