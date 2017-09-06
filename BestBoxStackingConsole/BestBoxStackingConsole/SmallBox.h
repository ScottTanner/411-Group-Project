#pragma once
#ifndef SMALLBOX_H
#define SMALLBOX_H
class SmallBox
{
public:
	SmallBox(); 
	SmallBox(double width, double height, double length);
	double getSmallBoxWidth();
	double getSmallBoxHeight();
	double getSmallBoxLength();
	~SmallBox();
private:
	double width;
	double height;
	double length;
};
#endif // !SMALLBOX_H
