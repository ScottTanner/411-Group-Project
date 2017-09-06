#pragma once
#ifndef BigBox_H
#define BigBox_H

class BigBox
{
public:
	BigBox();

	void setBigBoxWidth(double width);
	void setBigBoxHeight(double height);
	void setBigBoxLength(double length);
	double getBigBoxWidth();
	double getBigBoxHeight();
	double getBigBoxLength();
	~BigBox();
private:
	double width;
	double height;
	double length;
};
#endif // !BigBox_H
