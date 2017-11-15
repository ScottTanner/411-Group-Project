#include"save.h"
#include <iostream>
#include <fstream>
#include<string>

#include "mainwindow.h"
#include "OneSizedAlgorithm.h"
#include "ui_OneSizedSmallBoxes.h"
int Go =0;

Dialog_OneSized::Dialog_OneSized(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog_OneSized)
{
	ui->setupUi(this);
	
	
		fill_ComboCNBox();
	
		
	

	connect(ui->comboBox_SmallBoxes, SIGNAL(currentIndexChanged(QString)), this, SLOT(update_SMvalues()));
	connect(ui->comboBox_Containers, SIGNAL(currentIndexChanged(QString)), this, SLOT(update_CNvalues()));
}
void Dialog_OneSized::set_container(double cX, double cY, double cZ, double boxX, double boxY, double boxZ)
{
	this->containerX = cX;
	this->containerY = cY;
	this->containerZ = cZ;
	
	this->boxX = boxX;
	this->boxY = boxY;
	this->boxZ = boxZ;
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

void Dialog_OneSized::on_pushButton_clicked()
{

}

void Dialog_OneSized::on_pushButton_Done_clicked()
{
	ui->lineEdit_SmallBoxLength->setEnabled(1);
	ui->lineEdit_SmallBoxHeight->setEnabled(1);
	ui->lineEdit_SmallBoxWidth->setEnabled(1);
	ui->comboBox_SmallBoxes->setEnabled(1);
	ui->label_8->setEnabled(1);
	
	ui->pushButton_Done2->setEnabled(1); 
	ui->pushButton_SmallBoxSave->setEnabled(1);
	ui->pushButton_SmallBoxDelete->setEnabled(1);
	ui->pushButton_Back->setEnabled(1);
	ui->label_4->setEnabled(1);
	ui->label_5->setEnabled(1);
	ui->label_6->setEnabled(1);
	
	ui->groupBox_Container->setDisabled(1);
	
	fill_ComboSMBox();

}

void Dialog_OneSized::on_pushButton_Done2_clicked()
{
	ui->pushButton_Calulate->setEnabled(1);
}

void Dialog_OneSized::on_pushButton_Back_clicked()
{
	ui->lineEdit_SmallBoxLength->setDisabled(1);
	ui->lineEdit_SmallBoxHeight->setDisabled(1);
	ui->lineEdit_SmallBoxWidth->setDisabled(1);
	ui->comboBox_SmallBoxes->setDisabled(1);
	ui->label_8->setDisabled(1);

	ui->pushButton_Done2->setDisabled(1);
	ui->pushButton_SmallBoxSave->setDisabled(1);
	ui->pushButton_SmallBoxDelete->setDisabled(1);
	ui->pushButton_Back->setDisabled(1);
	ui->label_4->setDisabled(1);
	ui->label_5->setDisabled(1);
	ui->label_6->setDisabled(1);

	ui->pushButton_Calulate->setEnabled(0);
	ui->groupBox_Container->setEnabled(1);
	fill_ComboCNBox();
}


void Dialog_OneSized::update_SMvalues()
{
	QString compareString = ui->comboBox_SmallBoxes->currentText();
	for (std::list<std::pair<std::string, std::list<double>>>::iterator it = this->listItems.begin(); it != this->listItems.end(); it++)
	{
		if (compareString == QString::fromStdString((*it).first))
		{
			std::list<double> listValues = (*it).second;
			int count = 0;
			for (std::list<double>::iterator itValues = listValues.begin(); itValues != listValues.end(); itValues++)
			{
				switch (count++)
				{
				case 0:
					ui->lineEdit_SmallBoxWidth->setText(QString::number(*itValues));
					break;
				case 1:
					ui->lineEdit_SmallBoxHeight->setText(QString::number(*itValues));
					break;
				case 2:
					ui->lineEdit_SmallBoxLength->setText(QString::number(*itValues));
					break;
				}
			}
		}
	}
}

void Dialog_OneSized::update_CNvalues()
{
	QString compareString = ui->comboBox_Containers->currentText();
	for (std::list<std::pair<std::string, std::list<double>>>::iterator it = this->listItems.begin(); it != this->listItems.end(); it++)
	{
		if (compareString == QString::fromStdString((*it).first))
		{
			std::list<double> listValues = (*it).second;
			int count = 0;
			for (std::list<double>::iterator itValues = listValues.begin(); itValues != listValues.end(); itValues++)
			{
				switch (count++)
				{
				case 0:
					ui->lineEdit_ContainerWidth->setText(QString::number(*itValues));
					break;
				case 1:
					ui->lineEdit_ContainerHeight->setText(QString::number(*itValues));
					break;
				case 2:
					ui->lineEdit_ContainerLength->setText(QString::number(*itValues));
					break;
				}
			}
		}
	}
}


void Dialog_OneSized::fill_ComboSMBox()
{
	ui->comboBox_SmallBoxes->clear();
	std::ifstream file("SmallBox.csv");
	std::string name;
	std::string fileContainerX;
	std::string fileContainerY;
	std::string fileContainerZ;
	this->listItems.clear();

	ui->comboBox_SmallBoxes->addItem("Select to load");
	if (file.is_open()) {
		while (file.good())
		{
			getline(file, name, ',');
			getline(file, fileContainerX, ',');
			getline(file, fileContainerY, ',');
			getline(file, fileContainerZ, '\n');
			if (name != "") {
				std::list<double> listContainer;
				listContainer.push_back(std::stod(fileContainerX));
				listContainer.push_back(std::stod(fileContainerY));
				listContainer.push_back(std::stod(fileContainerZ));
				this->listItems.push_back(std::make_pair(name, listContainer));
				ui->comboBox_SmallBoxes->addItem(QString::fromStdString(name));
			}
		}
		file.close();
	}
	
}

void Dialog_OneSized::fill_ComboCNBox()
{
	ui->comboBox_Containers->clear();
	std::ifstream file("BigBox.csv");
	std::string name;
	std::string fileContainerX;
	std::string fileContainerY;
	std::string fileContainerZ;
	this->listItems.clear();

	ui->comboBox_Containers->addItem("Select to load");
	if (file.is_open()) {
		while (file.good())
		{
			getline(file, name, ',');
			getline(file, fileContainerX, ',');
			getline(file, fileContainerY, ',');
			getline(file, fileContainerZ, '\n');
			if (name != "") {
				std::list<double> listContainer;
				listContainer.push_back(std::stod(fileContainerX));
				listContainer.push_back(std::stod(fileContainerY));
				listContainer.push_back(std::stod(fileContainerZ));
				this->listItems.push_back(std::make_pair(name, listContainer));
				ui->comboBox_Containers->addItem(QString::fromStdString(name));
			}
		}
		file.close();
	}
	
}


void Dialog_OneSized::on_OneSized_Clicked()
{
	MainWindow gui2;
	this->containerX = (ui->lineEdit_ContainerWidth->text()).toDouble();
	this->containerY = (ui->lineEdit_ContainerHeight->text()).toDouble();
	this->containerZ = (ui->lineEdit_ContainerLength->text()).toDouble();

	this->boxX = (ui->lineEdit_SmallBoxWidth->text()).toDouble();
	this->boxY = (ui->lineEdit_SmallBoxHeight->text()).toDouble();
	this->boxZ = (ui->lineEdit_SmallBoxLength->text()).toDouble();
	
	
	gui2.set_container(containerX, containerY, containerZ, boxX, boxY, boxZ);
	
	close();
}

