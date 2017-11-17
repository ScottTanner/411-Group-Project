#include "BoxStack2.h"
#include"ui_BoxStack2.h"
#include "OneSizedAlgorithm.h"

BoxStack2::BoxStack2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoxStack2)
{
    ui->setupUi(this);
}

BoxStack2::~BoxStack2()
{
    delete ui;
}

void BoxStack2::on_pushButton_Exit_clicked()
{
	close();
}

void BoxStack2::set_container(double cX, double cY, double cZ, double boxX, double boxY, double boxZ)
{
	this->containerX = cX;
	this->containerY = cY;
	this->containerZ = cZ;

	this->boxX = boxX;
	this->boxY = boxY;
	this->boxZ = boxZ;

	ui->lineEdit_SmallBoxWidth->setText(QString::number(this->boxX));
	ui->lineEdit_SmallBoxHeight->setText(QString::number(this->boxY));
	ui->lineEdit_SmallBoxLength->setText(QString::number(this->boxZ));

	ui->lineEdit_ContainerWidth->setText(QString::number(this->containerX));
	ui->lineEdit_ContainerHeight->setText(QString::number(this->containerY));
	ui->lineEdit_ContainerLength->setText(QString::number(this->containerZ));
}

void BoxStack2::on_pushButton_Config_clicked() {

	Dialog_OneSized oneSized;
	oneSized.setModal(true);
	close();
	oneSized.exec();
}