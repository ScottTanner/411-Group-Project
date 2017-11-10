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

void Dialog_OneSized::on_OneSized_Clicked()
{
}

Dialog_OneSized::~Dialog_OneSized()
{
}
