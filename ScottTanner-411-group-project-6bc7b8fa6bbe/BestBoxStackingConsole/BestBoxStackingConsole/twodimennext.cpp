#include"calculate.h"
#include <iostream>
#include <fstream>
#include "save.h"
#include "twodimennext.h"
#include "ui_twodimennext.h"

TwoDimenNext::TwoDimenNext(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TwoDimenNext)
{
    ui->setupUi(this);
	fill_ComboBox();
	connect(ui->comboBox_smallBoxcontainer, SIGNAL(currentIndexChanged(QString)), this, SLOT(update_values()));

}

void TwoDimenNext::set_container(double cX, double cY, double cZ, double boxX, double boxY, double boxZ)
{
	this->containerX = cX;
	this->containerY = cY;
	this->containerZ = cZ;
	this->boxX = boxX;
	this->boxY = boxY;
	this->boxZ = boxZ;
}

TwoDimenNext::~TwoDimenNext()
{
    delete ui;
}

void TwoDimenNext::on_pushButton_save_clicked()
{
    Save gui3;
	gui3.setFlagBox(false);
	double width = ui->lineEdit_width->text().toDouble();
	double height = ui->lineEdit_height->text().toDouble();
	double length = ui->lineEdit_length->text().toDouble();
	gui3.setValues(width, height, length);
	gui3.setlistStingsPair(this->listItems);
    gui3.setModal(true);
    gui3.exec();
	fill_ComboBox();
}

void TwoDimenNext::on_pushButton_next_clicked()
{
    Calculate gui2;
	this->boxX = (ui->lineEdit_width->text()).toDouble();
	this->boxY = (ui->lineEdit_height->text()).toDouble();
	this->boxZ = (ui->lineEdit_length->text()).toDouble();
	gui2.set_Container(containerX, containerY, containerZ, boxX, boxY, boxZ);
    gui2.setModal(true);
    gui2.exec();
}

void TwoDimenNext::on_pushButton_clear_clicked()
{
	ui->lineEdit_width->setText("");
	ui->lineEdit_height->setText("");
	ui->lineEdit_length->setText(""); 
}

void TwoDimenNext::on_pushButton_exit_clicked()
{
    close();
}

void TwoDimenNext::update_values()
{
	QString compareString = ui->comboBox_smallBoxcontainer->currentText();
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
					ui->lineEdit_width->setText(QString::number(*itValues));
					break;
				case 1:
					ui->lineEdit_height->setText(QString::number(*itValues));
					break;
				case 2:
					ui->lineEdit_length->setText(QString::number(*itValues));
					break;
				}
			}
		}
	}
}

void TwoDimenNext::fill_ComboBox()
{
	ui->comboBox_smallBoxcontainer->clear();
	std::ifstream file("SmallBox.csv");
	std::string name;
	std::string fileContainerX;
	std::string fileContainerY;
	std::string fileContainerZ;

	ui->comboBox_smallBoxcontainer->addItem("Select to load");
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
				ui->comboBox_smallBoxcontainer->addItem(QString::fromStdString(name));
			}
		}
		file.close();
	}
}
