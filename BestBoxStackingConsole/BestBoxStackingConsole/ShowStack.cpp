#include "stdafx.h"
#include "ShowStack.h"


ShowStack::ShowStack()
{
}

ShowStack::ShowStack(Stack stack)
{
	this->bigBox = stack.getBigBox();
	this->smallBox = stack.getSmallBox();
	this->totalnumber = stack.getTotalNumber();
}

BigBox ShowStack::getBigBox()
{
	return this->bigBox;
}


ShowStack::~ShowStack()
{
}
