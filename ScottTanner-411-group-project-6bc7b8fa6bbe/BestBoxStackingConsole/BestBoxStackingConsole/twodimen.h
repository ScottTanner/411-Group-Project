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
    void on_pushButton_Next_clicked();

    void on_pushButton_Save_clicked();

    void on_pushButton_Clear_clicked();

    void on_pushButton_Exit_clicked();

	void update_values();

private:
    Ui::TwoDimen *ui;
	double containerX;
	double containerY;
	double containerZ;
	std::list<std::pair<std::string, std::list<double>>> listItems;
	void fill_ComboBox();
};

#endif // TWODIMEN_H
