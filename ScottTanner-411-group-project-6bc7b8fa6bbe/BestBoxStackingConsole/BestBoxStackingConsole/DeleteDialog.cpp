#include "DeleteDialog.h"
#include"ui_delete.h"
#include<iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include<stdio.h>

DeleteDialog::DeleteDialog(QWidget *parent):
	QDialog(parent),
	ui(new Ui::DeleteDialog)
{
	ui->setupUi(this);
	connect(ui->pushButton_Delete, &QPushButton::clicked, this, &DeleteDialog::on_DeleteButton_Clicked);
	connect(ui->pushButton_Cancel, &QPushButton::clicked, this, &DeleteDialog::on_CancelDelete_Clicked);
}


DeleteDialog::~DeleteDialog()
{
}

void DeleteDialog::fill_ComboSMBox(bool small)
{
	ui->comboBox_BoxDelete->clear();
	if (small) 
	{
		this->filename = "SmallBox.csv";
	}
	else 
	{
		this->filename = "BigBox.csv";
	}
	std::ifstream file(this->filename);
	std::string name;
	std::string fileContainerX;
	std::string fileContainerY;
	std::string fileContainerZ;
	this->listStringsPair.clear();

	ui->comboBox_BoxDelete->addItem("Select to load");
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
				this->listStringsPair.push_back(std::make_pair(name, listContainer));
				ui->comboBox_BoxDelete->addItem(QString::fromStdString(name));
			}
		}
		file.close();
	}

}

void DeleteDialog::on_CancelDelete_Clicked()
{
	close();
}

void DeleteDialog::on_DeleteButton_Clicked()
{
	if (this->ui->comboBox_BoxDelete->currentText().toStdString() == "" || this->ui->comboBox_BoxDelete->currentText().toStdString() == "Select to load" )
	{
		return;
	}
	std::string oldFilename = this->filename;
	oldFilename += ".old";

	rename(this->filename.c_str(), oldFilename.c_str());
	try {
		this->boxName = this->ui->comboBox_BoxDelete->currentText().toStdString();
		std::ofstream file(this->filename);

			
			std::list<double> second;
			int countSecond = 0;
			for (std::list<std::pair<std::string, std::list<double>>>::iterator itNewListFile = this->listStringsPair.begin(); itNewListFile != this->listStringsPair.end(); itNewListFile++)
			{
				if (this->boxName == (*itNewListFile).first)
				{
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
		file.close();
		remove(oldFilename.c_str());
	}
	catch (const std::exception e)
	{
		rename(oldFilename.c_str(), this->filename.c_str());

	}

	this->close();
}