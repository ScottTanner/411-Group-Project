#include "stdafx.h"
#include "BigBox.h"
#include "SmallBox.h"
#include "Stack.h"
#include<algorithm>
#include<iostream>
#include<list>

using namespace std;
int main()
{
	BigBox bigBox(14,13,7);
	SmallBox smallBox(2.5, 3.5, 1.5);
	list<Stack> listOfStacks;
	list<BigBox> listOfNewBigBoxes;
	Stack stack1(bigBox,smallBox);
	listOfStacks.push_back(stack1);
	stack1.getStack();
	int test;
	cin >> test;
    return 0;
}

