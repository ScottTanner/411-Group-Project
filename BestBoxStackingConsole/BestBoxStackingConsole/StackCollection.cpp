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
	std::list<Stack*> listStack;
	for (int i = 0; i < 6; i++) 
	{
		switch (i) 
		{
		case 0:
			stack = new Stack(bigBox, *new SmallBox(sWidth, sHeight, sLength));
			listStack.push_back(stack);
				break;
		case 1:
			stack = new Stack(bigBox, *new SmallBox(sWidth, sLength, sHeight));
			listStack.push_back(stack);
			break;
		case 2:
			stack = new Stack(bigBox, *new SmallBox(sHeight,sWidth, sLength));
			listStack.push_back(stack);
			break;
		case 3:
			stack = new Stack(bigBox, *new SmallBox(sHeight, sLength, sWidth));
			listStack.push_back(stack);
			break;
		case 4:
			stack = new Stack(bigBox, *new SmallBox(sLength, sWidth, sHeight));
			listStack.push_back(stack);
			break;
		case 5:
			stack = new Stack(bigBox, *new SmallBox(sLength, sHeight, sWidth));
			listStack.push_back(stack);
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
	for (std::list<Stack*>::iterator it = listStack.begin(); it != listStack.end();)
	{
		int check = ((Stack)(**it)).getTotalNumber();
		if (check == 0) 
		{
			listStack.remove(*it);
			it = listStack.begin();
		}
		else {
			it++;
		}
	}
	this->collection.push_back(listStack);
	nextStacking();
}


std::list<std::list<Stack*>> StackCollection::GetCollection()
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

void StackCollection::combineStacks()
{
	int count=0;
	//for (std::list<Stack*>::iterator it = this->collection.begin(); it != this->collection.end(); it++) 
	//{








		if (count == 5) {
			//break;
		}
		count++;
	//}
}
