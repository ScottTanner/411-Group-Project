#pragma once
#include "Stack.h"
class StackCollection
{
private:
	std::list<Stack> listStack;
	std::list<BigBox> listRestBigBoxes;
	std::list<BigBox> queueRestBigBoxes;
	std::list<std::pair<std::list<Stack>, int>> completedStackCollection;
	void stacking(BigBox bigBox, SmallBox smallBox);
	void sixDifferentWays(BigBox bigBox, SmallBox smallBox);
	void nextRestBigBox(Stack stack);
	void completeStackCollection();
public:
	StackCollection();
	StackCollection(double bigBoxWidth, double bigBoxHeight, double bigBoxLength, double smallBoxWidth, double smallBoxHeight, double smallBoxLength);
	~StackCollection();
};

