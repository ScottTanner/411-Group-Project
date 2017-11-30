#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QColorDialog>
#include <QPen>
#include <QBrush>
#include "StackCollection.h"
#include "UnReDo.h"
#include "FormColorSelector.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
	void set_container(double cX, double cY, double cZ, double boxX, double boxY, double boxZ);
	void set_color(QColor boxFirst, QColor boxSecond, QColor boxThird, QColor boxFourth, QColor container, QColor background);
	
	~MainWindow();	

private slots:
	void on_OneSized_clicked(bool edit= false);
	void on_Exit_clicked();
	void on_TableUpdate();
	void on_Edit_Boxes();
	void on_QActionAbout_Clicked();
	void on_Night_View_clicked();
	void on_QAction_Change_Color_2D_Clicked();
	void on_UnDo_Clicked();
	void on_ReDo_Clicked();

private:
    Ui::MainWindow *ui;
	QGraphicsScene *scene;
	double containerX = 0;
	double containerY = 0;
	double containerZ = 0;
	double boxX = 0;
	double boxY = 0;
	double boxZ = 0;
	StackCollection sc;
	QColor smallBoxFirst;
	QColor smallBoxSecond;
	QColor smallBoxThird;
	QColor smallBoxFourth;
	QColor container;
	QColor background;
	QPen boxFirstPen;
	QPen boxSecondPen;
	QPen boxThirdPen;
	QPen boxFourthPen;
	QPen containerPen;
	QBrush allBrush;

	void paintContainers();
	void paintBoxes(std::list<Stack> listStack,double conCX, double conCY, double conCZ);
	void set_Container(double cX, double cY, double cZ, double sBX, double sBY, double sBZ);
	Stack stack1;
	Stack stack2;
	Stack stack3;
	Stack stack4;

	UnReDo unReDo;
};

#endif // MAINWINDOW_H
