#include "stdafx.h"
#include "SmallBox.h"


SmallBox::SmallBox()
{
	this->width = 0;
	this->height = 0;
	this->length = 0;
}

SmallBox::SmallBox(double width, double height, double length)
{
	this->width = width;
	this->height = height;
	this->length = length;
}

double SmallBox::getSmallBoxWidth()
{
	return this->width;
}

double SmallBox::getSmallBoxHeight()
{
	return this->height;
}

double SmallBox::getSmallBoxLength()
{
	return this->length;
}


SmallBox::~SmallBox()
{
}
