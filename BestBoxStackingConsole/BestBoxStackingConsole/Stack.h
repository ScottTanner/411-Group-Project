#pragma once
#include "BigBox.h"
#include "SmallBox.h"
class Stack
{
private:
	BigBox bigBox;
	SmallBox smallBox;
public:
	Stack();
	Stack(BigBox bigBox, SmallBox smallBox);
	void getStack();
	~Stack();
};

