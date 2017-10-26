//#include"save.h"
//#include "twodimennext.h"
#include "twodimen.h"
#include "ui_twodimen.h"

TwoDimen::TwoDimen(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TwoDimen)
{
	ui->setupUi(this);
}

TwoDimen::~TwoDimen()
{
	delete ui;
}

void TwoDimen::on_pushButton_3_clicked()
{
	/*TwoDimenNext gui2;
	gui2.setModal(true);
	gui2.exec();*/
}

void TwoDimen::on_pushButton_clicked()
{
	/*Save gui3;
	gui3.setModal(true);
	gui3.exec();*/
}