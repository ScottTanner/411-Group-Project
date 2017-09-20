#pragma once

#ifndef STACK_H
#define STACK_H
#include <list>

class Stack
{
private:
	BigBox bigBox;
	SmallBox smallBox;
	int listOfDemention [3];
	int totalNumber;
	std::list<BigBox*> listOfRestBoxes;
public:
	Stack();
	Stack(BigBox bigBox, SmallBox smallBox);
	void GetStack();
	void CalculateDemention(BigBox bigBox, SmallBox smallBox);
	void CalculateTotalNumber();
	std::list<BigBox*> CalculateRestBoxes(BigBox bigBox, SmallBox smallBox, int listOfDemention[3]);
	std::list<BigBox*> getListBigBox();
	bool Prove(double bigBoxWidth, double bigBoxHeight, double bigBoxLength, SmallBox smallBox);
	int getTotalNumber();
	BigBox getBigBox();
	SmallBox getSmallBox();

	~Stack();
};


#endif // !STACK_H