#pragma once
#include "BigBox.h"
#include "SmallBox.h"
#include "Stack.h"
class ShowStack
{
public:
	ShowStack();
	ShowStack(Stack stack);
	~ShowStack();
private:
	BigBox bigBox;
	SmallBox smallBox;
	int totalnumber;
};

