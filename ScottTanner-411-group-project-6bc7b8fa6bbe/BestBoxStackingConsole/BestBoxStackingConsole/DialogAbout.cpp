#include "DialogAbout.h"
#include "ui_AboutDialog.h"


DialogAbout::DialogAbout(QWidget *parent) : 
	QDialog(parent),
	ui(new Ui::DialogAbout)
{
	ui->setupUi(this);
}


DialogAbout::~DialogAbout()
{
}
