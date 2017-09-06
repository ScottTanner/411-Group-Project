#include "stdafx.h"
#include "BigBox.h"


BigBox::BigBox()
{
}

void BigBox::setBigBoxWidth(double width)
{
	this->width = width;
}

void BigBox::setBigBoxHeight(double height)
{
	this->height = height;
}


void BigBox::setBigBoxLength(double length)
{
	this->length = length;
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