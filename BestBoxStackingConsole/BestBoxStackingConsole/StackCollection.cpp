#include "stdafx.h"
#include "StackCollection.h"
#include "Stack.h"
#include "BigBox.h"
#include "SmallBox.h"
#include <list>


StackCollection::StackCollection()
{
}

StackCollection::StackCollection(double bigBoxWidth, double bigBoxHeight, double bigBoxLength, double smallBoxWidth, double smallBoxHeight, double smallBoxLength)
{
	this->bigBox = *new BigBox(bigBoxWidth, bigBoxHeight, bigBoxLength);
	this->smallBox = *new SmallBox(smallBoxWidth, smallBoxHeight, smallBoxLength);
	sixDifferentWays(this->bigBox, this->smallBox);
	this->showingList = calculateShowingList();
}


StackCollection::~StackCollection()
{
}

void StackCollection::sixDifferentWays(BigBox bigBox, SmallBox smallBox)
{
	double sWidth = smallBox.getSmallBoxWidth();
	double sHeight = smallBox.getSmallBoxHeight();
	double sLength = smallBox.getSmallBoxLength();
	Stack* stack = new Stack(bigBox,smallBox);
	for (int i = 0; i < 6; i++) 
	{
		switch (i) 
		{
		case 0:
			stack = new Stack(bigBox, *new SmallBox(sWidth, sHeight, sLength));
			this->collection.push_back(stack);
				break;
		case 1:
			stack = new Stack(bigBox, *new SmallBox(sWidth, sLength, sHeight));
			this->collection.push_back(stack);
			break;
		case 2:
			stack = new Stack(bigBox, *new SmallBox(sHeight,sWidth, sLength));
			this->collection.push_back(stack);
			break;
		case 3:
			stack = new Stack(bigBox, *new SmallBox(sHeight, sLength, sWidth));
			this->collection.push_back(stack);
			break;
		case 4:
			stack = new Stack(bigBox, *new SmallBox(sLength, sWidth, sHeight));
			this->collection.push_back(stack);
			break;
		case 5:
			stack = new Stack(bigBox, *new SmallBox(sLength, sHeight, sWidth));
			this->collection.push_back(stack);
			break;
		}
		bool add = true;;
		std::list<BigBox*> tmpList = stack->getListBigBox();
		for (std::list<BigBox*>::iterator it = tmpList.begin(); it != tmpList.end(); it++)
		{
			for (std::list<BigBox*>::iterator its = BigBoxList.begin(); its != BigBoxList.end(); its++)
			{
				if (**it == **its)
				{
					add = false;
					break;
				}
				else {
					add = true;
				}
			}
			if (add)
			{
				this->BigBoxList.push_back(*it);
				this->bigBoxQueue.push_back(*it);
			}
		}
	}
	for (std::list<Stack*>::iterator it = this->collection.begin(); it != this->collection.end();)
	{
		int check = ((Stack)(**it)).getTotalNumber();
		if (check == 0) 
		{
			this->collection.remove(*it);
			it = this->collection.begin();
		}
		else {
			it++;
		}
	}
	nextStacking();
}


std::list<Stack*> StackCollection::GetCollection()
{
	return this->collection;
}

void StackCollection::nextStacking()
{
	if (this->bigBoxQueue.size() != 0) {
		BigBox* bigBoxs = this->bigBoxQueue.front();
		this->bigBoxQueue.pop_front();
		sixDifferentWays(*bigBoxs, this->smallBox);
	}
}

std::list<std::list<ShowStack*>> StackCollection::combineStacks(std::list<std::list<ShowStack*>> stackedList)
{

	for (std::list<std::list<ShowStack*>>::iterator it = stackedList.begin(); it != stackedList.end(); it++) 
	{
		for (std::list<std::list<ShowStack*>>::iterator it2 = stackedList.begin(); it2 != stackedList.end(); it2++) 
		{
			std::list<ShowStack*> listShowStack1 = *it;
			ShowStack showstack1 = *listShowStack1.back();
			std::list<ShowStack*> listShowStack2 = *it2;
			ShowStack showstack2 = *listShowStack2.front();
			if (showstack1.getBigBox() == showstack2.getBigBox()) 
			{
				listShowStack1.pop_back();
				it = stackedList.begin();
			}
			else
			{
				continue;
			}

		}

	}
	return stackedList;
}

std::list<std::pair<std::list<ShowStack*>, int>> StackCollection::calculateShowingList()
{
	std::list<std::list<ShowStack*>> stackedList;
	for (std::list<Stack*>::iterator it = this->collection.begin(); it != this->collection.end(); it++) 
	{
		std::list<BigBox*> listBigBox = (*it)->getListBigBox();
		for (std::list<BigBox*>::iterator itRest = listBigBox.begin(); itRest != listBigBox.end(); itRest++) 
		{
			BigBox bigBoxElement = **itRest;
			for (std::list<Stack*>::iterator it2 = this->collection.begin(); it2 != this->collection.end(); it2++)
			{
				if (bigBoxElement == (*it2)->getBigBox()) 
				{
					
					ShowStack stack1(**it);
					ShowStack stack2(**it2);
					std::list<ShowStack*> tmp;
					tmp.push_back(&stack1);
					tmp.push_back(&stack2);
					stackedList.push_back(tmp);
				}
			}



		}
	}


	stackedList = combineStacks(stackedList);



	return this->showingList;
}
