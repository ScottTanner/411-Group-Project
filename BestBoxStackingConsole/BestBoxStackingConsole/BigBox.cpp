#include "stdafx.h"
#include "BigBox.h"


BigBox::BigBox()
{
	this->width = 0;
	this->height = 0;
	this->length = 0;
}

BigBox::BigBox(double width, double height, double length)
{
	this->width = width;
	this->height = height;
	this->length = length;
}

BigBox::BigBox(const BigBox &obj)
{
	width = obj.width;
	height = obj.height;
	length = obj.length;
}

double BigBox::getBigBoxWidth()
{
	return this->width;
}

double BigBox::getBigBoxHeight()
{
	return this->height;
}

double BigBox::getBigBoxLength()
{
	return this->length;
}


BigBox::~BigBox()
{
}