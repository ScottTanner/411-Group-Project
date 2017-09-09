#pragma once

#ifndef STACK_H
#define STACK_H

class Stack
{
private:
	BigBox bigBox;
	SmallBox smallBox;
	int listOfDemention [3];
	int totalNumber;
	//list<BigBox> listOfRestBoxes;
	BigBox test[3];
public:
	Stack();
	Stack(BigBox bigBox, SmallBox smallBox);
	void GetStack();
	void CalculateDemention(BigBox bigBox, SmallBox smallBox);
	void CalculateTotalNumber();
	void CalculateRestBoxes(BigBox bigBox, SmallBox smallBox, int listOfDemention[3]);
	~Stack();
};


#endif // !STACK_H