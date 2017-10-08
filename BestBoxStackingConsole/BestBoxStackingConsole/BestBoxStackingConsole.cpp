#include "stdafx.h"
#include "BigBox.h"
#include "SmallBox.h"
#include "Stack.h"
#include "StackCollection.h"
#include<algorithm>
#include<iostream>
#include<list>

using namespace std;
int main()
{

	StackCollection stackCollection(14,13,7,1.5,3.5,5.5);

	//Create a list of stacks
	list<Stack*> listOfStacks = stackCollection.GetCollection();

	int pause;
	cin >> pause;
    return 0;
}

