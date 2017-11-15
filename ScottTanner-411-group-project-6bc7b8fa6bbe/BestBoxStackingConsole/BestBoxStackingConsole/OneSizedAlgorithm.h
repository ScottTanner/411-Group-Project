#ifndef ONESIZEDALGORITHM_H
#define	ONESIZEDALGORITHM_H


#include <QDialog>

namespace Ui {
	class Dialog_OneSized;
}

class Dialog_OneSized : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog_OneSized(QWidget *parent = 0);
	~Dialog_OneSized();

private slots:
	void on_OneSized_Clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_ContainerDelete_clicked();
	void on_pushButton_SmallBoxDelete_clicked();

private:
	Ui::Dialog_OneSized *ui;
	double containerX;
	double containerY;
	double containerZ;
	std::list<std::pair<std::string, std::list<double>>> listItems;
	double boxX;
	double boxY;
	double boxZ;
	void fill_ComboBox();
};


#endif // !ONESIZEDALGORITHM_H