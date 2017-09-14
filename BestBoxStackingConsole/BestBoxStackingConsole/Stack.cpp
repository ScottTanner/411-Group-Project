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
	cout << "x = " << this->listOfDemention[0] <<", y = "<< this->listOfDemention[1] << " , z = " << this->listOfDemention[2] << endl;
	cout << "Totalnumber: " << this->totalNumber << endl;
	int count = 0;
	for (std::list<BigBox*>::iterator it = listOfRestBoxes.begin(); it != listOfRestBoxes.end(); it++) 
	{
		cout << "BigBox" << ++count << ": \n" << ((BigBox)**it).printBigBox() << endl;
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

				if ((tmp > smallBox.getSmallBoxWidth() || tmp > smallBox.getSmallBoxHeight() || tmp > smallBox.getSmallBoxLength()) &&
					(bigBox.getBigBoxHeight() > smallBox.getSmallBoxWidth() || bigBox.getBigBoxHeight()  > smallBox.getSmallBoxHeight() || bigBox.getBigBoxHeight() > smallBox.getSmallBoxHeight()) &&
					(bigBox.getBigBoxLength() > smallBox.getSmallBoxWidth() || bigBox.getBigBoxLength() > smallBox.getSmallBoxHeight()  || bigBox.getBigBoxLength() > smallBox.getSmallBoxHeight())
					)
				{
					listBigBox.push_back(new BigBox(tmp, bigBox.getBigBoxHeight(), bigBox.getBigBoxLength()));
				}
				break;

			case(1):	
				tmp = bigBox.getBigBoxHeight() - (smallBox.getSmallBoxHeight()*listOfDemention[1]);

				if ((bigBox.getBigBoxWidth() > smallBox.getSmallBoxWidth()  || bigBox.getBigBoxWidth() > smallBox.getSmallBoxHeight()  || bigBox.getBigBoxWidth() > smallBox.getSmallBoxHeight()) &&
					(tmp > smallBox.getSmallBoxWidth() || tmp > smallBox.getSmallBoxHeight() || tmp > smallBox.getSmallBoxLength()) &&
					(bigBox.getBigBoxLength() > smallBox.getSmallBoxWidth() || bigBox.getBigBoxLength() > smallBox.getSmallBoxHeight() || bigBox.getBigBoxLength() > smallBox.getSmallBoxHeight())
					)
				{
					listBigBox.push_back(new BigBox(bigBox.getBigBoxWidth(), bigBox.getBigBoxHeight() - (smallBox.getSmallBoxHeight()*listOfDemention[1]), bigBox.getBigBoxLength()));
				}
				break;

			case(2):	
				tmp = bigBox.getBigBoxWidth() - (smallBox.getSmallBoxWidth()*listOfDemention[0]);
					
				if ((bigBox.getBigBoxWidth() > smallBox.getSmallBoxWidth() || bigBox.getBigBoxWidth() > smallBox.getSmallBoxHeight() || bigBox.getBigBoxWidth() > smallBox.getSmallBoxHeight()) &&
					(bigBox.getBigBoxHeight() > smallBox.getSmallBoxWidth() || bigBox.getBigBoxHeight()  > smallBox.getSmallBoxHeight() || bigBox.getBigBoxHeight() > smallBox.getSmallBoxHeight()) &&
					(tmp > smallBox.getSmallBoxWidth() || tmp > smallBox.getSmallBoxHeight() || tmp > smallBox.getSmallBoxLength())
				)
				{
					listBigBox.push_back(new BigBox(bigBox.getBigBoxWidth(), bigBox.getBigBoxHeight(), bigBox.getBigBoxLength() - (smallBox.getSmallBoxLength()*listOfDemention[2])));
				}
				break;
		}
	}
	return listBigBox;
}




Stack::~Stack()
{
}
