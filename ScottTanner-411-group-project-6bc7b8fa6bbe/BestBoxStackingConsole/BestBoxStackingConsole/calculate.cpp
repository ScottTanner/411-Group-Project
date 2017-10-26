#include "calculate.h"
#include "ui_calculate.h"
#include "StackCollection.h"
#include "showResult.h"

Calculate::Calculate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calculate)
{
    ui->setupUi(this);



}

void Calculate::set_Container(double cX, double cY, double cZ, double boxX, double boxY, double boxZ)
{
	this->containerX = cX;
	this->containerY = cY;
	this->containerZ = cZ;
	this->boxX = boxX;
	this->boxY = boxY;
	this->boxZ = boxZ;
	ui->boxX->setText(QString::number(this->boxX));
	ui->boxY->setText(QString::number(this->boxY));
	ui->boxZ->setText(QString::number(this->boxZ));
	ui->containerX->setText(QString::number(this->containerX));
	ui->containerY->setText(QString::number(this->containerY));
	ui->containerZ->setText(QString::number(this->containerZ));
}

Calculate::~Calculate()
{

    delete ui;
}

void Calculate::on_pushButton_2_clicked()
{
	ShowResult gui4;
	gui4.set_StackCollection(StackCollection (this->containerX, this->containerY, this->containerZ, this->boxX, this->boxY, this->boxZ));
	gui4.setModal(true);
	gui4.exec();
}

void Calculate::on_pushButton_clicked()
{
	close();
}
