#include "stdafx.h"
#include "Stack.h"
#include <iostream>

// Calculate the number of staks in one way
void Stack::calculateNumber()
{
	// X == number width ; y == number of height; z == number of length
	int x;
	int y;
	int z;

	// Calculate the number of width
	x = this->bigBox.GetBigBoxWidth() / this->smallBox.GetSmallBoxWidth();
	// Calculate the number of height
	y = this->bigBox.GetBigBoxHeight() / this->smallBox.GetSmallBoxHeight();
	//Calculate the number of length
	z = this->bigBox.GetBigBoxLength() / this->smallBox.GetSmallBoxLength();

	//Add x to listNumbers
	listNumbers[0] = x;

	//Add y to listNumbers
	listNumbers[1] = y;

	//Add z to listNumbers
	listNumbers[2] = z;

	// Calculate the totalnumber of this stack
	this->number = x*y*z;
}


void Stack::calculateListRestBigBoxes()
{
	//Changed element for x
	double x = this->bigBox.GetBigBoxWidth() - (this->smallBox.GetSmallBoxWidth()* listNumbers[0]);

	//Changed element for y
	double y = this->bigBox.GetBigBoxHeight() - (this->smallBox.GetSmallBoxHeight()* listNumbers[1]);

	//Changed element for z
	double z = this->bigBox.GetBigBoxLength() - (this->smallBox.GetSmallBoxLength()* listNumbers[2]);

	// Proof the x one
	if (prove(x, this->bigBox.GetBigBoxHeight(), this->bigBox.GetBigBoxLength(), this->smallBox))
	{
		// Add the rest box
		this->listRestBigBox.push_back(*new BigBox(x, this->bigBox.GetBigBoxHeight(), this->bigBox.GetBigBoxLength()));
	}
	// Proof the y one
	if (prove(this->bigBox.GetBigBoxWidth(), y, this->bigBox.GetBigBoxLength(), this->smallBox))
	{
		// Add the rest box
		this->listRestBigBox.push_back(*new BigBox(this->bigBox.GetBigBoxWidth(), y, this->bigBox.GetBigBoxLength()));
	}
	// Proof the z one
	if (prove(this->bigBox.GetBigBoxWidth(), this->bigBox.GetBigBoxHeight(), z, this->smallBox))
	{
		// Add the rest box
		this->listRestBigBox.push_back(*new BigBox(this->bigBox.GetBigBoxWidth(), this->bigBox.GetBigBoxHeight(), z));
	}

	// Proof if in the list are 2 restBigBoxes
	if (this->listRestBigBox.size() == 2)
	{
		BigBox bigBoxfront = this->listRestBigBox.front();
		BigBox bigBoxback = this->listRestBigBox.back();
		double cutX;
		double cutY;
		double cutZ;

		if (bigBoxfront.GetBigBoxWidth() == bigBoxback.GetBigBoxWidth())
		{
			if (bigBoxfront.GetBigBoxHeight() > bigBoxback.GetBigBoxHeight())
			{
				cutZ = this->bigBox.GetBigBoxLength() - bigBoxfront.GetBigBoxLength();
				cutY = bigBoxback.GetBigBoxHeight();
				cutX = this->bigBox.GetBigBoxWidth();
				this->listRestBigBox.push_back(*new BigBox(cutX, cutY, cutZ));

				cutZ = bigBoxfront.GetBigBoxLength();
				cutY = this->bigBox.GetBigBoxHeight() - bigBoxback.GetBigBoxHeight();
				this->listRestBigBox.push_back(*new BigBox(cutX, cutY, cutZ));
			}
			else
			{
				cutX = this->bigBox.GetBigBoxWidth();
				cutY = this->bigBox.GetBigBoxHeight() - bigBoxfront.GetBigBoxHeight();
				cutZ = bigBoxback.GetBigBoxLength();
				this->listRestBigBox.push_back(*new BigBox(cutX, cutY, cutZ));

				cutY = bigBoxfront.GetBigBoxHeight();
				cutZ = this->bigBox.GetBigBoxLength() - bigBoxback.GetBigBoxLength();
				this->listRestBigBox.push_back(*new BigBox(cutX, cutY, cutZ));
			}
		}
		else if (bigBoxfront.GetBigBoxWidth() > bigBoxback.GetBigBoxWidth()) {

			if (bigBoxfront.GetBigBoxHeight() == bigBoxback.GetBigBoxHeight())
			{
				cutX = bigBoxback.GetBigBoxWidth();
				cutY = this->bigBox.GetBigBoxHeight();
				cutZ = this->bigBox.GetBigBoxLength() - bigBoxfront.GetBigBoxLength();
				this->listRestBigBox.push_back(*new BigBox(cutX, cutY, cutZ));

				cutX = this->bigBox.GetBigBoxWidth() - bigBoxback.GetBigBoxWidth();
				cutZ = bigBoxfront.GetBigBoxLength();
				this->listRestBigBox.push_back(*new BigBox(cutX, cutY, cutZ));
			}
			else
			{
				cutX = bigBoxback.GetBigBoxWidth();
				cutY = this->bigBox.GetBigBoxHeight() - bigBoxfront.GetBigBoxHeight();
				cutZ = this->bigBox.GetBigBoxLength();
				this->listRestBigBox.push_back(*new BigBox(cutX, cutY, cutZ));

				cutX = this->bigBox.GetBigBoxWidth() - bigBoxback.GetBigBoxWidth();
				cutY = bigBoxfront.GetBigBoxHeight();
				this->listRestBigBox.push_back(*new BigBox(cutX, cutY, cutZ));
			}
		}
		else if (bigBoxfront.GetBigBoxWidth() < bigBoxback.GetBigBoxWidth()) {
			if (bigBoxfront.GetBigBoxHeight() == bigBoxback.GetBigBoxHeight())
			{
				cutX = this->bigBox.GetBigBoxWidth() - bigBoxfront.GetBigBoxWidth();
				cutY = this->bigBox.GetBigBoxHeight();
				cutZ = bigBoxback.GetBigBoxLength();
				this->listRestBigBox.push_back(*new BigBox(cutX, cutY, cutZ));

				cutX = bigBoxfront.GetBigBoxWidth();
				cutZ = this->bigBox.GetBigBoxLength() - bigBoxback.GetBigBoxLength();
				this->listRestBigBox.push_back(*new BigBox(cutX, cutY, cutZ));
			}
			else
			{
				cutX = this->bigBox.GetBigBoxWidth() - bigBoxfront.GetBigBoxWidth();
				cutY = bigBoxback.GetBigBoxHeight();
				cutZ = this->bigBox.GetBigBoxLength();
				this->listRestBigBox.push_back(*new BigBox(cutX, cutY, cutZ));

				cutX = bigBoxfront.GetBigBoxWidth();
				cutY = this->bigBox.GetBigBoxHeight() - bigBoxback.GetBigBoxHeight();
				this->listRestBigBox.push_back(*new BigBox(cutX, cutY, cutZ));
			}
		}
		else {
			std::cout << "Hello";
		}
	}
}

// Proof if a SmallBox fit in a bigBox
bool Stack::prove(double bigBoxWidth, double bigBoxHeight, double bigBoxLength, SmallBox smallBox)
{
	double top = smallBox.GetSmallBoxWidth();
	double middle = smallBox.GetSmallBoxHeight();
	double down = smallBox.GetSmallBoxLength();
	bool test = true;

	// Rearrange the top,middle,down to the right order
	while (test) {
		if (middle > top)
		{
			double tmp = top;
			top = middle;
			middle = tmp;
		}
		else if (down > middle) {
			double tmp = middle;
			middle = down;
			down = tmp;
		}
		else if (down > top) {
			double tmp = top;
			top = down;
			down = tmp;
		}
		else {
			test = false;
		}
	}

	// Proof if a smallBox is stackable in the bigBox
	if (bigBoxWidth >= top && bigBoxHeight >= middle && bigBoxLength >= down ||
		bigBoxWidth >= middle && bigBoxHeight >= top && bigBoxLength >= down ||
		bigBoxWidth >= top && bigBoxHeight >= down && bigBoxLength >= middle ||
		bigBoxWidth >= down && bigBoxHeight >= top && bigBoxLength >= middle ||
		bigBoxWidth >= down && bigBoxHeight >= middle && bigBoxLength >= top ||
		bigBoxWidth >= middle && bigBoxHeight >= down && bigBoxLength >= top) {
		return true;
	}
	return false;
}

Stack::Stack(BigBox bigBox, SmallBox smallBox)
{
	this->bigBox = bigBox;
	this->smallBox = smallBox;
	calculateNumber();
	calculateListRestBigBoxes();
}

int Stack::GetNumber()
{
	return this->number;
}

BigBox Stack::GetBigBox()
{
	return this->bigBox;
}

SmallBox Stack::GetSmallBox()
{
	return this->smallBox;
}

std::list<BigBox> Stack::getListRestBigBox()
{
	return this->listRestBigBox;
}

Stack::~Stack()
{
}
