#include "UnReDo.h"



UnReDo::UnReDo()
{
}


UnReDo::~UnReDo()
{
}

void UnReDo::UnDoValue(double cX, double cY, double cZ, double bX, double bY, double bZ)
{
	this->stackUnDo = *new Stack(*new BigBox(cX, cY, cZ), *new SmallBox(bX, bY, bZ));
}

void UnReDo::ReDoValue(double cX, double cY, double cZ, double bX, double bY, double bZ)
{
	this->stackReDo = *new Stack(*new BigBox(cX, cY, cZ), *new SmallBox(bX, bY, bZ));
}


double UnReDo::UnDoGetCX()
{
	return this->stackUnDo.GetBigBox().GetBigBoxWidth();
}

double UnReDo::UnDoGetCY()
{
	return this->stackUnDo.GetBigBox().GetBigBoxHeight();
}

double UnReDo::UnDoGetCZ()
{
	return this->stackUnDo.GetBigBox().GetBigBoxLength();
}

double UnReDo::UnDoGetBX()
{
	return this->stackUnDo.GetSmallBox().GetSmallBoxWidth();
}

double UnReDo::UnDoGetBY()
{
	return this->stackUnDo.GetSmallBox().GetSmallBoxHeight();
}

double UnReDo::UnDoGetBZ()
{
	return this->stackUnDo.GetSmallBox().GetSmallBoxLength();
}

void UnReDo::ReDoGet(double cX, double cY, double cZ, double bX, double bY, double bZ)
{
	cX = this->stackReDo.GetBigBox().GetBigBoxWidth();
	cY = this->stackReDo.GetBigBox().GetBigBoxHeight();
	cZ = this->stackReDo.GetBigBox().GetBigBoxLength();

	bX = this->stackReDo.GetSmallBox().GetSmallBoxWidth();
	bY = this->stackReDo.GetSmallBox().GetSmallBoxHeight();
	bZ = this->stackReDo.GetSmallBox().GetSmallBoxLength();

}

double UnReDo::ReDoGetCX()
{
	return this->stackReDo.GetBigBox().GetBigBoxWidth();
}

double UnReDo::ReDoGetCY()
{
	return this->stackReDo.GetBigBox().GetBigBoxHeight();
}

double UnReDo::ReDoGetCZ()
{
	return this->stackReDo.GetBigBox().GetBigBoxLength();
}

double UnReDo::ReDoGetBX()
{
	return this->stackReDo.GetSmallBox().GetSmallBoxWidth();
}

double UnReDo::ReDoGetBY()
{
	return this->stackReDo.GetSmallBox().GetSmallBoxHeight();
}

double UnReDo::ReDoGetBZ()
{
	return this->stackReDo.GetSmallBox().GetSmallBoxLength();
}
