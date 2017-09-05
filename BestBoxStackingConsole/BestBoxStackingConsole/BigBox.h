#pragma once
class BigBox
{
public:
	BigBox();
	BigBox(double width, double height, double length);
	BigBox(const BigBox &obj);
	double getBigBoxWidth();
	double getBigBoxHeight();
	double getBigBoxLength();
	~BigBox();
private:
	double width;
	double height;
	double length;
};

