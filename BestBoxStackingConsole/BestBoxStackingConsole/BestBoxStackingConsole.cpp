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
	BigBox bigBox;
	bigBox.setBigBoxWidth(14);
	bigBox.setBigBoxHeight(13);
	bigBox.setBigBoxLength(7);
	//SmallBox smallBox(2.5, 3.5, 1.5);

	cout << "BigBox : " << bigBox.getBigBoxWidth() << ", " << bigBox.getBigBoxHeight() << ", " << bigBox.getBigBoxLength() << "" << endl;
	//cout << "SmallBox : " << smallBox.getSmallBoxWidth() << ", " << smallBox.getSmallBoxHeight() << ", " << smallBox.getSmallBoxLength() << "" << endl;

	//Stack stack1(bigBox);
	//stack1.getStack();
	int test;
	cin >> test;
    return 0;
}

