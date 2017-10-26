#include<iostream>
#include<fstream>
#include <iomanip> // setprecision
#include <sstream> // stringstream
#include<string>
#include "save.h"
#include "ui_save.h"

Save::Save(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Save)
{
    ui->setupUi(this);
}

void Save::setFlagBox(bool flag)
{
	this->flagBox = flag;
}

void Save::setValues(double boxX, double boxY, double boxZ)
{
	std::stringstream streamX;
	streamX << std::fixed << std::setprecision(2) << boxX;
	this->boxX = streamX.str();
	std::stringstream streamY;
	streamY << std::fixed << std::setprecision(2) << boxY;
	this->boxY = streamY.str();
	std::stringstream streamZ;
	streamZ << std::fixed << std::setprecision(2) << boxZ;
	this->boxZ = streamZ.str();
}

void Save::setlistStingsPair(std::list<std::pair<std::string, std::list<double>>> listStringsPair)
{
	this->listStringsPair = listStringsPair;
}

Save::~Save()
{
    delete ui;
}

void Save::on_pushButton_Save_clicked()
{
	this->name = this->ui->lineEdit_name->text().toStdString();
	if (this->flagBox == true)
	{
		int count = 0;
		bool sameName = false;
		for (std::list<std::pair<std::string, std::list<double>>>::iterator it = this->listStringsPair.begin(); it != this->listStringsPair.end(); it++)
		{
			if (this->name == (*it).first) 
			{
				sameName = true;
				std::list<double> second = (*it).second;
				int countSecond = 0;
				for (std::list<double>::iterator itDoubles = second.begin(); itDoubles != second.end(); itDoubles++) 
				{
					switch(countSecond++)
					{
					case 0:
						*itDoubles = std::stod(this->boxX);
						break;
					case 1:
						*itDoubles = std::stod(this->boxY);
						break;
					case 2:
						*itDoubles = std::stod(this->boxZ);
						break;
					}
				}
				(*it).second = second;
				std::ofstream file("BigBox.csv");
				for (std::list<std::pair<std::string, std::list<double>>>::iterator itNewListFile = this->listStringsPair.begin(); itNewListFile != this->listStringsPair.end(); itNewListFile++) 
				{
					std::string bigBoxName = (*itNewListFile).first;
					std::string bigBoxX;
					std::string bigBoxY;
					std::string bigBoxZ;
					second = (*itNewListFile).second;
					countSecond = 0;
					for (std::list<double>::iterator itBoxValues = second.begin(); itBoxValues != second.end(); itBoxValues++)
					{
						std::stringstream streamBoxX;
						std::stringstream streamBoxY;
						std::stringstream streamBoxZ;

						switch (countSecond++)
						{
						case 0:
							streamBoxX << std::fixed << std::setprecision(2) << *itBoxValues;
							bigBoxX = streamBoxX.str();
							break;
						case 1:
							streamBoxY << std::fixed << std::setprecision(2) << *itBoxValues;;
							bigBoxY = streamBoxY.str();
							break;
						case 2:
							streamBoxZ << std::fixed << std::setprecision(2) << *itBoxValues;;
							bigBoxZ = streamBoxZ.str();
							break;
						}
					}
					file << bigBoxName << "," << bigBoxX << "," << bigBoxY << "," << bigBoxZ << "\n";
				}
				file.close();
				break;
			}
			count++;
		}
		if (sameName == false) {
			std::ofstream file("BigBox.csv", std::ios::app);
			file << this->name << "," << this->boxX << "," << this->boxY << "," << this->boxZ << "\n";
			file.close();
		}
	}
	else {
		int count = 0;
		bool sameName = false;
		for (std::list<std::pair<std::string, std::list<double>>>::iterator it = this->listStringsPair.begin(); it != this->listStringsPair.end(); it++)
		{
			if (this->name == (*it).first)
			{
				sameName = true;
				std::list<double> second = (*it).second;
				int countSecond = 0;
				for (std::list<double>::iterator itDoubles = second.begin(); itDoubles != second.end(); itDoubles++)
				{
					switch (countSecond++)
					{
					case 0:
						*itDoubles = std::stod(this->boxX);
						break;
					case 1:
						*itDoubles = std::stod(this->boxY);
						break;
					case 2:
						*itDoubles = std::stod(this->boxZ);
						break;
					}
				}
				(*it).second = second;
				std::ofstream file("SmallBox.csv");
				for (std::list<std::pair<std::string, std::list<double>>>::iterator itNewListFile = this->listStringsPair.begin(); itNewListFile != this->listStringsPair.end(); itNewListFile++)
				{
					std::string smallBoxName = (*itNewListFile).first;
					std::string smallBoxX;
					std::string smallBoxY;
					std::string smallBoxZ;
					countSecond = 0;
					second = (*itNewListFile).second;
					for (std::list<double>::iterator itBoxValues = second.begin(); itBoxValues != second.end(); itBoxValues++)
					{
						std::stringstream streamBoxX;
						std::stringstream streamBoxY;
						std::stringstream streamBoxZ;

						switch (countSecond++)
						{
						case 0:
							streamBoxX << std::fixed << std::setprecision(2) << *itBoxValues;
							smallBoxX = streamBoxX.str();
							break;
						case 1:
							streamBoxY << std::fixed << std::setprecision(2) << *itBoxValues;;
							smallBoxY = streamBoxY.str();
							break;
						case 2:
							streamBoxZ << std::fixed << std::setprecision(2) << *itBoxValues;;
							smallBoxZ = streamBoxZ.str();
							break;
						}
					}
					file << smallBoxName << "," << smallBoxX << "," << smallBoxY << "," << smallBoxZ << "\n";
				}
				file.close();
				break;
			}
			count++;
		}
		if (sameName == false) {
			std::ofstream file("SmallBox.csv", std::ios::app);
			file << this->name << "," << this->boxX << "," << this->boxY << "," << this->boxZ << "\n";
			file.close();
		}
	}
	close();
}

void Save::on_pushButton_Cancel_clicked()
{
    close();
}
