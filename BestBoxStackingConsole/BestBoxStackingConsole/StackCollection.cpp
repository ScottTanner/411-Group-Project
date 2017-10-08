#include "stdafx.h"
#include "StackCollection.h"


StackCollection::StackCollection()
{
}

StackCollection::StackCollection(double bigBoxWidth, double bigBoxHeight, double bigBoxLength, double smallBoxWidth, double smallBoxHeight, double smallBoxLength)
{
	stacking(*new BigBox(bigBoxWidth, bigBoxHeight, bigBoxLength), *new SmallBox(smallBoxWidth, smallBoxHeight, smallBoxLength));
}


StackCollection::~StackCollection()
{
}

void StackCollection::stacking(BigBox bigBox, SmallBox smallBox)
{
	sixDifferentWays(bigBox, smallBox);
	while (this->queueRestBigBoxes.size() != 0)
	{
		BigBox tmpBigBox = *this->queueRestBigBoxes.begin();
		this->queueRestBigBoxes.pop_front();
		sixDifferentWays(tmpBigBox, smallBox);
	}
	completeStackCollection();

}

void StackCollection::sixDifferentWays(BigBox bigBox, SmallBox smallBox)
{
	// Values of the smallBox
	double smallX = smallBox.GetSmallBoxWidth();
	double smallY = smallBox.GetSmallBoxHeight();
	double smallZ = smallBox.GetSmallBoxLength();

	//Six different ways to lay the smallBoxes in the bigBox
	for (int i = 0; i < 6; i++)
	{
		Stack stack(bigBox, smallBox);
		switch (i)
		{
		case 0:
			// Create a new Stack
			stack = *new Stack(bigBox, *new SmallBox(smallX, smallY, smallZ));

			// Proof if the number is not 0
			if (stack.GetNumber() > 0)
			{
				// Add the stack to the listStack
				listStack.push_back(stack);
				nextRestBigBox(stack);
			}
			break;
		case 1:
			// Create a new Stack
			stack = *new Stack(bigBox, *new SmallBox(smallX, smallZ, smallY));

			// Proof if the number is not 0
			if (stack.GetNumber() > 0)
			{
				// Add the stack to the listStack
				listStack.push_back(stack);
				nextRestBigBox(stack);
			}
			break;
		case 2:
			// Create a new Stack
			stack = *new Stack(bigBox, *new SmallBox(smallY, smallX, smallZ));

			// Proof if the number is not 0
			if (stack.GetNumber() > 0)
			{
				// Add the stack to the listStack
				listStack.push_back(stack);
				nextRestBigBox(stack);
			}
			break;
		case 3:
			// Create a new Stack
			stack = *new Stack(bigBox, *new SmallBox(smallY, smallZ, smallX));

			// Proof if the number is not 0
			if (stack.GetNumber() > 0)
			{
				// Add the stack to the listStack
				listStack.push_back(stack);
				nextRestBigBox(stack);
			}
			break;
		case 4:
			// Create a new Stack
			stack = *new Stack(bigBox, *new SmallBox(smallZ, smallX, smallY));

			// Proof if the number is not 0
			if (stack.GetNumber() > 0)
			{
				// Add the stack to the listStack
				listStack.push_back(stack);
				nextRestBigBox(stack);
			}
			break;
		case 5:
			// Create a new Stack
			Stack stack = *new Stack(bigBox, *new SmallBox(smallZ, smallY, smallX));

			// Proof if the number is not 0
			if (stack.GetNumber() > 0)
			{
				// Add the stack to the listStack
				listStack.push_back(stack);
				nextRestBigBox(stack);
			}
			break;
		}
	}
}

void StackCollection::nextRestBigBox(Stack stack)
{
	// get the list of restBoxes from the actual stack
	std::list<BigBox> tmpList = stack.getListRestBigBox();
	bool check = true;

	// Add all possible Restboxes the listResBigBoxes
	for (std::list<BigBox>::iterator it = tmpList.begin(); it != tmpList.end(); it++)
	{
		check = true;

		// Check if the BigBox is still existing in the listRestBigBoxes
		for (std::list<BigBox>::iterator itList = this->listRestBigBoxes.begin(); itList != this->listRestBigBoxes.end(); itList++)
		{
			if ((*itList).GetBigBoxWidth() == (*it).GetBigBoxWidth() && (*itList).GetBigBoxHeight() == (*it).GetBigBoxHeight() && (*itList).GetBigBoxLength() == (*it).GetBigBoxLength())
			{
				check = false;
			}
		}

		// if check is true then add the actual RestBox to the list and the queue
		if (check == true)
		{
			this->listRestBigBoxes.push_back(*it);
			this->queueRestBigBoxes.push_back(*it);
		}
	}
}

void StackCollection::completeStackCollection()
{
	int countOriginalBB = 0;
	for (std::list<Stack>::iterator itOriginalBB = this->listStack.begin(); itOriginalBB != this->listStack.end(); itOriginalBB++)
	{
		if (++countOriginalBB == 6)
		{
			break;
		}
		std::list<Stack> listStacks;
		int totalNumber = 0;
		Stack firstStack = *itOriginalBB;
		totalNumber += firstStack.GetNumber();
		std::list<BigBox>listRestBB = firstStack.getListRestBigBox();
		listStacks.push_back(firstStack);
		if (listRestBB.size() == 4)
		{
			BigBox arrayRestBigBox[4];
			int count = 0;
			for (std::list<BigBox>::iterator itArray = listRestBB.begin(); itArray != listRestBB.end(); itArray++)
			{
				arrayRestBigBox[count++] = *itArray;
			}
			for (std::list<Stack>::iterator itRestBoxes = this->listStack.begin(); itRestBoxes != this->listStack.end(); itRestBoxes++)
			{
				Stack secondRestBox = *itRestBoxes;

				// First Way to lay the cut
				if (secondRestBox.GetBigBox().GetBigBoxWidth() == arrayRestBigBox[0].GetBigBoxWidth() && secondRestBox.GetBigBox().GetBigBoxHeight() == arrayRestBigBox[0].GetBigBoxHeight() && secondRestBox.GetBigBox().GetBigBoxLength() == arrayRestBigBox[0].GetBigBoxLength())
				{
					listStacks.push_back(secondRestBox);
					totalNumber += secondRestBox.GetNumber();
					for (std::list<Stack>::iterator itThirdRestBox = this->listStack.begin(); itThirdRestBox != this->listStack.end(); itThirdRestBox++)
					{
						Stack thirdRestBox = *itThirdRestBox;
						if (thirdRestBox.GetBigBox().GetBigBoxWidth() == arrayRestBigBox[2].GetBigBoxWidth() && thirdRestBox.GetBigBox().GetBigBoxHeight() == arrayRestBigBox[2].GetBigBoxHeight() && thirdRestBox.GetBigBox().GetBigBoxLength() == arrayRestBigBox[2].GetBigBoxLength())
						{
							totalNumber += thirdRestBox.GetNumber();
							listStacks.push_back(thirdRestBox);
							this->completedStackCollection.push_back(std::make_pair(listStacks, totalNumber));
							listStacks.pop_back();
							totalNumber -= thirdRestBox.GetNumber();
						}
					}
					totalNumber -= secondRestBox.GetNumber();
					listStacks.pop_back();
				}

				// Second way to lay the cut
				if (secondRestBox.GetBigBox().GetBigBoxWidth() == arrayRestBigBox[1].GetBigBoxWidth() && secondRestBox.GetBigBox().GetBigBoxHeight() == arrayRestBigBox[1].GetBigBoxHeight() && secondRestBox.GetBigBox().GetBigBoxLength() == arrayRestBigBox[1].GetBigBoxLength())
				{
					listStacks.push_back(secondRestBox);
					totalNumber += secondRestBox.GetNumber();
					for (std::list<Stack>::iterator itThirdRestBox = this->listStack.begin(); itThirdRestBox != this->listStack.end(); itThirdRestBox++)
					{
						Stack thirdRestBox = *itThirdRestBox;
						if (thirdRestBox.GetBigBox().GetBigBoxWidth() == arrayRestBigBox[3].GetBigBoxWidth() && thirdRestBox.GetBigBox().GetBigBoxHeight() == arrayRestBigBox[3].GetBigBoxHeight() && thirdRestBox.GetBigBox().GetBigBoxLength() == arrayRestBigBox[3].GetBigBoxLength())
						{
							totalNumber += thirdRestBox.GetNumber();
							listStacks.push_back(thirdRestBox);
							this->completedStackCollection.push_back(std::make_pair(listStacks, totalNumber));
							listStacks.pop_back();
							totalNumber -= thirdRestBox.GetNumber();
						}
					}
					totalNumber -= secondRestBox.GetNumber();
					listStacks.pop_back();
				}

			}
		}
		else
		{
			for (std::list<Stack>::iterator itRestBoxes = this->listStack.begin(); itRestBoxes != this->listStack.end(); itRestBoxes++)
			{
				Stack secondStack = *itRestBoxes;
				BigBox firstRestBigBox = firstStack.getListRestBigBox().front();
				BigBox scondStackBigBox = secondStack.GetBigBox();
				if (firstRestBigBox.GetBigBoxWidth() == scondStackBigBox.GetBigBoxWidth() && firstRestBigBox.GetBigBoxHeight() == scondStackBigBox.GetBigBoxHeight() && firstRestBigBox.GetBigBoxLength() == scondStackBigBox.GetBigBoxLength())
				{
					totalNumber += secondStack.GetNumber();
					listStacks.push_back(secondStack);
					this->completedStackCollection.push_back(std::make_pair(listStacks, totalNumber));
					listStacks.pop_back();
					totalNumber -= secondStack.GetNumber();
				}
			}
		}
	}
}
