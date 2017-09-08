#include "stdafx.h"
#include <iostream>
#include "Stack.h"
#include "Stack.h"

using namespace std;

Stack::Stack()
{
}

Stack::Stack(BigBox bigBox, SmallBox smallBox)
{
	this->bigBox = bigBox;
	this->smallBox = smallBox;
}


void Stack::getStack()
{
	cout <<"BigBox : " << bigBox.getBigBoxWidth() << ", " << bigBox.getBigBoxHeight() << ", " << bigBox.getBigBoxLength() << "\n";
	cout << "SmallBox : " << smallBox.getSmallBoxWidth() << ", " << smallBox.getSmallBoxHeight() << ", " << smallBox.getSmallBoxLength() << "\n";

}

Stack::~Stack()
{
}
