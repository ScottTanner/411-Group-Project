#include<iostream>
#include<list>
#include "stdafx.h"
#include "Stack.h"
#include "BigBox.h"
#include "SmallBox.h"


using namespace std;
Stack::Stack()
{
};

Stack::Stack(BigBox bigBox)//, SmallBox smallBox)
{
	this->bigBox = bigBox;
	//this->smallBox = smallBox;

	//void Stack::getStack()

};

Stack::~Stack()
{
};
