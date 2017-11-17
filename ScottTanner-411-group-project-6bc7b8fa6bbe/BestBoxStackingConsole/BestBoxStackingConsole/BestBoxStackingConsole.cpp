#include "stdafx.h"
#include "BigBox.h"
#include "SmallBox.h"
#include "Stack.h"
#include "StackCollection.h"
#include"BoxStack2.h"
#include<algorithm>
#include<iostream>
#include<list>

#include"mainwindow.h "
#include <QtWidgets/QApplication>

using namespace std;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BoxStack2 w;
//	StackCollection stackCollection(14, 13, 7, 3, 1.5, 5.5);
	
	int pause;
	
	cin >> pause;
	w.show();
	return a.exec();
	return 0;
}

