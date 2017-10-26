#pragma once
#include "BigBox.h"
#include "SmallBox.h"
#include <list>
class Stack
{
private:
	BigBox bigBox;
	SmallBox smallBox;
	int listNumbers[3];
	int number;
	std::list<BigBox> listRestBigBox;
	void calculateNumber();
	void calculateListRestBigBoxes();
	bool prove(double bigBoxWidth, double bigBoxHeight, double bigBoxLength, SmallBox smallBox);
public:
	Stack(BigBox bigBox, SmallBox smallBox);
	int GetNumber();
	BigBox GetBigBox();
	SmallBox GetSmallBox();
	std::list<BigBox> getListRestBigBox();
	~Stack();

};

