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
	std::list<Stack*>GetCollection();
	void nextStacking();
	std::list<std::list<ShowStack*>> combineStacks(std::list<std::list<ShowStack*>> stackedList);
	std::list<std::pair<std::list<ShowStack*>, int>> calculateShowingList();

private:
	std::list<Stack*> collection;
	BigBox bigBox;
	SmallBox smallBox;
	std::list<BigBox*> bigBoxQueue;
	std::list<BigBox*> BigBoxList;
	std::list<Stack*> listShowsStacking;
	std::list<std::pair<std::list<ShowStack*>,int>> showingList;
};

