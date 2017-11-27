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

Save::~Save()
{
	delete ui;
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

void Save::setFilename(std::string fName)
{
	this->filename = fName;
}

void Save::setlistStingsPair(std::list<std::pair<std::string, std::list<double>>> listStringsPair)
{
	this->listStringsPair = listStringsPair;
}

int Save::GetIndex()
{
	return this->index;
}

void Save::on_pushButton_Save_clicked()
{
	if (this->ui->lineEdit_name->text().toStdString() == "") 
	{
		return;
	}
	std::string oldFilename = this->filename;
	oldFilename += ".old";

	rename(this->filename.c_str(), oldFilename.c_str());
	try {
		this->name = this->ui->lineEdit_name->text().toStdString();
		std::ofstream file(this->filename);

		std::list<double> second;
		int countSecond = 0;
		bool isOverwrite = false;
		for (std::list<std::pair<std::string, std::list<double>>>::iterator itNewListFile = this->listStringsPair.begin(); itNewListFile != this->listStringsPair.end(); itNewListFile++)
		{
			if (isOverwrite == false) {
				this->index++;
			}
			if (this->name == (*itNewListFile).first)
			{
				file << (*itNewListFile).first << "," << this->boxX << "," << this->boxY << "," << this->boxZ << "\n";
				isOverwrite = true;
				continue;
			}
			std::string BoxX;
			std::string BoxY;
			std::string BoxZ;
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
					BoxX = streamBoxX.str();
					break;
				case 1:
					streamBoxY << std::fixed << std::setprecision(2) << *itBoxValues;;
					BoxY = streamBoxY.str();
					break;
				case 2:
					streamBoxZ << std::fixed << std::setprecision(2) << *itBoxValues;;
					BoxZ = streamBoxZ.str();
					break;
				}
			}
			file << (*itNewListFile).first << "," << BoxX << "," << BoxY << "," << BoxZ << "\n";
		}
		if (isOverwrite == false) 
		{
			file << this->name << "," << this->boxX << "," << this->boxY << "," << this->boxZ << "\n";
			index++;
		}
		file.close();
		remove(oldFilename.c_str());
	}
	catch (const std::exception e)
	{
		rename(oldFilename.c_str(), this->filename.c_str());

	}

	close();
}

void Save::on_pushButton_Cancel_clicked()
{
    close();
}
