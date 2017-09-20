#include "stdafx.h"
#include <iostream>

#include <list>
#include <string>

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
	this->listOfRestBoxes = CalculateRestBoxes(this->bigBox, this->smallBox, this->listOfDemention);
}



void Stack::GetStack()
{
	cout <<"BigBox : " << this->bigBox.getBigBoxWidth() << ", " << bigBox.getBigBoxHeight() << ", " << bigBox.getBigBoxLength() << "\n";
	cout << "SmallBox : " << smallBox.getSmallBoxWidth() << ", " << smallBox.getSmallBoxHeight() << ", " << smallBox.getSmallBoxLength() << "\n";
	cout << "Demension: x = " << this->listOfDemention[0] <<", y = "<< this->listOfDemention[1] << " , z = " << this->listOfDemention[2] << endl;
	cout << "Totalnumber: " << this->totalNumber << endl;
	int count = 0;
	for (std::list<BigBox*>::iterator it = listOfRestBoxes.begin(); it != listOfRestBoxes.end(); it++) 
	{
		cout << "BigBox" << ++count<< ": \n" << ((BigBox)**it).printBigBox() << endl;
	}
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

// Calculate the Rest Boxes with only the Boxes which are allowed
list<BigBox*> Stack::CalculateRestBoxes(BigBox bigBox, SmallBox smallBox, int listOfDemention[3])
{
	list<BigBox*> listBigBox;
	double tmp;
	for (int i = 0; i < 3; i++) 
	{
		switch (i) 
		{
			case(0):
				tmp = bigBox.getBigBoxWidth() - (smallBox.getSmallBoxWidth()*listOfDemention[0]);
				if (Prove(tmp, bigBox.getBigBoxHeight(), bigBox.getBigBoxLength(), smallBox))
				{
					listBigBox.push_back(new BigBox(tmp, bigBox.getBigBoxHeight(), bigBox.getBigBoxLength()));
				}
				break;

			case(1):	
				tmp = bigBox.getBigBoxHeight() - (smallBox.getSmallBoxHeight()*listOfDemention[1]);
				if (Prove( bigBox.getBigBoxWidth(), tmp, bigBox.getBigBoxLength(), smallBox))
				{
					listBigBox.push_back(new BigBox(bigBox.getBigBoxWidth(), bigBox.getBigBoxHeight() - (smallBox.getSmallBoxHeight()*listOfDemention[1]), bigBox.getBigBoxLength()));
				}
				break;

			case(2):	
				tmp = bigBox.getBigBoxLength() - (smallBox.getSmallBoxLength()*listOfDemention[2]);
				if (Prove( bigBox.getBigBoxWidth(), bigBox.getBigBoxHeight(), tmp, smallBox))
				{
					listBigBox.push_back(new BigBox(bigBox.getBigBoxWidth(), bigBox.getBigBoxHeight(), bigBox.getBigBoxLength() - (smallBox.getSmallBoxLength()*listOfDemention[2])));
				}
				break;
		}
	}
	return listBigBox;
}

std::list<BigBox*> Stack::getBigBox()
{
	return this->listOfRestBoxes;
}

bool Stack::Prove(double bigBoxWidth, double bigBoxHeight, double bigBoxLength, SmallBox smallBox)
{
	double top=smallBox.getSmallBoxWidth();
	double middle = smallBox.getSmallBoxHeight();
	double down = smallBox.getSmallBoxLength();
	bool test = true;
	while (test) {
		if (middle > top)
		{
			double tmp = top;
			top = middle;
			middle = tmp;
		}
		else if (down > middle) {
			double tmp = middle;
			middle = down;
			down = tmp;
		}
		else if (down > top) {
			double tmp = top;
			top = down;
			down = tmp;
		}
		else {
			test = false;
		}
	}

	if (bigBoxWidth >= top && bigBoxHeight >= middle && bigBoxLength >= down ||
		bigBoxWidth >= middle && bigBoxHeight >= top && bigBoxLength >= down ||
		bigBoxWidth >= top && bigBoxHeight >= down && bigBoxLength >= middle ||
		bigBoxWidth >= down && bigBoxHeight >= top && bigBoxLength >= middle ||
		bigBoxWidth >= down && bigBoxHeight >= middle && bigBoxLength >= top ||
		bigBoxWidth >= middle && bigBoxHeight >= down && bigBoxLength >= top ){
		return true;
	}
	return false;
}

int Stack::getTotalNumber()
{
	return this->totalNumber;
}

Stack::~Stack()
{
}
