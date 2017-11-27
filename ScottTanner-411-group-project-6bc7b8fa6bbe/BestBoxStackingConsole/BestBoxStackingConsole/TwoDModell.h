#pragma once
#include <qwidget.h>
class TwoDModell : public QWidget
{
public:
	TwoDModell(QWidget* obj);
	~TwoDModell();
private:
	void paintModel(QPaintEvent*);
};

