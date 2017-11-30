#include "OneSizedAlgorithm.h"
#include "mainwindow.h"
#include "ui_boxstacking.h"
#include <algorithm>
#include "DialogAbout.h"
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
	connect(ui->actionNight_View, &QAction::triggered, this, &MainWindow::on_Night_View_clicked);

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

void MainWindow::on_Night_View_clicked()
{
	if (styleControl == true) {
		//QString styleSheet = "QPushButton{border-style:solid;background-color:#da532c;color:#fff;border-radius:7px;}";
		QString styleSheet = "QDialog{}QGroupBox{background-color:#2d2d2d;color: #fff;border: none;}QLabel{color: #fff;}QMenuBar{background-color:#1d1d1d;padding:5px;	font: 12pt 'MS Shell Dlg 2';}QMenuBar::item{background-color:#1d1d1d;color:#fff;padding:5px;}QMenu{color:#fff;padding:0;}QMenu::item:selected{color:#fff;background-color:#00aba9;}QMenu::QAction{color: #ffffff;}QWidget{background-color: #2d2d2d;font-color: #ffffff;}QTabWidget{background-color: #2d2d2d;}QTableWidget{background-color:#2d2d2d;color:#fff;  selection-background-color: #da532c;border:solid;border-width:3px;border-color:#da532c;}QHeaderView::section{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));border:none;border-top-style:solid;border-width:1px;border-top-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));color:#fff;}QHeaderView{background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));border:none;border-top-style:solid;border-width:1px;border-top-color:#149ED9;color:#fff;	font: 75 12pt 'Calibri';}QTableCornerButton::section{border:none;background-color:#149ED9;}QListWidget{background-color:#3d3d3d;color:#fff;}QMenu{background-color:#3d3d3d;}QStatusBar{background-color:#7e3878;color:#fff;}QComboBox{border-style:solid;background-color:#3d3d3d;color:#fff;border-radius:7px;}QPushButton{border-style:solid;background-color:#3d3d3d;color:#fff;border-radius:7px;}QPushButton:hover{color:#ccc;	background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(45, 45, 45, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));	border-color:#2d89ef;border-width:2px;}QPushButton:pressed{background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(29, 29, 29, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));}QTabWidget::tab{background-color:#3d3d3d;}QLineEdit{border-radius:0;}QProgressBar{border-radius:0;text-align:center;color:#fff;background-color:transparent;border: 2px solid #e3a21a;border-radius:7px;	font: 75 12pt 'Open Sans';}QLineEdit{background-color: #ffffff;}QProgressBar::chunk{background-color:#2d89ef;width:20px;}";
		styleControl = false;
		this->setStyleSheet(styleSheet);
	}
	else {
		QString styleSheet2 = "QDialog{ } QMenuBar{ background-color:#1d1d1d; padding:5px; font: 12pt 'MS Shell Dlg 2'; } QMenuBar::item{ background-color:#1d1d1d; color:#fff; padding:5px; } QMenu{ color:#fff; padding:0; } QMenu::item:selected{ color:#fff; background-color:#00aba9; } QTableWidget{ background-color:#3d3d3d; color:#fff; selection-background-color: #da532c; border:solid; border-width:3px; border-color:#da532c; } QHeaderView::section{ background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255)); border:none; border-top-style:solid; border-width:1px; border-top-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255)); color:#fff; } QHeaderView{ background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255)); border:none; border-top-style:solid; border-width:1px; border-top-color:#149ED9; color:#fff; font: 75 12pt 'Calibri'; } QTableCornerButton::section{ border:none; background-color:#149ED9; } QListWidget{ background-color:#3d3d3d; color:#fff; } QMenu{ background-color:#3d3d3d; } QStatusBar{ background-color:#7e3878; color:#fff; } QComboBox { border-style:solid; background-color:#3d3d3d; color:#fff; border-radius:7px; } QPushButton{ border-style:solid; background-color:#3d3d3d; color:#fff; border-radius:7px; } QPushButton:hover{ color:#ccc; background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(45, 45, 45, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255)); border-color:#2d89ef; border-width:2px; } QPushButton:pressed{ background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(29, 29, 29, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255)); } QTabWidget::tab{ background-color:#3d3d3d; } QLineEdit{ border-radius:0; } QProgressBar{ border-radius:0; text-align:center; color:#fff; background-color:transparent; border: 2px solid #e3a21a; border-radius:7px; font: 75 12pt 'Open Sans'; } QProgressBar::chunk{ background-color:#2d89ef; width:20px; }";
		styleControl = true;
		this->setStyleSheet(styleSheet2);
	}


    //ui->menubar->setStyleSheet(styleSheet);
}


void MainWindow::paintContainers()
{
	this->scene = new QGraphicsScene(0, 0, this->ui->graphicsView_TwoDim->width(), this->ui->graphicsView_TwoDim->height(), this->ui->graphicsView_TwoDim);
	this->scene->setBackgroundBrush(Qt::white);

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
	QPen pr(Qt::SolidPattern);
	pr.setColor(Qt::red);
	QPen pgr(Qt::SolidPattern);
	pgr.setColor(Qt::green);
	QBrush bW(Qt::SolidPattern);
	bW.setColor(Qt::white);

	int count = 0;
	int constcX = conCX*20;
	int constcY = conCY * 20;
	int constcZ = conCZ * 20;

	std::reverse(listStack.begin(), listStack.end());
	for (Stack stack : listStack) {
		double cX = stack.GetBigBox().GetBigBoxWidth() * 20;
		double cY = stack.GetBigBox().GetBigBoxHeight()* 20;
		double cZ = stack.GetBigBox().GetBigBoxLength()* 20;

		double bX = stack.GetSmallBox().GetSmallBoxWidth() * 20;
		double bY = stack.GetSmallBox().GetSmallBoxHeight() * 20;
		double bZ = stack.GetSmallBox().GetSmallBoxLength() * 20;

		if (count == (listStack.size()-1)) {
			QGraphicsRectItem* rectWhite = new QGraphicsRectItem(20 + cX, 20 + cX + 10 + cY, -(bX)*stack.GetListNumbersX(), -(bY)*stack.GetListNumbersY());
			rectWhite->setBrush(bW);
			rectWhite->update();
			this->scene->addItem(rectWhite);
			//Section1
			for (int i = 1; i <= stack.GetListNumbersX(); i++) {
				QGraphicsRectItem* rectX = new QGraphicsRectItem(20 + cX, 20 + cX + 10 + cY, -(bX)*i, -(bY));
				rectX->setPen(pr);
				rectX->update();
				this->scene->addItem(rectX);
				for (int j = 1; j <= stack.GetListNumbersY(); j++) {
					QGraphicsRectItem* rectY = new QGraphicsRectItem(20 + cX, 20 + cX + 10 + cY, -(bX)*i, -(bY)*j);
					rectY->setPen(pr);
					rectY->update();
					this->scene->addItem(rectY);
				}
			}

			//Section 2
			for (int i = 1; i <= stack.GetListNumbersZ(); i++) 
			{
				QGraphicsRectItem* rectX = new QGraphicsRectItem(20 + cX + 10, 20 + cX, (bZ)*i, -(bX));
				rectX->setPen(pr);
				rectX->update();
				this->scene->addItem(rectX);
				for (int j = 1; j <= stack.GetListNumbersX(); j++) {
					QGraphicsRectItem* rectZ = new QGraphicsRectItem(20 + cX + 10, 20 + cX, (bZ)*i, -(bX)*j);
					rectZ->setPen(pr);
					rectZ->update();
					this->scene->addItem(rectZ);
				}
			}

			//Section 3
			for (int i = 1; i <= stack.GetListNumbersZ(); i++)
			{
				QGraphicsRectItem* rectX = new QGraphicsRectItem(20 + cX + 10, 20 + cX + 10 + cY, (bZ)*i, -(bY));
				rectX->setPen(pr);
				rectX->update();
				this->scene->addItem(rectX);
				for (int j = 1; j <= stack.GetListNumbersY(); j++) {
					QGraphicsRectItem* rectZ = new QGraphicsRectItem(20 + cX + 10, 20 + cX + 10 + cY, (bZ)*i, -(bY)*j);
					rectZ->setPen(pr);
					rectZ->update();
					this->scene->addItem(rectZ);
				}
			}

			//Secton 4
			for (int i = 1; i <= stack.GetListNumbersZ(); i++)
			{
				QGraphicsRectItem* rectX = new QGraphicsRectItem(20 + cX + 10, 20 + cX + 10 + cY + 10, (bZ)*i, (bX));
				rectX->setPen(pr);
				rectX->update();
				this->scene->addItem(rectX);
				for (int j = 1; j <= stack.GetListNumbersX(); j++) {
					QGraphicsRectItem* rectZ = new QGraphicsRectItem(20 + cX + 10, 20 + cX + 10 + cY + 10, (bZ)*i, (bX)*j);
					rectZ->setPen(pr);
					rectZ->update();
					this->scene->addItem(rectZ);
				}
			}

			//Section 5
			for (int i = 1; i <= stack.GetListNumbersX(); i++)
			{
				QGraphicsRectItem* rectX = new QGraphicsRectItem(20 + cX + 10 + cZ + 10, 20 + cX + 10 + cY, (bX)*i, -(bY));
				rectX->setPen(pr);
				rectX->update();
				this->scene->addItem(rectX);
				for (int j = 1; j <= stack.GetListNumbersY(); j++) {
					QGraphicsRectItem* rectZ = new QGraphicsRectItem(20 + cX + 10 + cZ + 10, 20 + cX + 10 + cY, (bX)*i, -(bY)*j);
					rectZ->setPen(pr);
					rectZ->update();
					this->scene->addItem(rectZ);
				}
			}

			//Section 6
			for (int i = 1; i <= stack.GetListNumbersZ(); i++)
			{
				QGraphicsRectItem* rectX = new QGraphicsRectItem(20 + cX + 10 + cZ + 10 + cX + 10 + cZ , 20 + cX + 10 + cY, -(bZ)*i, -(bY));
				rectX->setPen(pr);
				rectX->update();
				this->scene->addItem(rectX);
				for (int j = 1; j <= stack.GetListNumbersY(); j++) {
					QGraphicsRectItem* rectZ = new QGraphicsRectItem(20 + cX + 10 + cZ + 10 + cX + 10 + cZ, 20 + cX + 10 + cY, -(bZ)*i, -(bY)*j);
					rectZ->setPen(pr);
					rectZ->update();
					this->scene->addItem(rectZ);
				}
			}
		}
		else if(count == listStack.size() - 2)
		{
			for (int i = 1; i <= stack.GetListNumbersX(); i++) {
				QGraphicsRectItem* rectX = new QGraphicsRectItem(20 + cX, 20 + constcX + 10 + constcY, -(bX)*i, -(bY));

				this->scene->addItem(rectX);
				rectX->setPen(pgr);
				rectX->update();
				for (int j = 1; j <= stack.GetListNumbersY(); j++) {
					QGraphicsRectItem* rectY = new QGraphicsRectItem(20 + cX, 20 + constcX + 10 + constcY, -(bX)*i, -(bY)*j);
					
					
					rectY->setPen(pgr);
					rectY->update();
					this->scene->addItem(rectY);
				}
			}
		}
		count++;
	}

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

