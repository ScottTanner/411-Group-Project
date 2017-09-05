#pragma once
class Stack
{
public:
	Stack();
	Stack(BigBox bigBox);//, SmallBox smallBox);
	//void getStack();
	~Stack();
private:
	BigBox bigBox;
	//SmallBox smallBox;
	//int totalNumber;
	//std::list<BigBox> newBigBoxes;
};

