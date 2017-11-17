#include "BoxStack2.h"
#include"ui_BoxStack2.h"
#include "OneSizedAlgorithm.h"

BoxStack2::BoxStack2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoxStack2)
{
    ui->setupUi(this);
}
void BoxStack2::set_StackCollection(StackCollection sc)
{
	this->sc = sc;
	int count = 0;
	std::list<std::pair<std::list<Stack>, int>> listSC = this->sc.GetCompletedStackCollection();
	for (std::list<std::pair<std::list<Stack>, int>>::iterator it = listSC.begin(); it != listSC.end(); it++)
	{
		this->ui->listWidget_ShowResult->insertItem(count++, QString::number(it->second));
	}

	// Connect ListWidget_ShowResult with this obejct when an item is clicked and run the Update_Table method
	connect(ui->listWidget_ShowResult, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(Update_Table()));
}

void BoxStack2::Update_Table()
{
	// Delete all rows in the table
	int rows = this->ui->tableWidget_ShowStacks->rowCount();
	for (int i = 0; i <rows; i++) {
		this->ui->tableWidget_ShowStacks->removeRow(0);
	}

	std::list<std::pair<std::list<Stack>, int>> listSC = this->sc.GetCompletedStackCollection();
	int currentItem = this->ui->listWidget_ShowResult->currentRow();
	int count = 0;
	for (std::list<std::pair<std::list<Stack>, int>>::iterator itList = listSC.begin(); itList != listSC.end(); itList++)
	{
		if (currentItem == count)
		{
			std::list<Stack> listStack = (*itList).first;
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
			break;
		}
		else {
			count++;
		}
	}
}
BoxStack2::~BoxStack2()
{
    delete ui;
}

void BoxStack2::on_pushButton_Exit_clicked()
{
	close();
}

void BoxStack2::set_container(double cX, double cY, double cZ, double boxX, double boxY, double boxZ)
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

void BoxStack2::on_pushButton_Config_clicked() {

	Dialog_OneSized oneSized;
	oneSized.setModal(true);
	close();
	oneSized.exec();
}