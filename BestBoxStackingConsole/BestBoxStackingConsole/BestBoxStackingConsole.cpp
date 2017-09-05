// BestBoxStackingConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BigBox.h"
#include "SmallBox.h"
#include "Stack.h"
#include<algorithm>
#include<iostream>

using namespace std;
int main()
{
	BigBox bigBox(14, 13, 7);
	SmallBox smallBox(2.5, 3.5, 1.5);

	cout << "BigBox : " << bigBox.getBigBoxWidth() << ", " << bigBox.getBigBoxHeight() << ", " << bigBox.getBigBoxLength() << "" << endl;
	cout << "SmallBox : " << smallBox.getSmallBoxWidth() << ", " << smallBox.getSmallBoxHeight() << ", " << smallBox.getSmallBoxLength() << "" << endl;

	//Stack stack1(bigBox, smallBox);
	//stack1.getStack();
	int test;
	cin >> test;
    return 0;
}

