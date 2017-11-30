#include "FormColorSelector.h"
#include "ui_dialog_Color_Selector.h"


FormColorSelector::FormColorSelector(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::FormColorSelector)
{
	ui->setupUi(this);
}


FormColorSelector::~FormColorSelector()
{
}

QColor FormColorSelector::get_smallBoxFirst()
{
	return this->smallBoxFirst;
}

QColor FormColorSelector::get_smallBoxSecond()
{
	return this->smallBoxSecond;
}

QColor FormColorSelector::get_smallBoxThird()
{
	return this->smallBoxThird;
}

QColor FormColorSelector::get_smallBoxFourth()
{
	return this->smallBoxFourth;
}

QColor FormColorSelector::get_container()
{
	return this->container;
}

QColor FormColorSelector::get_backGround()
{
	return this->backGround;
}

void FormColorSelector::on_pushButton_Exit_clicked()
{
	close();
}

void FormColorSelector::colorChanged(QColor color)
{
	this->scene = new QGraphicsScene(0, 0, this->ui->graphicsView_Color_View->width(), this->ui->graphicsView_Color_View->height(), this->ui->graphicsView_Color_View);
	this->scene->setBackgroundBrush(color);
	this->ui->graphicsView_Color_View->setScene(this->scene);
}

void FormColorSelector::colorChangedTarget()
{

}

void FormColorSelector::on_pushButton_Change_Color_clicked()
{
	color = QColorDialog::getColor(Qt::white, this);
	colorChanged(this->color);
	smallBoxFirst = this->color;

	QString First = "Small Box First";
	QString Second = "Small Box Second";
	QString Third = "Small Box Third";
	QString Fourth = "Small Box Fourth";
	QString back= "Background";
	QString cont = "Container";


	if (ui->comboBox_Color_Select->currentText() == First)
	{
		this->smallBoxFirst = color;
	}
	else if (ui->comboBox_Color_Select->currentText() == Second)
	{
		this->smallBoxSecond = color;
	}
	else if (ui->comboBox_Color_Select->currentText() == Third)
	{
		this->smallBoxThird = color;
	}
	else if (ui->comboBox_Color_Select->currentText() == Fourth)
	{
		this->smallBoxFourth = color;
	}
	else if (ui->comboBox_Color_Select->currentText() == back)
	{
		this->backGround = color;
	}
	else if (ui->comboBox_Color_Select->currentText() == cont)
	{
		this->container = color;
	}

}

