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
	Stack(BigBox bigBox1,SmallBox smallBox1) :bigBox(bigBox1),smallBox(smallBox1) {

	}
	void getStack();
	~Stack();
};

