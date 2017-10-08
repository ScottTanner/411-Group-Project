#pragma once
class SmallBox
{
private:
	double width;
	double length;
	double height;
public:
	SmallBox();
	SmallBox(double width, double height, double length);
	~SmallBox();

	// Get width by SmallBox
	double GetSmallBoxWidth();

	//Get height by SmallBox
	double GetSmallBoxHeight();

	//Get length by SmallBox
	double GetSmallBoxLength();
};

