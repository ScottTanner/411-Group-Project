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
	// Counter to get just the first 6 Ways
	int countOriginalBB = 0;

	for (std::list<Stack>::iterator itOriginalBB = this->listStack.begin(); itOriginalBB != this->listStack.end(); itOriginalBB++)
	{
		// Check if the loop was run 6 times and the break up
		if (++countOriginalBB == 6)
		{
			break;
		}

		// The first level of stacking 
		Stack firstStack = *itOriginalBB;

		// Sotre the total number of smallBoxes in the BigBox
		int totalNumber = firstStack.GetNumber();

		// List for storing the First Restboxes that it can be check if there are cuts
		std::list<BigBox>listRestBB = firstStack.getListRestBigBox();

		// List of Stacks for each way
		std::list<Stack> listStacks;
		listStacks.push_back(firstStack);

		// If there are cuts then ther are 4 RestBoxes
		if (listRestBB.size() == 4)
		{
			// Count the steps in the loop for storing the RestBoxes in the array
			int arrayCount = 0;

			// Array of Rest BigBoxes
			BigBox arrayRestBigBox[4];

			for (std::list<BigBox>::iterator itArray = listRestBB.begin(); itArray != listRestBB.end(); itArray++)
			{
				arrayRestBigBox[arrayCount++] = *itArray;
			}

			// Store the second level
			for (std::list<Stack>::iterator itRestBoxes = this->listStack.begin(); itRestBoxes != this->listStack.end(); itRestBoxes++)
			{
				// Stack n the second level
				Stack secondRestBox = *itRestBoxes;

				// First Way to lay the cut
				if (secondRestBox.GetBigBox() == arrayRestBigBox[0])
				{
					// Add the acutal Stack to the list of stack
					listStacks.push_back(secondRestBox);

					// Increase the totalnumber
					totalNumber += secondRestBox.GetNumber();

					if (secondRestBox.getListRestBigBox().size() != 0)
					{
						for (std::list<Stack>::iterator itRestBoxSecond = this->listStack.begin(); itRestBoxSecond != this->listStack.end(); itRestBoxSecond++)
						{
							Stack stackOfRestBoxSecond = *itRestBoxSecond;

							if (secondRestBox.getListRestBigBox().front() == stackOfRestBoxSecond.GetBigBox())
							{
								listStacks.push_back(stackOfRestBoxSecond);
								totalNumber += stackOfRestBoxSecond.GetNumber();

								// Find the cut stacking
								for (std::list<Stack>::iterator itThirdRestBox = this->listStack.begin(); itThirdRestBox != this->listStack.end(); itThirdRestBox++)
								{
									// Stack in the thrid level
									Stack thirdRestBox = *itThirdRestBox;

									if (thirdRestBox.GetBigBox() == arrayRestBigBox[2])
									{
										totalNumber += thirdRestBox.GetNumber();
										listStacks.push_back(thirdRestBox);
										if (thirdRestBox.getListRestBigBox().size() != 0)
										{
											for (std::list<Stack>::iterator itFourthRestBox = this->listStack.begin(); itFourthRestBox != this->listStack.end(); itFourthRestBox++)
											{
												Stack fourthStack = *itFourthRestBox;
												BigBox restBox = thirdRestBox.getListRestBigBox().front();
												if (fourthStack.GetBigBox() == restBox)
												{
													totalNumber += fourthStack.GetNumber();
													listStacks.push_back(fourthStack);
													this->completedStackCollection.push_back(std::make_pair(listStacks, totalNumber));
													listStacks.pop_back();
													totalNumber -= fourthStack.GetNumber();
												}
											}
										}
										else
										{
											this->completedStackCollection.push_back(std::make_pair(listStacks, totalNumber));
										}
										listStacks.pop_back();
										totalNumber -= thirdRestBox.GetNumber();
									}
								}
								listStacks.pop_back();
								totalNumber -= stackOfRestBoxSecond.GetNumber();
							}
						}
					}
					else {

						// Find the cut stacking
						for (std::list<Stack>::iterator itThirdRestBox = this->listStack.begin(); itThirdRestBox != this->listStack.end(); itThirdRestBox++)
						{
							// Stack in the thrid level
							Stack thirdRestBox = *itThirdRestBox;

							if (thirdRestBox.GetBigBox() == arrayRestBigBox[2])
							{
								totalNumber += thirdRestBox.GetNumber();
								listStacks.push_back(thirdRestBox);
								if (thirdRestBox.getListRestBigBox().size() != 0)
								{
									for (std::list<Stack>::iterator itFourthRestBox = this->listStack.begin(); itFourthRestBox != this->listStack.end(); itFourthRestBox++)
									{
										Stack fourthStack = *itFourthRestBox;
										BigBox restBox = thirdRestBox.getListRestBigBox().front();
										if (fourthStack.GetBigBox() == restBox)
										{
											totalNumber += fourthStack.GetNumber();
											listStacks.push_back(fourthStack);
											this->completedStackCollection.push_back(std::make_pair(listStacks, totalNumber));
											listStacks.pop_back();
											totalNumber -= fourthStack.GetNumber();
										}
									}
								}
								else
								{
									this->completedStackCollection.push_back(std::make_pair(listStacks, totalNumber));
								}
								listStacks.pop_back();
								totalNumber -= thirdRestBox.GetNumber();
							}
						}
					}
					totalNumber -= secondRestBox.GetNumber();
					listStacks.pop_back();
				}

				// Second way to lay the cut
				if (secondRestBox.GetBigBox() == arrayRestBigBox[1])
				{
					listStacks.push_back(secondRestBox);
					totalNumber += secondRestBox.GetNumber();

					if (secondRestBox.getListRestBigBox().size() != 0)
					{
						for (std::list<Stack>::iterator itRestBoxSecond = this->listStack.begin(); itRestBoxSecond != this->listStack.end(); itRestBoxSecond++)
						{
							Stack stackOfRestBoxSecond = *itRestBoxSecond;

							if (secondRestBox.getListRestBigBox().front() == stackOfRestBoxSecond.GetBigBox())
							{
								listStacks.push_back(stackOfRestBoxSecond);
								totalNumber += stackOfRestBoxSecond.GetNumber();

								for (std::list<Stack>::iterator itThirdRestBox = this->listStack.begin(); itThirdRestBox != this->listStack.end(); itThirdRestBox++)
								{
									Stack thirdRestBox = *itThirdRestBox;
									if (thirdRestBox.GetBigBox() == arrayRestBigBox[3])
									{
										totalNumber += thirdRestBox.GetNumber();
										listStacks.push_back(thirdRestBox);



										if (thirdRestBox.getListRestBigBox().size() != 0)
										{
											for (std::list<Stack>::iterator itFourthRestBox = this->listStack.begin(); itFourthRestBox != this->listStack.end(); itFourthRestBox++)
											{
												Stack fourthStack = *itFourthRestBox;
												BigBox restBox = thirdRestBox.getListRestBigBox().front();
												if (fourthStack.GetBigBox() == restBox)
												{
													totalNumber += fourthStack.GetNumber();
													listStacks.push_back(fourthStack);
													this->completedStackCollection.push_back(std::make_pair(listStacks, totalNumber));
													listStacks.pop_back();
													totalNumber -= fourthStack.GetNumber();
												}
											}
										}
										else
										{
											this->completedStackCollection.push_back(std::make_pair(listStacks, totalNumber));
										}
										listStacks.pop_back();
										totalNumber -= thirdRestBox.GetNumber();
									}
								}
							}
						}
					}
					else {

						for (std::list<Stack>::iterator itThirdRestBox = this->listStack.begin(); itThirdRestBox != this->listStack.end(); itThirdRestBox++)
						{
							Stack thirdRestBox = *itThirdRestBox;
							if (thirdRestBox.GetBigBox() == arrayRestBigBox[3])
							{
								totalNumber += thirdRestBox.GetNumber();
								listStacks.push_back(thirdRestBox);



								if (thirdRestBox.getListRestBigBox().size() != 0)
								{
									for (std::list<Stack>::iterator itFourthRestBox = this->listStack.begin(); itFourthRestBox != this->listStack.end(); itFourthRestBox++)
									{
										Stack fourthStack = *itFourthRestBox;
										BigBox restBox = thirdRestBox.getListRestBigBox().front();
										if (fourthStack.GetBigBox() == restBox)
										{
											totalNumber += fourthStack.GetNumber();
											listStacks.push_back(fourthStack);
											this->completedStackCollection.push_back(std::make_pair(listStacks, totalNumber));
											listStacks.pop_back();
											totalNumber -= fourthStack.GetNumber();
										}
									}
								}
								else
								{
									this->completedStackCollection.push_back(std::make_pair(listStacks, totalNumber));
								}
								listStacks.pop_back();
								totalNumber -= thirdRestBox.GetNumber();
							}
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
				if (firstStack.getListRestBigBox().size() != 0) {
					BigBox firstRestBigBox = firstStack.getListRestBigBox().front();
					BigBox scondStackBigBox = secondStack.GetBigBox();
					if (firstRestBigBox == scondStackBigBox)
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
}
