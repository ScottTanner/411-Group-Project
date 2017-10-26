#pragma once
class BigBox
{
private:
	double width;
	double height;
	double length;
public:
	BigBox();
	// Create a BigBox
	BigBox(double width, double height, double length);
	~BigBox();
	// Get the width by BigBox
	double GetBigBoxWidth();

	// Get the height by BigBox
	double GetBigBoxHeight();

	// Get the length by BigBox
	double GetBigBoxLength();

	bool operator==(BigBox& bigBox)const;
	bool operator!=(BigBox &bigBox)const;
};

