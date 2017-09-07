#include "stdafx.h"
#include <iostream>
#include "Stack.h"
#include "Stack.h"

using namespace std;

Stack::Stack()
{
}


void Stack::getStack()
{
	cout <<"BigBox : " << bigBox.getBigBoxWidth() << ", " << bigBox.getBigBoxHeight() << ", " << bigBox.getBigBoxLength() << "\n";
	cout << "SmallBox : " << smallBox.getSmallBoxWidth() << ", " << smallBox.getSmallBoxHeight() << ", " << smallBox.getSmallBoxLength() << "\n";

}

Stack::~Stack()
{
}
