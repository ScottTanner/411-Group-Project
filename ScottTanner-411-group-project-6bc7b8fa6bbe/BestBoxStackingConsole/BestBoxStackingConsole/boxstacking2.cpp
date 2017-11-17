#include "boxstacking2.h"
#include "ui_boxstacking2.h"

boxstacking2::boxstacking2(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::boxstacking2)
{
	ui->setupUi(this);
}

boxstacking2::~boxstacking2()
{
	delete ui;
}
