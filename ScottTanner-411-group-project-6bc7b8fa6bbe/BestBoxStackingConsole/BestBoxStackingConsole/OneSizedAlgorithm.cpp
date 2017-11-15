#include"save.h"
#include <iostream>
#include <fstream>
#include<string>
#include "OneSizedAlgorithm.h"
#include "ui_OneSizedSmallBoxes.h"

Dialog_OneSized::Dialog_OneSized(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog_OneSized)
{
	ui->setupUi(this);

}
Dialog_OneSized::~Dialog_OneSized()
{
	delete ui;

}

void Dialog_OneSized::on_pushButton_2_clicked()
{
	close();
}

void Dialog_OneSized::on_pushButton_ContainerDelete_clicked()
{

	ui->lineEdit_ContainerWidth->setText("");
	ui->lineEdit_ContainerHeight->setText("");
	ui->lineEdit_ContainerLength->setText("");
}

void Dialog_OneSized::on_pushButton_SmallBoxDelete_clicked()
{
	ui->lineEdit_SmallBoxWidth->setText("");
	ui->lineEdit_SmallBoxHeight->setText("");
	ui->lineEdit_SmallBoxLength->setText("");
}


void Dialog_OneSized::on_OneSized_Clicked()
{
}

