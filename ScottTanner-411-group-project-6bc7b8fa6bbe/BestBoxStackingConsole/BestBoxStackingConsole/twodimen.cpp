#include"save.h"
#include <iostream>
#include <fstream>
#include<string>
#include "twodimennext.h"
#include "twodimen.h"
#include "ui_twodimen.h"

TwoDimen::TwoDimen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TwoDimen)
{
    ui->setupUi(this);
	fill_ComboBox();
	connect(ui->comboBox_Container,SIGNAL(currentIndexChanged(QString)),this,SLOT(update_values()));
}

TwoDimen::~TwoDimen()
{
    delete ui;
}

void TwoDimen::on_pushButton_Next_clicked()
{
    TwoDimenNext gui2;
	QString cX = ui->lineEdit_Width->text();
	QString cY = ui->lineEdit_Height->text();
	QString cZ = ui->lineEdit_Length->text();
	gui2.set_container(cX.toDouble(), cY.toDouble(), cZ.toDouble(),0,0,0);
    gui2.setModal(true);
    gui2.exec();
}

void TwoDimen::on_pushButton_Save_clicked()
{
    Save gui3;
	gui3.setFlagBox(true);
	double width = ui->lineEdit_Width->text().toDouble();
	double height = ui->lineEdit_Height->text().toDouble();
	double length = ui->lineEdit_Length->text().toDouble();
	gui3.setValues(width, height, length);
	gui3.setlistStingsPair(this->listItems);
    gui3.setModal(true);
    gui3.exec();
	fill_ComboBox();
}

void TwoDimen::on_pushButton_Exit_clicked()
{
    close();
}

void TwoDimen::update_values()
{
	QString compareString = ui->comboBox_Container->currentText();
	for (std::list<std::pair<std::string, std::list<double>>>::iterator it = this->listItems.begin(); it != this->listItems.end(); it++) 
	{
		if (compareString == QString::fromStdString((*it).first))
		{
			std::list<double> listValues = (*it).second;
			int count  = 0;
			for (std::list<double>::iterator itValues = listValues.begin(); itValues != listValues.end(); itValues++) 
			{
				switch (count++) 
				{
				case 0:
					ui->lineEdit_Width->setText(QString::number(*itValues));
					break;
				case 1:
					ui->lineEdit_Height->setText(QString::number(*itValues));
					break;
				case 2:
					ui->lineEdit_Length->setText(QString::number(*itValues));
					break;
				}
			}
		}
	}

}

void TwoDimen::fill_ComboBox()
{
	ui->comboBox_Container->clear();
	std::ifstream file("BigBox.csv");
	std::string name;
	std::string fileContainerX;
	std::string fileContainerY;
	std::string fileContainerZ;
	listItems.clear();
	ui->comboBox_Container->addItem("Select to load");
	if (file.is_open()) {
		while(file.good()) 
		{
			getline(file, name, ',');
			getline(file, fileContainerX,',');
			getline(file, fileContainerY,',');
			getline(file, fileContainerZ, '\n');
			if (name != "") {
				std::list<double> listContainer;
				listContainer.push_back(std::stod(fileContainerX));
				listContainer.push_back(std::stod(fileContainerY));
				listContainer.push_back(std::stod(fileContainerZ));
				listItems.push_back(std::make_pair(name, listContainer));
				ui->comboBox_Container->addItem(QString::fromStdString(name));
			}
		}
		file.close();
	}
	
	
}

void TwoDimen::on_pushButton_Clear_clicked()
{
    ui->lineEdit_Width->setText("");
    ui->lineEdit_Height->setText("");
    ui->lineEdit_Length->setText("");
}
