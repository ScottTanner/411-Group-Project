#include "stdafx.h"
#include "BigBox.h"


BigBox::BigBox()
{
}

// constructor for a BigBox
BigBox::BigBox(double width, double height, double length)
{
	this->width = width;
	this->height = height;
	this->length = length;
}

BigBox::~BigBox()
{
}

// Get the width by BigBox
double BigBox::GetBigBoxWidth()
{
	return this->width;
}

// Get the height by BigBox
double BigBox::GetBigBoxHeight()
{
	return this->height;
}

// Get the length by BigBox
double BigBox::GetBigBoxLength()
{
	return this->length;
}

bool BigBox::operator==(BigBox & bigBox)const
{
	if (this->width == bigBox.width && this->height == bigBox.height && this->length == bigBox.length)
	{
		return true;
	}
	return false;
}

bool BigBox::operator!=(BigBox & bigBox) const
{
	if (!(this->width == bigBox.width && this->height == bigBox.height && this->length == bigBox.length))
	{
		return true;
	}
	return false;
}
