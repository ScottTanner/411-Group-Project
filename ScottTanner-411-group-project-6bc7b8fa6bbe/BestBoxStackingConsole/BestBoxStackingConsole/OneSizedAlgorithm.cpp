#include"save.h"
#include "DeleteDialog.h"
#include <iostream>
#include <fstream>
#include<string>

#include "OneSizedAlgorithm.h"
#include "ui_OneSizedSmallBoxes.h"
int Go =0;

Dialog_OneSized::Dialog_OneSized(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog_OneSized)
{
	ui->setupUi(this);
	fill_ComboCNBox();
	calculated = false;
	connect(ui->comboBox_SmallBoxes, SIGNAL(currentIndexChanged(QString)), this, SLOT(update_SMvalues()));
	connect(ui->comboBox_Containers, SIGNAL(currentIndexChanged(QString)), this, SLOT(update_CNvalues()));
	connect(ui->pushButton_ContainerSave, &QPushButton::clicked, this, &Dialog_OneSized::on_pushButton_Save_Container_Clicked);
	connect(ui->pushButton_SmallBoxSave, &QPushButton::clicked, this, &Dialog_OneSized::on_pushButton_Save_SmallBox_Clicked);
	connect(ui->pushButton_DeleteCon, &QPushButton::clicked, this, &Dialog_OneSized::on_pushButton_ContainerDelete_Clicked);
	connect(ui->pushButton_DeleteSB, &QPushButton::clicked, this, &Dialog_OneSized::on_pushButton_SmallBoxDelete_Clicked);
	connect(ui->pushButton_ContainerDelete, &QPushButton::clicked, this, &Dialog_OneSized::on_pushButton_ClearContainer_Clicked);
	connect(ui->pushButton_SmallBoxDelete, &QPushButton::clicked, this, &Dialog_OneSized::on_pushButton_ClearSmallBox_Clicked);
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

double Dialog_OneSized::GetContainerX()
{
	return this->containerX;
}

double Dialog_OneSized::GetContainerY()
{
	return this->containerY;
}

double Dialog_OneSized::GetContainerZ()
{
	return this->containerZ;
}

double Dialog_OneSized::GetSmallBoxX()
{
	return this->boxX;
}

double Dialog_OneSized::GetSmallBoxY()
{
	return this->boxY;
}

double Dialog_OneSized::GetSmallBoxZ()
{
	return this->boxZ;
}

void Dialog_OneSized::setTextBoxesEdit()
{
	this->ui->lineEdit_ContainerWidth->setText(QString::number(this->containerX));
	this->ui->lineEdit_ContainerHeight->setText(QString::number(this->containerY));
	this->ui->lineEdit_ContainerLength->setText(QString::number(this->containerZ));

	this->ui->lineEdit_SmallBoxWidth->setText(QString::number(this->boxX));
	this->ui->lineEdit_SmallBoxHeight->setText(QString::number(this->boxY));
	this->ui->lineEdit_SmallBoxLength->setText(QString::number(this->boxZ));

	return;
}

bool Dialog_OneSized::getCalculated()
{
	return this->calculated;
}

void Dialog_OneSized::on_pushButton_2_clicked()
{
	close();
}

void Dialog_OneSized::on_pushButton_ContainerDelete_Clicked()
{
	DeleteDialog deleteD;
	deleteD.fill_ComboSMBox();
	deleteD.setModal(true);
	deleteD.exec();
	fill_ComboCNBox();

}

void Dialog_OneSized::on_pushButton_SmallBoxDelete_Clicked()
{
	ui->lineEdit_SmallBoxWidth->setText("");
	ui->lineEdit_SmallBoxHeight->setText("");
	ui->lineEdit_SmallBoxLength->setText("");
	DeleteDialog deleteD;
	deleteD.fill_ComboSMBox(true);
	deleteD.setModal(true);
	deleteD.exec();
	fill_ComboSMBox();
}


void Dialog_OneSized::on_pushButton_Done_clicked()
{
	ui->groupBox_SmallBox->setEnabled(1);
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
	ui->pushButton_DeleteSB->setEnabled(1);

	ui->groupBox_Container->setDisabled(1);
	
	fill_ComboSMBox();

}

void Dialog_OneSized::on_pushButton_Done2_clicked()
{
	ui->pushButton_Calulate->setEnabled(1);
}

void Dialog_OneSized::on_pushButton_Back_clicked()
{
	ui->groupBox_Container->setEnabled(1);
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

	ui->pushButton_Calulate->setDisabled(1);
	ui->groupBox_SmallBox->setDisabled(1);
	fill_ComboCNBox();
}

void Dialog_OneSized::on_pushButton_Calulate_clicked()
{
	this->containerX = (ui->lineEdit_ContainerWidth->text()).toDouble();
	this->containerY = (ui->lineEdit_ContainerHeight->text()).toDouble();
	this->containerZ = (ui->lineEdit_ContainerLength->text()).toDouble();

	this->boxX = (ui->lineEdit_SmallBoxWidth->text()).toDouble();
	this->boxY = (ui->lineEdit_SmallBoxHeight->text()).toDouble();
	this->boxZ = (ui->lineEdit_SmallBoxLength->text()).toDouble();
	calculated = true;
	close();
}

void Dialog_OneSized::on_pushButton_Save_Container_Clicked()
{
	Save save;
	save.setFlagBox(true);
	save.setFilename("BigBox.csv");
	save.setValues((this->ui->lineEdit_ContainerWidth->text()).toDouble(), (this->ui->lineEdit_ContainerHeight->text()).toDouble(), (this->ui->lineEdit_ContainerLength->text()).toDouble());
	save.setlistStingsPair(this->listItems);
	save.setModal(true);
	save.exec();
	fill_ComboCNBox();
	ui->comboBox_Containers->setCurrentIndex(save.GetIndex());
	if (save.GetIndex() == 0) 
	{
		on_pushButton_ClearContainer_Clicked();
	}
}

void Dialog_OneSized::on_pushButton_Save_SmallBox_Clicked()
{
	Save save;
	save.setFlagBox(false);
	save.setFilename("SmallBox.csv");
	save.setValues((this->ui->lineEdit_SmallBoxWidth->text()).toDouble(), (this->ui->lineEdit_SmallBoxHeight->text()).toDouble(), (this->ui->lineEdit_SmallBoxLength->text()).toDouble());	
	save.setlistStingsPair(this->listItems);
	save.setModal(true);
	save.exec();
	fill_ComboSMBox();
	ui->comboBox_SmallBoxes->setCurrentIndex(save.GetIndex());
	if (save.GetIndex() == 0)
	{
		on_pushButton_ClearSmallBox_Clicked();
	}
}

void Dialog_OneSized::on_pushButton_ClearContainer_Clicked()
{
	ui->lineEdit_ContainerWidth->setText("");
	ui->lineEdit_ContainerHeight->setText("");
	ui->lineEdit_ContainerLength->setText("");
	ui->comboBox_Containers->setCurrentIndex(0);
}

void Dialog_OneSized::on_pushButton_ClearSmallBox_Clicked()
{
	ui->lineEdit_SmallBoxWidth->setText("");
	ui->lineEdit_SmallBoxHeight->setText("");
	ui->lineEdit_SmallBoxLength->setText("");
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

