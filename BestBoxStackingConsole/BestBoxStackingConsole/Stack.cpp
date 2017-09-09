#include "stdafx.h"
#include <iostream>
#include <list>
#include "BigBox.h"
#include "SmallBox.h"
#include "Stack.h"

using namespace std;

Stack::Stack()
{
}

Stack::Stack(BigBox bigBox, SmallBox smallBox)
{
	this->bigBox = bigBox;
	this->smallBox = smallBox;
	CalculateDemention(this->bigBox, this->smallBox);
	CalculateTotalNumber();
	CalculateRestBoxes(this->bigBox, this->smallBox, this->listOfDemention);
}



void Stack::GetStack()
{
	cout <<"BigBox : " << this->bigBox.getBigBoxWidth() << ", " << bigBox.getBigBoxHeight() << ", " << bigBox.getBigBoxLength() << "\n";
	cout << "SmallBox : " << smallBox.getSmallBoxWidth() << ", " << smallBox.getSmallBoxHeight() << ", " << smallBox.getSmallBoxLength() << "\n";
	cout << "x = " << this->listOfDemention[0] <<", y = "<< this->listOfDemention[1] << " , z = " << this->listOfDemention[2] << endl;
	cout << "Totalnumber: " << this->totalNumber << endl;
	cout << "BigBox1: \nWidth: " << test[0].getBigBoxWidth() << ", " << test[0].getBigBoxHeight() << ", " << test[0].getBigBoxLength() << "\n";
	cout << "BigBox2: \nWidth: " << test[1].getBigBoxWidth() << ", " << test[1].getBigBoxHeight() << ", " << test[1].getBigBoxLength() << "\n";
	cout << "BigBox3: \nWidth: " << test[2].getBigBoxWidth() << ", " << test[2].getBigBoxHeight() << ", " << test[2].getBigBoxLength() << "\n";

}
void Stack::CalculateDemention(BigBox bigBox, SmallBox smallBox)
{
	this->listOfDemention[0] = (int)(bigBox.getBigBoxWidth() / smallBox.getSmallBoxWidth());
	this->listOfDemention[1] = (int)(bigBox.getBigBoxHeight() / smallBox.getSmallBoxHeight());
	this->listOfDemention[2] = (int)(bigBox.getBigBoxLength() / smallBox.getSmallBoxLength());
}

void Stack::CalculateTotalNumber()
{
	this->totalNumber = this->listOfDemention[0] * this->listOfDemention[1] * this->listOfDemention[2];
}

void Stack::CalculateRestBoxes(BigBox bigBox, SmallBox smallBox, int listOfDemention[3])
{
	//list<BigBox> listBigBox;

	for (int i = 0; i < 3; i++) {

		switch (i) {
		case(0):	test[i] = (*(new BigBox(bigBox.getBigBoxWidth()-(smallBox.getSmallBoxWidth()*listOfDemention[0]),bigBox.getBigBoxHeight(),bigBox.getBigBoxLength())));
			break;
		case(1):	test[i] = (*(new BigBox(bigBox.getBigBoxWidth(),bigBox.getBigBoxHeight()-(smallBox.getSmallBoxHeight()*listOfDemention[1]),bigBox.getBigBoxLength())));
			break;
		case(2):	test[i] = (*(new BigBox(bigBox.getBigBoxWidth(), bigBox.getBigBoxHeight(),bigBox.getBigBoxLength()-(smallBox.getSmallBoxLength()*listOfDemention[2]))));
			break;
		}

		if (test[i].getBigBoxWidth() < smallBox.getSmallBoxWidth() && test[i].getBigBoxWidth() < smallBox.getSmallBoxHeight() && test[i].getBigBoxWidth() < smallBox.getSmallBoxLength() ||
			test[i].getBigBoxHeight() < smallBox.getSmallBoxWidth() && test[i].getBigBoxHeight() < smallBox.getSmallBoxHeight() && test[i].getBigBoxHeight() < smallBox.getSmallBoxLength() ||
			test[i].getBigBoxLength() < smallBox.getSmallBoxWidth() && test[i].getBigBoxLength() < smallBox.getSmallBoxHeight() && test[i].getBigBoxLength() < smallBox.getSmallBoxLength()) 
		{
			test[i] = *new BigBox(0, 0, 0);
		}
	}
}




Stack::~Stack()
{
}
