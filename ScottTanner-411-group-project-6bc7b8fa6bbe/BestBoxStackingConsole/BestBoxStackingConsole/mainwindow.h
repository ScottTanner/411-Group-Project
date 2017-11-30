#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include "StackCollection.h"
#include "UnReDo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
	void set_container(double cX, double cY, double cZ, double boxX, double boxY, double boxZ);
	~MainWindow();	

private slots:
	void on_OneSized_clicked(bool edit= false);
	void on_Exit_clicked();
	void on_TableUpdate();
	void on_Edit_Boxes();
	void on_QActionAbout_Clicked();
	void on_Night_View_clicked();
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
