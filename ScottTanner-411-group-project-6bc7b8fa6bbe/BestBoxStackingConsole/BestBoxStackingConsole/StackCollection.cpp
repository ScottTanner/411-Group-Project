#include "stdafx.h"
#include "StackCollection.h"
#include <algorithm> 


std::list<std::pair<std::list<Stack>, int>> StackCollection::GetCompletedStackCollection()
{
	return this->completedStackCollection;
}

StackCollection::StackCollection()
{
}

StackCollection::StackCollection(double bigBoxWidth, double bigBoxHeight, double bigBoxLength, double smallBoxWidth, double smallBoxHeight, double smallBoxLength)
{
	double top = smallBoxWidth;
	double middle = smallBoxHeight;
	double down = smallBoxLength;
	bool test = true;

	// Rearrange the top,middle,down to the right order
	while (test) {
		if (middle > top)
		{
			double tmp = top;
			top = middle;
			middle = tmp;
		}
		else if (down > middle) {
			double tmp = middle;
			middle = down;
			down = tmp;
		}
		else if (down > top) {
			double tmp = top;
			top = down;
			down = tmp;
		}
		else {
			test = false;
		}
	}
	stacking(*new BigBox(bigBoxWidth, bigBoxHeight, bigBoxLength), *new SmallBox(top, down, middle));
	
	// Sort the Collection descending
	completedStackCollection.sort(pairCompareDesc);
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
			stack = *new Stack(bigBox, *new SmallBox(smallZ, smallY, smallX));

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
	int countItFirstStack = 0;

	for (std::list<Stack>::iterator itFirstStack = this->listStack.begin(); itFirstStack != this->listStack.end(); itFirstStack++)
	{
		if (++countItFirstStack == 6)
		{
			break;
		}
		else
		{
			Stack firstStack = *itFirstStack;
			std::list<Stack> tmpStackList;
			int totalNumber = 0;
			tmpStackList.push_back(firstStack);
			totalNumber += firstStack.GetNumber();

			if (firstStack.getListRestBigBox().size() != 0)
			{
				if (firstStack.getListRestBigBox().size() == 4)
				{
					BigBox arrayOfRestBoxes[4];
					int countLoop = 0;
					std::list<BigBox> listRestBigBox = firstStack.getListRestBigBox();
					for (std::list<BigBox>::iterator itFirstStackRestBox = listRestBigBox.begin(); itFirstStackRestBox != listRestBigBox.end(); itFirstStackRestBox++)
					{
						arrayOfRestBoxes[countLoop++] = *itFirstStackRestBox;
					}

					for (std::list<Stack>::iterator itSecondStack = this->listStack.begin(); itSecondStack != this->listStack.end(); itSecondStack++)
					{
						Stack secondStack = *itSecondStack;

						if (arrayOfRestBoxes[0] == secondStack.GetBigBox())
						{
							tmpStackList.push_back(secondStack);
							totalNumber += secondStack.GetNumber();

							if (secondStack.getListRestBigBox().size() != 0)
							{
								for (std::list<Stack>::iterator itSecondStackRestBoxStack = this->listStack.begin(); itSecondStackRestBoxStack != this->listStack.end(); itSecondStackRestBoxStack++)
								{
									Stack RestBoxStack = *itSecondStackRestBoxStack;
									if (secondStack.getListRestBigBox().front() == RestBoxStack.GetBigBox())
									{
										tmpStackList.push_back(RestBoxStack);
										totalNumber += RestBoxStack.GetNumber();

										for (std::list<Stack>::iterator itThirdStack = this->listStack.begin(); itThirdStack != this->listStack.end(); itThirdStack++)
										{
											Stack thirdStack = *itThirdStack;
											if (arrayOfRestBoxes[2] == thirdStack.GetBigBox())
											{
												tmpStackList.push_back(thirdStack);
												totalNumber += thirdStack.GetNumber();

												if (thirdStack.getListRestBigBox().size() != 0)
												{
													for (std::list<Stack>::iterator itThirdStackRestBoxStack = this->listStack.begin(); itThirdStackRestBoxStack != this->listStack.end(); itThirdStackRestBoxStack++)
													{
														Stack RestBoxThird = *itThirdStackRestBoxStack;
														if (thirdStack.getListRestBigBox().front() == RestBoxThird.GetBigBox())
														{
															tmpStackList.push_back(RestBoxThird);
															totalNumber += RestBoxThird.GetNumber();
															this->completedStackCollection.push_back(std::make_pair(tmpStackList, totalNumber));
															totalNumber -= RestBoxThird.GetNumber();
															tmpStackList.pop_back();
														}
													}
												}
												else
												{
													this->completedStackCollection.push_back(std::make_pair(tmpStackList, totalNumber));
												}

												tmpStackList.pop_back();
												totalNumber -= thirdStack.GetNumber();
											}
										}
										tmpStackList.pop_back();
										totalNumber -= RestBoxStack.GetNumber();
									}
								}

							}
							else
							{
								for (std::list<Stack>::iterator itThirdStack = this->listStack.begin(); itThirdStack != this->listStack.end(); itThirdStack++)
								{
									Stack thirdStack = *itThirdStack;
									if (arrayOfRestBoxes[2] == thirdStack.GetBigBox())
									{
										tmpStackList.push_back(thirdStack);
										totalNumber += thirdStack.GetNumber();

										if (thirdStack.getListRestBigBox().size() != 0)
										{
											for (std::list<Stack>::iterator itThirdStackRestBoxStack = this->listStack.begin(); itThirdStackRestBoxStack != this->listStack.end(); itThirdStackRestBoxStack++)
											{
												Stack RestBoxThird = *itThirdStackRestBoxStack;
												if (thirdStack.getListRestBigBox().front() == RestBoxThird.GetBigBox())
												{
													tmpStackList.push_back(RestBoxThird);
													totalNumber += RestBoxThird.GetNumber();
													this->completedStackCollection.push_back(std::make_pair(tmpStackList, totalNumber));
													totalNumber -= RestBoxThird.GetNumber();
													tmpStackList.pop_back();
												}
											}
										}
										else
										{
											this->completedStackCollection.push_back(std::make_pair(tmpStackList, totalNumber));
										}

										tmpStackList.pop_back();
										totalNumber -= thirdStack.GetNumber();
									}
								}
							}
							tmpStackList.pop_back();
							totalNumber -= secondStack.GetNumber();
						}
						else if (arrayOfRestBoxes[1] == secondStack.GetBigBox())
						{
							tmpStackList.push_back(secondStack);
							totalNumber += secondStack.GetNumber();

							if (secondStack.getListRestBigBox().size() != 0)
							{
								for (std::list<Stack>::iterator itSecondStackRestBoxStack = this->listStack.begin(); itSecondStackRestBoxStack != this->listStack.end(); itSecondStackRestBoxStack++)
								{
									Stack RestBoxStack = *itSecondStackRestBoxStack;
									if (secondStack.getListRestBigBox().front() == RestBoxStack.GetBigBox())
									{
										tmpStackList.push_back(RestBoxStack);
										totalNumber += RestBoxStack.GetNumber();

										for (std::list<Stack>::iterator itThirdStack = this->listStack.begin(); itThirdStack != this->listStack.end(); itThirdStack++)
										{
											Stack thirdStack = *itThirdStack;
											if (arrayOfRestBoxes[3] == thirdStack.GetBigBox())
											{
												tmpStackList.push_back(thirdStack);
												totalNumber += thirdStack.GetNumber();

												if (thirdStack.getListRestBigBox().size() != 0)
												{
													for (std::list<Stack>::iterator itThirdStackRestBoxStack = this->listStack.begin(); itThirdStackRestBoxStack != this->listStack.end(); itThirdStackRestBoxStack++)
													{
														Stack RestBoxThird = *itThirdStackRestBoxStack;
														if (thirdStack.getListRestBigBox().front() == RestBoxThird.GetBigBox())
														{
															tmpStackList.push_back(RestBoxThird);
															totalNumber += RestBoxThird.GetNumber();
															this->completedStackCollection.push_back(std::make_pair(tmpStackList, totalNumber));
															totalNumber -= RestBoxThird.GetNumber();
															tmpStackList.pop_back();
														}
													}
												}
												else
												{
													this->completedStackCollection.push_back(std::make_pair(tmpStackList, totalNumber));
												}

												tmpStackList.pop_back();
												totalNumber -= thirdStack.GetNumber();
											}
										}
										tmpStackList.pop_back();
										totalNumber -= RestBoxStack.GetNumber();
									}
								}

							}
							else
							{
								for (std::list<Stack>::iterator itThirdStack = this->listStack.begin(); itThirdStack != this->listStack.end(); itThirdStack++)
								{
									Stack thirdStack = *itThirdStack;
									if (arrayOfRestBoxes[3] == thirdStack.GetBigBox())
									{
										tmpStackList.push_back(thirdStack);
										totalNumber += thirdStack.GetNumber();

										if (thirdStack.getListRestBigBox().size() != 0)
										{
											for (std::list<Stack>::iterator itThirdStackRestBoxStack = this->listStack.begin(); itThirdStackRestBoxStack != this->listStack.end(); itThirdStackRestBoxStack++)
											{
												Stack RestBoxThird = *itThirdStackRestBoxStack;
												if (thirdStack.getListRestBigBox().front() == RestBoxThird.GetBigBox())
												{
													tmpStackList.push_back(RestBoxThird);
													totalNumber += RestBoxThird.GetNumber();
													this->completedStackCollection.push_back(std::make_pair(tmpStackList, totalNumber));
													totalNumber -= RestBoxThird.GetNumber();
													tmpStackList.pop_back();
												}
											}
										}
										else
										{
											this->completedStackCollection.push_back(std::make_pair(tmpStackList, totalNumber));
										}

										tmpStackList.pop_back();
										totalNumber -= thirdStack.GetNumber();
									}
								}
							}

							tmpStackList.pop_back();
							totalNumber -= secondStack.GetNumber();
						}
					}
				}
				else if (firstStack.getListRestBigBox().size() == 1)
				{
					for (std::list<Stack>::iterator itSecondStack = this->listStack.begin(); itSecondStack != this->listStack.end(); itSecondStack++)
					{
						Stack secondStack = *itSecondStack;
						if (firstStack.getListRestBigBox().front() == secondStack.GetBigBox())
						{
							tmpStackList.push_back(secondStack);
							totalNumber += secondStack.GetNumber();

							if (secondStack.getListRestBigBox().size() != 0)
							{
								for (std::list<Stack>::iterator itSecondStackRestBoxStack = this->listStack.begin(); itSecondStackRestBoxStack != this->listStack.end(); itSecondStackRestBoxStack++)
								{
									Stack restBoxStack = *itSecondStackRestBoxStack;

									if (secondStack.getListRestBigBox().front() == restBoxStack.GetBigBox())
									{
										tmpStackList.push_back(restBoxStack);
										totalNumber += restBoxStack.GetNumber();

										this->completedStackCollection.push_back(std::make_pair(tmpStackList, totalNumber));

										tmpStackList.pop_back();
										totalNumber -= restBoxStack.GetNumber();
									}
								}
							}
							else
							{
								this->completedStackCollection.push_back(std::make_pair(tmpStackList, totalNumber));
							}

							tmpStackList.pop_back();
							totalNumber -= secondStack.GetNumber();
						}
					}
				}
			}
		}
	}
}

bool StackCollection::pairCompareDesc(const std::pair<std::list<Stack>, int>& firstItem, const std::pair<std::list<Stack>, int>& secondItem)
{
	return firstItem.second > secondItem.second;
}




