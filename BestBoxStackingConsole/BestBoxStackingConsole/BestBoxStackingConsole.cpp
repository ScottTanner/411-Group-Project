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
	// create a Big Box
	BigBox bigBox(14,13,7);

	// Create a Small Box
	SmallBox smallBox(5.5, 3.5, 1.5);
	
	//Create a list of stacks
	list<Stack> listOfStacks;

	//Create a list of new Big Box
	list<BigBox> listOfNewBigBoxes;

	//Create a Stack
	Stack stack1(bigBox,smallBox);

	// Add stack 1
	listOfStacks.push_back(stack1);
	
	// Print stack out
	stack1.GetStack();
	int test;
	cin >> test;
    return 0;
}

