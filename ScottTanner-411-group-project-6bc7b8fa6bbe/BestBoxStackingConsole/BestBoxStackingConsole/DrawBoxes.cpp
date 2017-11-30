#include "DrawBoxes.h"



DrawBoxes::DrawBoxes()
{

}


DrawBoxes::~DrawBoxes()
{
}

//Section 1
QGraphicsRectItem* DrawBoxes::drawSection1Layer1OverDraw(Stack stack, QBrush brushOverDraw)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite = new QGraphicsRectItem(20 + cX, 20 + cX + 10 + cY, -(bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem *> DrawBoxes::drawSection1Layer1Rect(Stack stack, QPen* pen)
{
	std::list<QGraphicsRectItem *> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	//Section1
	for (int i = 1; i <= stack.GetListNumbersX(); i++) {
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			QGraphicsRectItem* rect = new QGraphicsRectItem(20 + cX, 20 + cX + 10 + cY, -(bX)*i, -(bY)*j);
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection1Layer2OverDraw(Stack stack, QBrush brushOverDraw,double constcX)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem *rectWhite = new QGraphicsRectItem(20 + cX, 20 + constcX + 10 + cY, -(bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem *> DrawBoxes::drawSection1Layer2Rect(Stack stack, QPen* pen,double constcX)
{
	std::list<QGraphicsRectItem *> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	for (int i = 1; i <= stack.GetListNumbersX(); i++) {
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			QGraphicsRectItem * rect = new QGraphicsRectItem(20 + cX, 20 + constcX + 10 + cY, -(bX)*i, -(bY)*j);
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection1Layer3OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcZ,double cRBX, double cRBY, double cRBZ )
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;


	if (constcZ == cRBZ && constcX == cRBX) {
		QGraphicsRectItem *rectWhite = new QGraphicsRectItem(20 + cX, 20 + constcX + 10 + cRBY + cY, -(bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());
		rectWhite->setBrush(brushOverDraw);
		rectWhite->update();
		return rectWhite;
	}
	else {
		QGraphicsRectItem *rectWhite = new QGraphicsRectItem(20 + constcX, 20 + constcX + 10 + cY, -(bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());
		rectWhite->setBrush(brushOverDraw);
		rectWhite->update();
		return rectWhite;
	}
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection1Layer3Rect(Stack stack, QPen * pen,double constcX, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	for (int i = 1; i <= stack.GetListNumbersX(); i++) {
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			if (constcZ == cRBZ && constcX == cRBX) {
				QGraphicsRectItem *rect = new QGraphicsRectItem(20 + cX, 20 + constcX + 10 + cRBY + cY, -(bX)*i, -(bY)*j);
				rect->setPen(*pen);
				rect->update();
				list.push_back(rect);
			}
			else
			{
				QGraphicsRectItem * rect = new QGraphicsRectItem(20 + constcX, 20 + constcX + 10 + cY, -(bX)*i, -(bY)*j);
				rect->setPen(*pen);
				rect->update();
				list.push_back(rect);
			}
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection1Layer4OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;
	if (constcZ == cRBZ && constcX == cRBX) {
		QGraphicsRectItem *rectWhite = new QGraphicsRectItem(20 + cX, 20 + constcX + 10 + cRBY + cY, -(bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());
		rectWhite->setBrush(brushOverDraw);
		rectWhite->update();
		return rectWhite;
	}
	else {
		QGraphicsRectItem *rectWhite = new QGraphicsRectItem(20 + constcX, 20 + constcX + 10 + cY, -(bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());
		rectWhite->setBrush(brushOverDraw);
		rectWhite->update();
		return rectWhite;
	}
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection1Layer4Rect(Stack stack, QPen * pen, double constcX, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	for (int i = 1; i <= stack.GetListNumbersX(); i++) {
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			if (constcZ == cRBZ && constcX == cRBX) {
				QGraphicsRectItem *rect = new QGraphicsRectItem(20 + cX, 20 + constcX + 10 + cRBY + cY, -(bX)*i, -(bY)*j);
				rect->setPen(*pen);
				rect->update();
				list.push_back(rect);
			}
			else
			{
				QGraphicsRectItem * rect = new QGraphicsRectItem(20 + constcX, 20 + constcX + 10 + cY, -(bX)*i, -(bY)*j);
				rect->setPen(*pen);
				rect->update();
				list.push_back(rect);
			}
		}
	}
	return list;
}

//Section 2
QGraphicsRectItem * DrawBoxes::drawSection2Layer1OverDraw(Stack stack, QBrush brushOverDraw)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem *rectWhite = new QGraphicsRectItem(20 + cX + 10, 20 + cX, (bZ)*stack.GetListNumbersZ(), -(bX)*stack.GetListNumbersX());
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection2Layer1Rect(Stack stack, QPen * pen)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	//Section 2
	for (int i = 1; i <= stack.GetListNumbersZ(); i++)
	{
		for (int j = 1; j <= stack.GetListNumbersX(); j++) {
			QGraphicsRectItem *rect = new QGraphicsRectItem(20 + cX + 10, 20 + cX, (bZ)*i, -(bX)*j);
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection2Layer2OverDraw(Stack stack, QBrush brushOverDraw, double constcX,double constcZ)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + cX, -(bZ)*stack.GetListNumbersZ(), -(bX)*stack.GetListNumbersX());
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection2Layer2Rect(Stack stack, QPen * pen, double constcX, double constcZ)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	for (int i = 1; i <= stack.GetListNumbersZ(); i++) {
		for (int j = 1; j <= stack.GetListNumbersX(); j++) {
			QGraphicsRectItem *rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + cX, -(bZ)*i, -(bX)*j);
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection2Layer3OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;
	QGraphicsRectItem* rectWhite;
	if (constcZ != cRBZ) {
		if (constcX != cRBX) 
		{
			rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ - cRBZ, 20 + constcX - cRBX, -(bZ)*stack.GetListNumbersZ(), (bX)*stack.GetListNumbersX());
		}
		else {
			rectWhite = new QGraphicsRectItem(20 + constcX + 10, 20 + constcX, (bZ)*stack.GetListNumbersZ(), -(bX)*stack.GetListNumbersX());
		}
	}
	else {
		rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX, -(bZ)*stack.GetListNumbersZ(), -(bX)*stack.GetListNumbersX());

	}
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection2Layer3Rect(Stack stack, QPen * pen, double constcX, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	//ToDo: Correct drawing
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rect;
	for (int i = 1; i <= stack.GetListNumbersZ(); i++) {
		for (int j = 1; j <= stack.GetListNumbersX(); j++) {
			if (constcZ != cRBZ)
			{
				if (constcX != cRBX) {
					rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ - cRBZ, 20 + constcX - cRBX, -(bZ)*i, (bX)*j);
				}
				else {
					rect = new QGraphicsRectItem(20 + constcX + 10, 20 + constcX, (bZ)*i, -(bX)*j);
				}
			}
			else {
				rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX, -(bZ)*i, -(bX)*j);
			}
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection2Layer4OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;
	QGraphicsRectItem* rectWhite;
	if (constcX != cX) {

		rectWhite = new QGraphicsRectItem(20 + constcX + 10, 20 + cX, (bZ)*stack.GetListNumbersZ(), -(bX)*stack.GetListNumbersX());

	}
	else {
		rectWhite = new QGraphicsRectItem(20 + constcX + 10 + cZ, 20 + constcX, -(bZ)*stack.GetListNumbersZ(), -(bX)*stack.GetListNumbersX());

	}
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection2Layer4Rect(Stack stack, QPen * pen, double constcX, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rect;
	for (int i = 1; i <= stack.GetListNumbersZ(); i++) {
		for (int j = 1; j <= stack.GetListNumbersX(); j++) {
			if (constcX != cX) {
				rect = new QGraphicsRectItem(20 + constcX + 10, 20 + cX, (bZ)*i, -(bX)*j);
			}
			else {
				rect = new QGraphicsRectItem(20 + constcX + 10 + cZ, 20 + constcX, -(bZ)*i, -(bX)*j);
			}
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}

//Section 3
QGraphicsRectItem * DrawBoxes::drawSection3Layer1OverDraw(Stack stack, QBrush brushOverDraw)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite = new QGraphicsRectItem(20 + cX + 10, 20 + cX + 10 + cY, (bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection3Layer1Rect(Stack stack, QPen * pen)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rect;
	//Section 3
	for (int i = 1; i <= stack.GetListNumbersZ(); i++)
	{
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			rect = new QGraphicsRectItem(20 + cX + 10, 20 + cX + 10 + cY, (bZ)*i, -(bY)*j);
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection3Layer2OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcZ)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem *rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX + 10 + cY, -(bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection3Layer2Rect(Stack stack, QPen * pen, double constcX, double constcZ)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem *rect;
	for (int i = 1; i <= stack.GetListNumbersZ(); i++) {
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX + 10 + cY, -(bZ)*i, -(bY)*j);
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection3Layer3OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY,double constcZ, double cRBX, double cRBY, double cRBZ)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite;
	if (constcZ != cRBZ || constcX != cRBX)
	{
		if (constcX != cRBX) {
			rectWhite = new QGraphicsRectItem(20 + constcX + 10 + cZ, 20 + constcX + 10 + cY, -(bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
		}
		else {
			rectWhite = new QGraphicsRectItem(20 + constcX + 10, 20 + constcX + 10 + cY, (bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
		}

	}
	else
	{
		rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX + 10 + constcY, -(bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
	}
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection3Layer3Rect(Stack stack, QPen * pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rect;
	for (int i = 1; i <= stack.GetListNumbersZ(); i++) {
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			if (constcZ != cRBZ || constcX != cRBX)
			{
				if (constcX != cRBX) {
					rect = new QGraphicsRectItem(20 + constcX + 10 + cZ, 20 + constcX + 10 + cY, -(bZ)*i, -(bY)*j);
				}
				else {
					rect = new QGraphicsRectItem(20 + constcX + 10, 20 + constcX + 10 + cY, (bZ)*i, -(bY)*j);
				}

			}
			else
			{
				rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX + 10 + constcY, -(bZ)*i, -(bY)*j);
			}
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection3Layer4OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite;
	if (constcX != cX)
	{
		rectWhite = new QGraphicsRectItem(20 + constcX + 10, 20 + constcX + 10 + cY + cRBY, (bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
	}
	else
	{
		rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX + 10 + cY + cRBY, -(bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
	}
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection3Layer4Rect(Stack stack, QPen * pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rect;
	for (int i = 1; i <= stack.GetListNumbersZ(); i++) {
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			if (constcX != cX)
			{
				rect = new QGraphicsRectItem(20 + constcX + 10, 20 + constcX + 10 + cY + cRBY, (bZ)*i, -(bY)*j);
			}
			else
			{
				rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX + 10 + cY + cRBY, -(bZ)*i, -(bY)*j);
			}
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}

//Section 4
QGraphicsRectItem * DrawBoxes::drawSection4Layer1OverDraw(Stack stack, QBrush brushOverDraw)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite = new QGraphicsRectItem(20 + cX + 10, 20 + cX + 10 + cY + 10, (bZ)*stack.GetListNumbersZ(), (bX)*stack.GetListNumbersX());
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection4Layer1Rect(Stack stack, QPen * pen)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rect;
	//Secton 4
	for (int i = 1; i <= stack.GetListNumbersZ(); i++)
	{
		for (int j = 1; j <= stack.GetListNumbersX(); j++) {
			rect = new QGraphicsRectItem(20 + cX + 10, 20 + cX + 10 + cY + 10, (bZ)*i, (bX)*j);
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection4Layer2OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY,double constcZ)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX + 10 + constcY + 10 + constcX - cX, -(bZ)*stack.GetListNumbersZ(), (bX)*stack.GetListNumbersX());
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection4Layer2Rect(Stack stack, QPen * pen, double constcX, double constcY, double constcZ)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem * rect;
	for (int i = 1; i <= stack.GetListNumbersZ(); i++) {
		for (int j = 1; j <= stack.GetListNumbersX(); j++) {
			rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX + 10 + constcY + 10 + constcX - cX, -(bZ)*i, (bX)*j);
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection4Layer3OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	//ToDo: Change Drawing
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite;
	if (constcZ != cRBZ || constcX != cRBX)
	{
		if (constcX != cRBX) {
			rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX + 10 + constcY + 10, -(bZ)*stack.GetListNumbersZ(), (bX)*stack.GetListNumbersX());
		}
		else {
			rectWhite = new QGraphicsRectItem(20 + constcX + 10, 20 + constcX + 10 + constcY + 10 + constcX - cX, (bZ)*stack.GetListNumbersZ(), (bX)*stack.GetListNumbersX());
		}
	}
	else {
		if (constcX != cRBX) {
			rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX + 10 + constcY + 10 + constcX - cX, -(bZ)*stack.GetListNumbersZ(), (bX)*stack.GetListNumbersX());
		}
		else {
			rectWhite = new QGraphicsRectItem(20 + constcX + 10 +constcZ, 20 + constcX + 10 + constcY + 10, -(bZ)*stack.GetListNumbersZ(), (bX)*stack.GetListNumbersX());
		}
	}
		rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection4Layer3Rect(Stack stack, QPen * pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	//ToDo: Change Drawing
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rect;
	for (int i = 1; i <= stack.GetListNumbersZ(); i++) {
		for (int j = 1; j <= stack.GetListNumbersX(); j++) {
			if (constcZ != cRBZ || constcX != cRBX)
			{
				if (constcX != cRBX) {
					rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX + 10 + constcY + 10, -(bZ)*i, (bX)*j);
				}
				else {
					rect = new QGraphicsRectItem(20 + constcX + 10, 20 + constcX + 10 + constcY + 10 + constcX - cX, (bZ)*i, (bX)*j);
				}
			}
			else {
				if (constcX != cRBX) {
					rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX + 10 + constcY + 10 + constcX - cX, -(bZ)*i, (bX)*j);
				}
				else {
					rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX + 10 + constcY + 10, -(bZ)*i, (bX)*j);

				}
			}
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection4Layer4OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite;
	if (constcX != cX)
	{
		rectWhite = new QGraphicsRectItem(20 + constcX + 10, 20 + constcX + 10 + constcY + 10 + constcX - cX, (bZ)*stack.GetListNumbersZ(), (bX)*stack.GetListNumbersX());
	}
	else {
		rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX + 10 + constcY + 10, -(bZ)*stack.GetListNumbersZ(), (bX)*stack.GetListNumbersX());
	}
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection4Layer4Rect(Stack stack, QPen * pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rect;
	for (int i = 1; i <= stack.GetListNumbersZ(); i++) {
		for (int j = 1; j <= stack.GetListNumbersX(); j++) {
			if (constcX != cX)
			{
				rect = new QGraphicsRectItem(20 + constcX + 10, 20 + constcX + 10 + constcY + 10 + constcX - cX, (bZ)*i, (bX)*j);
			}
			else {
				rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ, 20 + constcX + 10 + constcY + 10, -(bZ)*i, (bX)*j);
			}
			
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}

//Section 5
QGraphicsRectItem * DrawBoxes::drawSection5Layer1OverDraw(Stack stack, QBrush brushOverDraw)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite = new QGraphicsRectItem(20 + cX + 10 + cZ + 10, 20 + cX + 10 + cY, (bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection5Layer1Rect(Stack stack, QPen * pen)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	//Section 5
	for (int i = 1; i <= stack.GetListNumbersX(); i++)
	{
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			QGraphicsRectItem* rect = new QGraphicsRectItem(20 + cX + 10 + cZ + 10, 20 + cX + 10 + cY, (bX)*i, -(bY)*j);
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection5Layer2OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX - cX, 20 + constcX + 10 + cY, (bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection5Layer2Rect(Stack stack, QPen * pen, double constcX, double constcY, double constcZ)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rect;
	for (int i = 1; i <= stack.GetListNumbersX(); i++) {
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX - cX, 20 + constcX + 10 + cY, (bX)*i, -(bY)*j);
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection5Layer3OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite;
	if (constcZ != cRBZ || constcX != cRBX) 
	{
		if (constcX != cRBX) {
			rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 , 20 + constcX + 10 +cY, (bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());
		}
		else {
			rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10, 20 + constcX + 10 + cY, (bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());

		}
	}
	else {
		if (constcX != cX) {
			rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX, 20 + constcX + 10 + constcY, -(bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());
		}
		else {
			rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10, 20 + constcX + 10 + constcY, (bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());
		}
	}
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection5Layer3Rect(Stack stack, QPen * pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rect;
	for (int i = 1; i <= stack.GetListNumbersX(); i++) {
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			if (constcZ != cRBZ || constcX != cRBX)
			{
				if (constcX != cRBX) {
					rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10, 20 + constcX + 10 + cY, (bX)*i, -(bY)*j);
				}
				else {
					rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10, 20 + constcX + 10 + cY, (bX)*i, -(bY)*j);

				}
			}
			else {
				if (constcX != cX) {
					rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX, 20 + constcX + 10 + constcY, -(bX)*i, -(bY)*j);
				}
				else {
					rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10, 20 + constcX + 10 +  constcY, (bX)*i, -(bY)*j);

				}
			}
				rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection5Layer4OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite;
	if (constcX != cX)
	{
		rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX, 20 + constcX + 10 + cRBY + cY, -(bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());
	}
	else {
		rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10, 20 + constcX + 10 + +cRBY + cY, (bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());
	}
	
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection5Layer4Rect(Stack stack, QPen * pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	std::list<QGraphicsRectItem*> list;
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rect;
	for (int i = 1; i <= stack.GetListNumbersX(); i++) {
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			if (constcX != cX) {
				rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX, 20 + constcX + 10 + cRBY + cY, -(bX)*i, -(bY)*j);
			}
			else {
				rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10, 20 + constcX + 10 + +cRBY + cY, (bX)*i, -(bY)*j);
			}
			
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}

//Section 6
QGraphicsRectItem * DrawBoxes::drawSection6Layer1OverDraw(Stack stack, QBrush brushOverDraw)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite = new QGraphicsRectItem(20 + cX + 10 + cZ + 10 + cX + 10 + cZ, 20 + cX + 10 + cY, -(bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection6Layer1Rect(Stack stack, QPen * pen)
{
	std::list<QGraphicsRectItem*> list;

	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem * rect;
	//Section 6
	for (int i = 1; i <= stack.GetListNumbersZ(); i++)
	{
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			rect = new QGraphicsRectItem(20 + cX + 10 + cZ + 10 + cX + 10 + cZ, 20 + cX + 10 + cY, -(bZ)*i, -(bY)*j);
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection6Layer2OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10, 20 + constcX + 10 + cY, (bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection6Layer2Rect(Stack stack, QPen * pen, double constcX, double constcY, double constcZ)
{
	std::list<QGraphicsRectItem*> list;

	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rect;
	for (int i = 1; i <= stack.GetListNumbersZ(); i++) {
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10, 20 + constcX + 10 + cY, (bZ)*i, -(bY)*j);
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection6Layer3OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite;
	if (constcZ != cRBZ || constcX != cRBX)
	{
		if (constcX != cRBX) {
			rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10, 20 + constcX + 10 + cY, (bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
		}
		else {
			rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10 + constcZ, 20 + constcX + 10 + cY, -(bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());

		}
	}
	else {
		if (constcX != cX) {
			rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10, 20 + constcX + 10 + constcY, (bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
		}
		else {
			rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10, 20 + constcX + 10 + constcY, (bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
		}
	}
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection6Layer3Rect(Stack stack, QPen * pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	std::list<QGraphicsRectItem*> list;

	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rect;
	for (int i = 1; i <= stack.GetListNumbersZ(); i++) {
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			if (constcZ != cRBZ || constcX != cRBX)
			{
				if (constcX != cRBX) {
					rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10, 20 + constcX + 10 + cY, (bZ)*i, -(bY)*j);
				}
				else {
					rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10 + constcZ, 20 + constcX + 10 + cY, -(bZ)*i, -(bY)*j);
				}
			}
			else {
				if (constcX != cX) {
					rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10, 20 + constcX + 10 + constcY, (bZ)*i, -(bY)*j);

				}
				else {
					rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10, 20 + constcX + 10 + constcY, (bZ)*i, -(bY)*j);
				}
			}
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}
QGraphicsRectItem * DrawBoxes::drawSection6Layer4OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite;

	if (constcX != cX) {
		rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10 + constcZ, 20 + constcX + 10 + cRBY + cY, -(bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
	}
	else {
		rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10, 20 + constcX + 10 + cRBY + cY, (bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
	}
	rectWhite->setBrush(brushOverDraw);
	rectWhite->update();
	return rectWhite;
}
std::list<QGraphicsRectItem*> DrawBoxes::drawSection6Layer4Rect(Stack stack, QPen * pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ)
{
	std::list<QGraphicsRectItem*> list;

	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rect;
	for (int i = 1; i <= stack.GetListNumbersZ(); i++) {
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			if (constcX != cX) {
				rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10 + constcZ, 20 + constcX + 10 + cRBY + cY, -(bZ)*i, -(bY)*j);
			}
			else {
				rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10, 20 + constcX + 10 + cRBY + cY, (bZ)*i, -(bY)*j);
			}
			rect->setPen(*pen);
			rect->update();
			list.push_back(rect);
		}
	}
	return list;
}



/*void DrawBoxes::drawSection1Layer2(Stack stack, QGraphicsScene scene, QPen pen, QBrush brushOverDraw)
{
	double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
	double cY = stack.GetBigBox().GetBigBoxHeight() * 20;
	double cZ = stack.GetBigBox().GetBigBoxLength() * 20;

	double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
	double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
	double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

	QGraphicsRectItem* rectWhite = new QGraphicsRectItem(20 + cX, 20 + constcX + 10 + cY, -(bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());
	rectWhite->setBrush(bW);
	rectWhite->update();
	scene->addItem(rectWhite);
	for (int i = 1; i <= stack.GetListNumbersX(); i++) {
		for (int j = 1; j <= stack.GetListNumbersY(); j++) {
			QGraphicsRectItem* rect = new QGraphicsRectItem(20 + cX, 20 + constcX + 10 + cY, -(bX)*i, -(bY)*j);
			rect->setPen(pen);
			rect->update();
			scene->addItem(rect);
		}
	}
}*/
/*
void DrawBoxes::drawSection1Layer3(Stack stack, QGraphicsScene scene, QPen pen, QBrush brushOverDraw)
{
}

void DrawBoxes::drawSection1Layer4(Stack stack, QGraphicsScene scene, QPen pen, QBrush brushOverDraw)
{
}*/
