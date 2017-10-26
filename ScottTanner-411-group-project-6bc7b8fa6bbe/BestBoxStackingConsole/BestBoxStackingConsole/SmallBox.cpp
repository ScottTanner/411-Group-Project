#include "stdafx.h"
#include "SmallBox.h"

SmallBox::SmallBox()
{
}

// Constructor for a SmallBox
SmallBox::SmallBox(double width, double height, double length)
{
	this->width = width;
	this->height = height;
	this->length = length;
}

SmallBox::~SmallBox()
{
}

// Get width by SmallBox
double SmallBox::GetSmallBoxWidth()
{
	return this->width;
}
// Get height by SmallBox
double SmallBox::GetSmallBoxHeight()
{
	return this->height;
}

// Get length by SmallBox
double SmallBox::GetSmallBoxLength()
{
	return this->length;
}
