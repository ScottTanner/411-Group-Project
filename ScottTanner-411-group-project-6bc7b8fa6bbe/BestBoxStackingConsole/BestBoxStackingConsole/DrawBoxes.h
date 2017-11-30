#pragma once
#include <QGraphicsItem>
#include <Stack>
#include "mainwindow.h"
class DrawBoxes
{
public:
	DrawBoxes();
	~DrawBoxes();
	
	//Section 1
	QGraphicsRectItem* drawSection1Layer1OverDraw(Stack stack, QBrush brushOverDraw);
	std::list<QGraphicsRectItem *> drawSection1Layer1Rect(Stack stack, QPen* pen);
	QGraphicsRectItem * drawSection1Layer2OverDraw(Stack stack, QBrush brushOverDraw, double constcX);
	std::list<QGraphicsRectItem *> drawSection1Layer2Rect(Stack stack, QPen* pen, double constcX);
	QGraphicsRectItem * drawSection1Layer3OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcZ, double cRBX, double cRBY, double cRBZ);
	std::list<QGraphicsRectItem *> drawSection1Layer3Rect(Stack stack, QPen* pen, double constcX, double constcZ, double cRBX, double cRBY, double cRBZ);
	QGraphicsRectItem * drawSection1Layer4OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcZ, double cRBX, double cRBY, double cRBZ);
	std::list<QGraphicsRectItem *> drawSection1Layer4Rect(Stack stack, QPen* pen, double constcX, double constcZ, double cRBX, double cRBY, double cRBZ);

	//Section 2

	QGraphicsRectItem* drawSection2Layer1OverDraw(Stack stack, QBrush brushOverDraw);
	std::list<QGraphicsRectItem *> drawSection2Layer1Rect(Stack stack, QPen* pen);
	QGraphicsRectItem * drawSection2Layer2OverDraw(Stack stack, QBrush brushOverDraw, double constcX,double constcZ);
	std::list<QGraphicsRectItem *> drawSection2Layer2Rect(Stack stack, QPen* pen, double constcX,double constcZ);
	QGraphicsRectItem * drawSection2Layer3OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcZ, double cRBX, double cRBY, double cRBZ);
	std::list<QGraphicsRectItem *> drawSection2Layer3Rect(Stack stack, QPen* pen, double constcX, double constcZ, double cRBX, double cRBY, double cRBZ);
	QGraphicsRectItem * drawSection2Layer4OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcZ, double cRBX, double cRBY, double cRBZ);
	std::list<QGraphicsRectItem *> drawSection2Layer4Rect(Stack stack, QPen* pen, double constcX, double constcZ, double cRBX, double cRBY, double cRBZ);

	//Section 3

	QGraphicsRectItem* drawSection3Layer1OverDraw(Stack stack, QBrush brushOverDraw);
	std::list<QGraphicsRectItem *> drawSection3Layer1Rect(Stack stack, QPen* pen);
	QGraphicsRectItem * drawSection3Layer2OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcZ);
	std::list<QGraphicsRectItem *> drawSection3Layer2Rect(Stack stack, QPen* pen, double constcX, double constcZ);
	QGraphicsRectItem * drawSection3Layer3OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);
	std::list<QGraphicsRectItem *> drawSection3Layer3Rect(Stack stack, QPen* pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);
	QGraphicsRectItem * drawSection3Layer4OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);
	std::list<QGraphicsRectItem *> drawSection3Layer4Rect(Stack stack, QPen* pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);

	//Section 4

	QGraphicsRectItem* drawSection4Layer1OverDraw(Stack stack, QBrush brushOverDraw);
	std::list<QGraphicsRectItem *> drawSection4Layer1Rect(Stack stack, QPen* pen);
	QGraphicsRectItem * drawSection4Layer2OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ);
	std::list<QGraphicsRectItem *> drawSection4Layer2Rect(Stack stack, QPen* pen, double constcX, double constcY, double constcZ);
	QGraphicsRectItem * drawSection4Layer3OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);
	std::list<QGraphicsRectItem *> drawSection4Layer3Rect(Stack stack, QPen* pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);
	QGraphicsRectItem * drawSection4Layer4OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);
	std::list<QGraphicsRectItem *> drawSection4Layer4Rect(Stack stack, QPen* pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);

	//Section 5

	QGraphicsRectItem* drawSection5Layer1OverDraw(Stack stack, QBrush brushOverDraw);
	std::list<QGraphicsRectItem *> drawSection5Layer1Rect(Stack stack, QPen* pen);
	QGraphicsRectItem * drawSection5Layer2OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ);
	std::list<QGraphicsRectItem *> drawSection5Layer2Rect(Stack stack, QPen* pen, double constcX, double constcY, double constcZ);
	QGraphicsRectItem * drawSection5Layer3OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);
	std::list<QGraphicsRectItem *> drawSection5Layer3Rect(Stack stack, QPen* pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);
	QGraphicsRectItem * drawSection5Layer4OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);
	std::list<QGraphicsRectItem *> drawSection5Layer4Rect(Stack stack, QPen* pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);

	//Section 6

	QGraphicsRectItem* drawSection6Layer1OverDraw(Stack stack, QBrush brushOverDraw);
	std::list<QGraphicsRectItem *> drawSection6Layer1Rect(Stack stack, QPen* pen);
	QGraphicsRectItem * drawSection6Layer2OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ);
	std::list<QGraphicsRectItem *> drawSection6Layer2Rect(Stack stack, QPen* pen, double constcX, double constcY, double constcZ);
	QGraphicsRectItem * drawSection6Layer3OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);
	std::list<QGraphicsRectItem *> drawSection6Layer3Rect(Stack stack, QPen* pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);
	QGraphicsRectItem * drawSection6Layer4OverDraw(Stack stack, QBrush brushOverDraw, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);
	std::list<QGraphicsRectItem *> drawSection6Layer4Rect(Stack stack, QPen* pen, double constcX, double constcY, double constcZ, double cRBX, double cRBY, double cRBZ);
private:
	QPen* pr;
	QPen* pgr;
	QPen* pblue;
	QBrush bW;
	QGraphicsScene* scene;
};

