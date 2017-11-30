#include "OneSizedAlgorithm.h"
#include "mainwindow.h"
#include "ui_boxstacking.h"
#include <algorithm>
#include "DialogAbout.h"
#include "FormColorSelector.h"
#include "DrawBoxes.h"
bool styleControl = true;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	this->showMaximized();
	connect(ui->actionOne_Sized_Small_Boxes, &QAction::triggered, this, &MainWindow::on_OneSized_clicked);
	connect(ui->actionExit, &QAction::triggered, this, &MainWindow::on_Exit_clicked);
	connect(ui->actionEdit_Boxes, &QAction::triggered, this, &MainWindow::on_Edit_Boxes);
	connect(ui->actionAbout_BestBoxStacking, &QAction::triggered, this, &MainWindow::on_QActionAbout_Clicked);
	connect(ui->action_ber_BestBoxStacking, &QAction::triggered, this, &MainWindow::on_QActionAbout_Clicked);
	connect(ui->listWidget_Result, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(on_TableUpdate()));
	connect(ui->actionChange_Color_2D, &QAction::triggered, this, &MainWindow::on_QAction_Change_Color_2D_Clicked);
}

void MainWindow::set_container(double cX, double cY, double cZ, double boxX, double boxY, double boxZ)
{
	this->containerX = cX;
	this->containerY = cY;
	this->containerZ = cZ;
	
	this->boxX = boxX;
	this->boxY = boxY;
	this->boxZ = boxZ;
	
	ui->lineEdit_SmallBoxWidth->setText(QString::number(this->boxX));
	ui->lineEdit_SmallBoxHeight->setText(QString::number(this->boxY));
	ui->lineEdit_SmallBoxLength->setText(QString::number(this->boxZ));
	
	ui->lineEdit_ContainerWidth->setText(QString::number(this->containerX));
	ui->lineEdit_ContainerHeight->setText(QString::number(this->containerY));
	ui->lineEdit_ContainerLength->setText(QString::number(this->containerZ));
}

void MainWindow::set_color(QColor smallBoxFirst, QColor smallBoxSecond, QColor smallBoxThird, QColor smallBoxFourth, QColor container, QColor background)
{
	this->smallBoxFirst = smallBoxFirst;
	this->smallBoxSecond = smallBoxSecond;
	this->smallBoxThird = smallBoxSecond;
	this->smallBoxFourth = smallBoxSecond;
	this->container = container;
	this->background = background;

	//set styles for pens
	this->boxFirstPen.setStyle(Qt::SolidLine);
	this->boxSecondPen.setStyle(Qt::SolidLine);
	this->boxThirdPen.setStyle(Qt::SolidLine);
	this->boxFourthPen.setStyle(Qt::SolidLine);
	this->containerPen.setStyle(Qt::SolidLine);

	//set color for brushes
	this->boxFirstPen.setColor(this->smallBoxFirst);
	this->boxSecondPen.setColor(this->smallBoxSecond);
	this->boxThirdPen.setColor(this->smallBoxThird);
	this->boxFourthPen.setColor(this->smallBoxFourth);
	this->containerPen.setColor(this->container);
	
	this->allBrush.setStyle(Qt::SolidPattern);
	this->allBrush.setColor(Qt::white);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Exit_clicked()
{
	close();
}

void MainWindow::on_TableUpdate()
{
	ui->pushButton_SaveValues->setEnabled(1);
	// Delete all rows in the table
	int rows = this->ui->tableWidget_ShowStacks->rowCount();
	for (int i = 0; i <rows; i++) {
		this->ui->tableWidget_ShowStacks->removeRow(0);
	}

	std::list<std::pair<std::list<Stack>, int>> listSC = this->sc.GetCompletedStackCollection();
	int currentItem = this->ui->listWidget_Result->currentRow();
	int count = 0;
	std::list<Stack> listStack;
	for (std::list<std::pair<std::list<Stack>, int>>::iterator itList = listSC.begin(); itList != listSC.end(); itList++)
	{
		if (currentItem == count)
		{
			listStack = (*itList).first;
			int countItem = 0;
			for (std::list<Stack>::iterator itListStack = listStack.begin(); itListStack != listStack.end(); itListStack++)
			{
				this->ui->tableWidget_ShowStacks->insertRow(countItem);
				Stack stack = *itListStack;
				QString bigBox(QString::number(stack.GetBigBox().GetBigBoxWidth()) + " , " + QString::number(stack.GetBigBox().GetBigBoxHeight()) + " , " + QString::number(stack.GetBigBox().GetBigBoxLength()));
				QString smallBox(QString::number(stack.GetSmallBox().GetSmallBoxWidth()) + " , " + QString::number(stack.GetSmallBox().GetSmallBoxHeight()) + " , " + QString::number(stack.GetSmallBox().GetSmallBoxLength()));
				QString number(QString::number(stack.GetNumber()));
				this->ui->tableWidget_ShowStacks->setItem(countItem, 0, new QTableWidgetItem(bigBox));
				this->ui->tableWidget_ShowStacks->setItem(countItem, 1, new QTableWidgetItem(smallBox));
				this->ui->tableWidget_ShowStacks->setItem(countItem, 2, new QTableWidgetItem(number));
				countItem++;
			}
			this->ui->tableWidget_ShowStacks->show();

			paintContainers();
			paintBoxes(listStack,this->containerX,this->containerY,this->containerZ);

			break;
		}
		else {
			count++;
		}
	}
}

void MainWindow::on_Edit_Boxes()
{
	on_OneSized_clicked(true);
}

void MainWindow::on_QActionAbout_Clicked()
{
	DialogAbout about;
	about.setModal(true);
	about.exec();
}

void MainWindow::on_QAction_Change_Color_2D_Clicked()
{

	FormColorSelector colorSelector;
	colorSelector.setModal(true);
	colorSelector.exec();
	set_color(colorSelector.get_smallBoxFirst(), colorSelector.get_smallBoxSecond(), colorSelector.get_smallBoxThird(), colorSelector.get_smallBoxFourth(), colorSelector.get_container(), colorSelector.get_backGround());
}


void MainWindow::paintContainers()
{
	this->scene = new QGraphicsScene(0, 0, this->ui->graphicsView_TwoDim->width(), this->ui->graphicsView_TwoDim->height(), this->ui->graphicsView_TwoDim);
	this->scene->setBackgroundBrush(this->background);

	this->ui->graphicsView_TwoDim->setScene(this->scene);
	double x = this->containerX * 20;
	double y = this->containerY * 20;
	double z = this->containerZ * 20;
	QGraphicsRectItem* rect1 = new QGraphicsRectItem(19, 19 + x+1 + 9, x+2, y+2);
	scene->addItem(rect1);
	QGraphicsRectItem* rect2 = new QGraphicsRectItem(19 + x+1 + 9, 19, z+2, x+2);
	scene->addItem(rect2);
	QGraphicsRectItem* rect3 = new QGraphicsRectItem(19 + x+1 + 9, 19 + x+1 + 9, z+2, y+2);
	scene->addItem(rect3);
	QGraphicsRectItem* rect4 = new QGraphicsRectItem(19 + x+1 + 9, 19 + x+1 + 9 + y+1 + 9, z+2, x+2);
	scene->addItem(rect4);
	QGraphicsRectItem* rect5 = new QGraphicsRectItem(19 + x+1 + 9 + z+1 + 9, 19 + x+1 + 9, x+2, y+2);
	scene->addItem(rect5);
	QGraphicsRectItem* rect6 = new QGraphicsRectItem(19 + x+1 + 9 + z+1 + 9 + x+1 + 9, 19 + x+1 + 9, z+2, y+2);
	scene->addItem(rect6);
}

void MainWindow::paintBoxes(std::list<Stack> listStack, double conCX,double conCY,double conCZ)
{
	QPen pr = this->boxFirstPen;
	QPen pgr = this->boxSecondPen;
	QPen pblue = this->boxThirdPen;
	QPen pm = this->boxFourthPen;
	QBrush bW = this->allBrush;

	int count = 0;
	int constcX = conCX*20;
	int constcY = conCY * 20;
	int constcZ = conCZ * 20;

	

	int listStackSize = listStack.size();
	double cX;
	double cY;
	double cZ;
	double bX;
	double bY;
	double bZ;
	double cRBX;
	double cRBY;
	double cRBZ;
	int countStack = 0;
	for (Stack stack : listStack) 
	{
		if (countStack++ == 1) {
			cRBX = stack.GetBigBox().GetBigBoxWidth() * 20;
			cRBY = stack.GetBigBox().GetBigBoxHeight() * 20;
			cRBZ = stack.GetBigBox().GetBigBoxLength() * 20;
		}
	}
	//std::reverse(listStack.begin(), listStack.end());
	QGraphicsRectItem* rectWhite;
	QGraphicsRectItem* rectWhite1;
	QGraphicsRectItem* rectWhite2;
	QGraphicsRectItem* rectWhite3;
	QGraphicsRectItem* rectWhite4;

	QGraphicsRectItem* rect;
	QGraphicsRectItem* rect1;
	QGraphicsRectItem* rect2;
	QGraphicsRectItem* rect3;
	QGraphicsRectItem* rect4;


	bool different;
	int countStacks=0;

	for (Stack stack : listStack)
	{
		switch (countStacks++) 
		{
		case 0:
			this->stack1 = stack;
			continue;
		case 1:
			this->stack2 = stack;
			continue;
		case 2:
			this->stack3 = stack;
			continue;
		case 3:
			this->stack4 = stack;
			continue;
		}
	}
	std::reverse(listStack.begin(), listStack.end());
	DrawBoxes box;
	std::list<QGraphicsRectItem *> listItems;
	//Section Layer desicion
	switch (listStack.size()) 
	{
	case 1:
		//Section 6
		this->scene->addItem(box.drawSection6Layer1OverDraw(stack1, bW));
		listItems = box.drawSection6Layer1Rect(stack1, &pr);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		//Section 5
		this->scene->addItem(box.drawSection5Layer1OverDraw(stack1, bW));
		listItems = box.drawSection5Layer1Rect(stack1, &pr);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		//Section 4
		this->scene->addItem(box.drawSection4Layer1OverDraw(stack1, bW));
		listItems = box.drawSection4Layer1Rect(stack1, &pr);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		//Section 3
		this->scene->addItem(box.drawSection3Layer1OverDraw(stack1, bW));
		listItems = box.drawSection3Layer1Rect(stack1, &pr);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();
		//Section 2
		this->scene->addItem(box.drawSection2Layer1OverDraw(stack1, bW));
		listItems = box.drawSection2Layer1Rect(stack1, &pr);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		//Section 1
		this->scene->addItem(box.drawSection1Layer1OverDraw(stack1,bW));
		listItems = box.drawSection1Layer1Rect(stack1, &pr);
		for (QGraphicsRectItem * item : listItems) {
			this->scene->addItem(item);
		}
		listItems.clear();
		break;
	case 2:
		//Section 6
		this->scene->addItem(box.drawSection6Layer1OverDraw(stack1, bW));
		listItems = box.drawSection6Layer1Rect(stack1, &pr);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		this->scene->addItem(box.drawSection6Layer2OverDraw(stack2, bW,constcX,constcY,constcZ));
		listItems = box.drawSection6Layer2Rect(stack2, &pgr, constcX, constcY, constcZ);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		//Section 5
		this->scene->addItem(box.drawSection5Layer1OverDraw(stack1, bW));
		listItems = box.drawSection5Layer1Rect(stack1, &pr);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		this->scene->addItem(box.drawSection5Layer2OverDraw(stack2, bW,constcX,constcY,constcZ));
		listItems = box.drawSection5Layer2Rect(stack2, &pgr, constcX, constcY, constcZ);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		//Section 4
		this->scene->addItem(box.drawSection4Layer1OverDraw(stack1, bW));
		listItems = box.drawSection4Layer1Rect(stack1, &pr);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		this->scene->addItem(box.drawSection4Layer2OverDraw(stack2, bW,constcX,constcY,constcZ));
		listItems = box.drawSection4Layer2Rect(stack2, &pgr, constcX, constcY, constcZ);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		//Section 3
		this->scene->addItem(box.drawSection3Layer2OverDraw(stack2, bW,constcX,constcZ));
		listItems = box.drawSection3Layer2Rect(stack2, &pgr, constcX, constcZ);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		this->scene->addItem(box.drawSection3Layer1OverDraw(stack1, bW));
		listItems = box.drawSection3Layer1Rect(stack1, &pr);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		//Section 2
		this->scene->addItem(box.drawSection2Layer2OverDraw(stack2, bW,constcX,constcZ));
		listItems = box.drawSection2Layer2Rect(stack2, &pgr, constcX, constcZ);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		this->scene->addItem(box.drawSection2Layer1OverDraw(stack1, bW));
		listItems = box.drawSection2Layer1Rect(stack1, &pr);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		//Section 1
		this->scene->addItem(box.drawSection1Layer2OverDraw(stack2, bW, constcX));
		listItems = box.drawSection1Layer2Rect(stack2, &pgr, constcX);
		for (QGraphicsRectItem * item : listItems) {
			this->scene->addItem(item);
		}
		listItems.clear();

		this->scene->addItem(box.drawSection1Layer1OverDraw(stack1, bW));
		listItems = box.drawSection1Layer1Rect(stack1, &pr);
		for (QGraphicsRectItem * item : listItems) {
			this->scene->addItem(item);
		}
		listItems.clear();

		break;
	case 3:
		different = false;
		countStacks = 1;
		for (Stack stack : listStack) 
		{
			if (countStacks != listStack.size() && stack.GetBigBox().GetBigBoxLength() != constcZ) 
			{
				different = true;
			}
			else if(countStacks != listStack.size() && stack.GetBigBox().GetBigBoxLength() == constcZ){
				different = false;
			}
			countStacks++;
		}
		if (different == true) 
		{
			//Section 6
			this->scene->addItem(box.drawSection6Layer1OverDraw(stack1, bW));
			listItems = box.drawSection6Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection6Layer3OverDraw(stack3, bW, constcX, constcY, constcZ,cRBX,cRBY,cRBZ));
			listItems = box.drawSection6Layer3Rect(stack3, &pblue, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection6Layer2OverDraw(stack2, bW, constcX, constcY, constcZ));
			listItems = box.drawSection6Layer2Rect(stack2, &pgr, constcX, constcY, constcZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			//Section 5
			this->scene->addItem(box.drawSection5Layer1OverDraw(stack1, bW));
			listItems = box.drawSection5Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection5Layer3OverDraw(stack3, bW, constcX, constcY, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection5Layer3Rect(stack3, &pblue, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection5Layer2OverDraw(stack2, bW, constcX, constcY, constcZ));
			listItems = box.drawSection5Layer2Rect(stack2, &pgr, constcX, constcY, constcZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();
			
			//Section 4
			this->scene->addItem(box.drawSection4Layer1OverDraw(stack1, bW));
			listItems = box.drawSection4Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection4Layer3OverDraw(stack3, bW, constcX, constcY, constcZ,cRBX,cRBY,cRBZ));
			listItems = box.drawSection4Layer3Rect(stack3, &pblue, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection4Layer2OverDraw(stack2, bW, constcX, constcY, constcZ));
			listItems = box.drawSection4Layer2Rect(stack2, &pgr, constcX, constcY, constcZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			//Section 3
			this->scene->addItem(box.drawSection3Layer2OverDraw(stack2, bW, constcX, constcZ));
			listItems = box.drawSection3Layer2Rect(stack2, &pgr, constcX, constcZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection3Layer3OverDraw(stack3, bW, constcX, constcY, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection3Layer3Rect(stack3, &pblue, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection3Layer1OverDraw(stack1, bW));
			listItems = box.drawSection3Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			//Section2

			this->scene->addItem(box.drawSection2Layer2OverDraw(stack2, bW, constcX, constcZ));
			listItems = box.drawSection2Layer2Rect(stack2, &pgr, constcX, constcZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection2Layer3OverDraw(stack3, bW, constcX, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection2Layer3Rect(stack3, &pblue, constcX, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection2Layer1OverDraw(stack1, bW));
			listItems = box.drawSection2Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			//Section 1
			this->scene->addItem(box.drawSection1Layer2OverDraw(stack2, bW, constcX));
			listItems = box.drawSection1Layer2Rect(stack2, &pgr, constcX);
			for (QGraphicsRectItem * item : listItems) {
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection1Layer3OverDraw(stack3, bW, constcX, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection1Layer3Rect(stack3, &pblue, constcX, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection1Layer1OverDraw(stack1, bW));
			listItems = box.drawSection1Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem * item : listItems) {
				this->scene->addItem(item);
			}
			listItems.clear();
		}
		else {
			//Section 6
			this->scene->addItem(box.drawSection6Layer1OverDraw(stack1, bW));
			listItems = box.drawSection6Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection6Layer2OverDraw(stack2, bW, constcX, constcY, constcZ));
			listItems = box.drawSection6Layer2Rect(stack2, &pgr, constcX, constcY, constcZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection6Layer3OverDraw(stack3, bW, constcX, constcY, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection6Layer3Rect(stack3, &pblue, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			//Section 5
			this->scene->addItem(box.drawSection5Layer1OverDraw(stack1, bW));
			listItems = box.drawSection5Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection5Layer2OverDraw(stack2, bW, constcX, constcY, constcZ));
			listItems = box.drawSection5Layer2Rect(stack2, &pgr, constcX, constcY, constcZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection5Layer3OverDraw(stack3, bW, constcX, constcY, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection5Layer3Rect(stack3, &pblue, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			//Section 4
			this->scene->addItem(box.drawSection4Layer1OverDraw(stack1, bW));
			listItems = box.drawSection4Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection4Layer2OverDraw(stack2, bW, constcX, constcY, constcZ));
			listItems = box.drawSection4Layer2Rect(stack2, &pgr, constcX, constcY, constcZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection4Layer3OverDraw(stack3, bW, constcX, constcY, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection4Layer3Rect(stack3, &pblue, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			//Section 3
			this->scene->addItem(box.drawSection3Layer3OverDraw(stack3, bW, constcX, constcY, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection3Layer3Rect(stack3, &pblue, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection3Layer2OverDraw(stack2, bW, constcX, constcZ));
			listItems = box.drawSection3Layer2Rect(stack2, &pgr, constcX, constcZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection3Layer1OverDraw(stack1, bW));
			listItems = box.drawSection3Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			//Section2
			this->scene->addItem(box.drawSection2Layer3OverDraw(stack3, bW, constcX, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection2Layer3Rect(stack3, &pblue, constcX, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection2Layer2OverDraw(stack2, bW, constcX, constcZ));
			listItems = box.drawSection2Layer2Rect(stack2, &pgr, constcX, constcZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection2Layer1OverDraw(stack1, bW));
			listItems = box.drawSection2Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			//Section 1
			this->scene->addItem(box.drawSection1Layer3OverDraw(stack3, bW, constcX, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection1Layer3Rect(stack3, &pblue, constcX, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem * item : listItems) {
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection1Layer2OverDraw(stack2, bW, constcX));
			listItems = box.drawSection1Layer2Rect(stack2, &pgr, constcX);
			for (QGraphicsRectItem * item : listItems) {
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection1Layer1OverDraw(stack1, bW));
			listItems = box.drawSection1Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem * item : listItems) {
				this->scene->addItem(item);
			}
			listItems.clear();
		}
		break;
	case 4:
		countStacks = 1;
		//Section 6
		this->scene->addItem(box.drawSection6Layer1OverDraw(stack1, bW));
		listItems = box.drawSection6Layer1Rect(stack1, &pr);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		this->scene->addItem(box.drawSection6Layer4OverDraw(stack4, bW, constcX, constcY, constcZ, cRBX, cRBY, cRBZ));
		listItems = box.drawSection6Layer4Rect(stack4, &pm, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		this->scene->addItem(box.drawSection6Layer3OverDraw(stack3, bW, constcX, constcY, constcZ, cRBX, cRBY, cRBZ));
		listItems = box.drawSection6Layer3Rect(stack3, &pblue, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		this->scene->addItem(box.drawSection6Layer2OverDraw(stack2, bW, constcX, constcY, constcZ));
		listItems = box.drawSection6Layer2Rect(stack2, &pgr, constcX, constcY, constcZ);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		//Section 5
		this->scene->addItem(box.drawSection5Layer1OverDraw(stack1, bW));
		listItems = box.drawSection5Layer1Rect(stack1, &pr);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		this->scene->addItem(box.drawSection5Layer4OverDraw(stack4, bW, constcX, constcY, constcZ, cRBX, cRBY, cRBZ));
		listItems = box.drawSection5Layer4Rect(stack4, &pm, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		this->scene->addItem(box.drawSection5Layer3OverDraw(stack3, bW, constcX, constcY, constcZ, cRBX, cRBY, cRBZ));
		listItems = box.drawSection5Layer3Rect(stack3, &pblue, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();

		this->scene->addItem(box.drawSection5Layer2OverDraw(stack2, bW, constcX, constcY, constcZ));
		listItems = box.drawSection5Layer2Rect(stack2, &pgr, constcX, constcY, constcZ);
		for (QGraphicsRectItem* item : listItems)
		{
			this->scene->addItem(item);
		}
		listItems.clear();
	
			//Section 4
			this->scene->addItem(box.drawSection4Layer1OverDraw(stack1, bW));
			listItems = box.drawSection4Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection4Layer3OverDraw(stack3, bW, constcX, constcY, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection4Layer3Rect(stack3, &pblue, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection4Layer4OverDraw(stack4, bW, constcX, constcY, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection4Layer4Rect(stack4, &pm, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection4Layer2OverDraw(stack2, bW, constcX, constcY, constcZ));
			listItems = box.drawSection4Layer2Rect(stack2, &pgr, constcX, constcY, constcZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();
			
			//Section 3

			this->scene->addItem(box.drawSection3Layer2OverDraw(stack2, bW, constcX, constcZ));
			listItems = box.drawSection3Layer2Rect(stack2, &pgr, constcX, constcZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection3Layer4OverDraw(stack4, bW, constcX, constcY, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection3Layer4Rect(stack4, &pm, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection3Layer3OverDraw(stack3, bW, constcX, constcY, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection3Layer3Rect(stack3, &pblue, constcX, constcY, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection3Layer1OverDraw(stack1, bW));
			listItems = box.drawSection3Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();
			
			//Section2

			this->scene->addItem(box.drawSection2Layer2OverDraw(stack2, bW, constcX, constcZ));
			listItems = box.drawSection2Layer2Rect(stack2, &pgr, constcX, constcZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection2Layer4OverDraw(stack4, bW, constcX, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection2Layer4Rect(stack4, &pm, constcX, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection2Layer3OverDraw(stack3, bW, constcX, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection2Layer3Rect(stack3, &pblue, constcX, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();
			
			this->scene->addItem(box.drawSection2Layer1OverDraw(stack1, bW));
			listItems = box.drawSection2Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem* item : listItems)
			{
				this->scene->addItem(item);
			}
			listItems.clear();

			//Section 1

			this->scene->addItem(box.drawSection1Layer2OverDraw(stack2, bW, constcX));
			listItems = box.drawSection1Layer2Rect(stack2, &pgr, constcX);
			for (QGraphicsRectItem * item : listItems) {
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection1Layer4OverDraw(stack4, bW, constcX, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection1Layer4Rect(stack4, &pm, constcX, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem * item : listItems) {
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection1Layer3OverDraw(stack3, bW, constcX, constcZ, cRBX, cRBY, cRBZ));
			listItems = box.drawSection1Layer3Rect(stack3, &pblue, constcX, constcZ, cRBX, cRBY, cRBZ);
			for (QGraphicsRectItem * item : listItems) {
				this->scene->addItem(item);
			}
			listItems.clear();

			this->scene->addItem(box.drawSection1Layer1OverDraw(stack1, bW));
			listItems = box.drawSection1Layer1Rect(stack1, &pr);
			for (QGraphicsRectItem * item : listItems) {
				this->scene->addItem(item);
			}
			listItems.clear();
		
		break;
	}

	listStackSize = listStack.size();
	//Section 2 //ToDO:Section2

	std::reverse(listStack.begin(), listStack.end());
	listStackSize = 1;
	
	listStackSize = 1;
	
	listStackSize = 1;
	//Section 6
	/*for (Stack stack : listStack)
	{
		if (listStackSize == listStack.size() + 1)
		{
			break;
		}
		switch (listStackSize)
		{
		case 1:
			cX = stack.GetBigBox().GetBigBoxWidth() * 20;
			cY = stack.GetBigBox().GetBigBoxHeight() * 20;
			cZ = stack.GetBigBox().GetBigBoxLength() * 20;

			bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
			bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
			bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

			rectWhite = new QGraphicsRectItem(20 + cX + 10 + cZ + 10 + cX + 10 + constcZ, 20 + cX + 10 + cY, -(bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
			rectWhite->setBrush(bW);
			rectWhite->update();
			this->scene->addItem(rectWhite);
			//Section 6
			for (int i = 1; i <= stack.GetListNumbersZ(); i++)
			{
				for (int j = 1; j <= stack.GetListNumbersY(); j++) {
					rect = new QGraphicsRectItem(20 + cX + 10 + cZ + 10 + cX + 10 + constcZ, 20 + cX + 10 + cY, -(bZ)*i, -(bY)*j);
					rect->setPen(pr);
					rect->update();
					this->scene->addItem(rect);
				}
			}
			listStackSize++;
			continue;
		case 2:
			cX = stack.GetBigBox().GetBigBoxWidth() * 20;
			cY = stack.GetBigBox().GetBigBoxHeight() * 20;
			cZ = stack.GetBigBox().GetBigBoxLength() * 20;

			bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
			bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
			bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

			rectWhite = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10, 20 + constcX + 10 + cY, (bZ)*stack.GetListNumbersZ(), -(bY)*stack.GetListNumbersY());
			rectWhite->setBrush(bW);
			rectWhite->update();
			this->scene->addItem(rectWhite);
			for (int i = 1; i <= stack.GetListNumbersZ(); i++) {
				for (int j = 1; j <= stack.GetListNumbersY(); j++) {
					rect = new QGraphicsRectItem(20 + constcX + 10 + constcZ + 10 + constcX + 10, 20 + constcX + 10 + cY, (bZ)*i, -(bY)*j);
					rect->setPen(pgr);
					rect->update();
					this->scene->addItem(rect);
				}
			}
			listStackSize++;
			continue;
		case 3:
			listStackSize++;
			continue;
		case 4:
			listStackSize++;
			continue;
		}

	}*/
}

void MainWindow::set_Container(double cX, double cY, double cZ, double sBX, double sBY, double sBZ)
{
	this->containerX = cX;
	this->containerY = cY;
	this->containerZ = cZ;

	this->boxX = sBX;
	this->boxY = sBY;
	this->boxZ = sBZ;

	ui->lineEdit_ContainerWidth->setText(QString::number(this->containerX));
	ui->lineEdit_ContainerHeight->setText(QString::number(this->containerY));
	ui->lineEdit_ContainerLength->setText(QString::number(this->containerZ));

	ui->lineEdit_SmallBoxWidth->setText(QString::number(this->boxX));
	ui->lineEdit_SmallBoxHeight->setText(QString::number(this->boxY));
	ui->lineEdit_SmallBoxLength->setText(QString::number(this->boxZ));
}

void MainWindow::on_OneSized_clicked(bool edit)
{
	Dialog_OneSized oneSized;
	if (edit) {
		oneSized.set_container(this->containerX,this->containerY,this->containerZ,this->boxX,this->boxY,this->boxZ);
		oneSized.setTextBoxesEdit();
	}
	oneSized.setModal(true);
	oneSized.exec();
	if(oneSized.getCalculated() == false)
	{
		return;
	}
	this->ui->actionEdit_Boxes->setEnabled(true);
	this->sc = *new StackCollection(StackCollection(oneSized.GetContainerX(), oneSized.GetContainerY(), oneSized.GetContainerZ(), oneSized.GetSmallBoxX(), oneSized.GetSmallBoxY(), oneSized.GetSmallBoxZ()));
	
	int count = 0;
	this->ui->listWidget_Result->clear();
	std::list<std::pair<std::list<Stack>, int>> listSC = *new std::list<std::pair<std::list<Stack>, int>>( this->sc.GetCompletedStackCollection());
	for (std::list<std::pair<std::list<Stack>, int>>::iterator it = listSC.begin(); it != listSC.end(); it++)
	{
		this->ui->listWidget_Result->insertItem(count++, QString::number(it->second));
	}
	this->set_Container(oneSized.GetContainerX(), oneSized.GetContainerY(), oneSized.GetContainerZ(), oneSized.GetSmallBoxX(), oneSized.GetSmallBoxY(), oneSized.GetSmallBoxZ());
}

