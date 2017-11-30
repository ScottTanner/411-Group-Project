#ifndef UNREDO_H
#define UNREDO_H

#include "Stack.h"
class UnReDo
{
public:
	UnReDo();
	~UnReDo();
	void UnDoValue(double cX,double cY,double cZ, double bX, double bY, double bZ);
	void ReDoValue(double cX, double cY, double cZ, double bX, double bY, double bZ);

	double  UnDoGetCX();
	double  UnDoGetCY();
	double  UnDoGetCZ();

	double  UnDoGetBX();
	double  UnDoGetBY();
	double  UnDoGetBZ();
	void ReDoGet(double cX, double cY, double cZ, double bX, double bY, double bZ);

	double  ReDoGetCX();
	double  ReDoGetCY();
	double  ReDoGetCZ();

	double  ReDoGetBX();
	double  ReDoGetBY();
	double  ReDoGetBZ();
private:
	Stack stackUnDo;
	Stack stackReDo;

};
#endif // !UNREDO_H

