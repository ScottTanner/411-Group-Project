#pragma once
#include <list>
#include "BigBox.h"
#include "SmallBox.h"
#include "Stack.h"
#include "ShowStack.h"

class StackCollection
{
public:
	StackCollection();
	StackCollection(double bigBoxWidth, double bigBoxHeight, double bigBoxLength, double smallBoxWidth, double smallBoxHeight, double smallBoxLength);
	~StackCollection();
	void sixDifferentWays(BigBox bigBox, SmallBox smallBox);
	std::list<std::list<Stack*>>GetCollection();
	void nextStacking();
	void combineStacks();


private:
	std::list<std::list<Stack*>> collection;
	BigBox bigBox;
	SmallBox smallBox;
	std::list<BigBox*> bigBoxQueue;
	std::list<BigBox*> BigBoxList;
	std::list<std::list<Stack*>> listShowsStacking;
	std::list<std::list<ShowStack*>> showingList;
};
