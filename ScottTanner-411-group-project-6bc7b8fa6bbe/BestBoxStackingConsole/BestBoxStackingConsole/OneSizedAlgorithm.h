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
	void set_container(double cX, double cY, double cZ, double boxX, double boxY, double boxZ);
	~Dialog_OneSized();
	double  GetContainerX();
	double  GetContainerY();
	double  GetContainerZ();
	double  GetSmallBoxX();
	double  GetSmallBoxY();
	double  GetSmallBoxZ();
	void setTextBoxesEdit();
	bool getCalculated();
private slots:
	void on_pushButton_2_clicked();
	void on_pushButton_ContainerDelete_Clicked();
	void on_pushButton_SmallBoxDelete_Clicked();
	void on_pushButton_Done_clicked();
	void on_pushButton_Done2_clicked();
	void on_pushButton_Back_clicked();
	void on_pushButton_Calulate_clicked();
	void on_pushButton_Save_Container_Clicked();
	void on_pushButton_Save_SmallBox_Clicked();
	void on_pushButton_ClearContainer_Clicked();
	void on_pushButton_ClearSmallBox_Clicked();


	void update_SMvalues();
	void update_CNvalues();

private:
	Ui::Dialog_OneSized *ui;
	double containerX;
	double containerY;
	double containerZ;
	std::list<std::pair<std::string, std::list<double>>> listItems;
	bool calculated;
	double boxX;
	double boxY;
	double boxZ;
	void fill_ComboSMBox();
	void fill_ComboCNBox();
};


#endif // !ONESIZEDALGORITHM_H