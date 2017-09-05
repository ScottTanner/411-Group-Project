#pragma once
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

