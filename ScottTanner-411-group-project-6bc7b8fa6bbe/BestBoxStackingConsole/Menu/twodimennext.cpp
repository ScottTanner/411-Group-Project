#include"calculate.h"
#include "save.h"
#include "twodimennext.h"
#include "ui_twodimennext.h"

TwoDimenNext::TwoDimenNext(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TwoDimenNext)
{
    ui->setupUi(this);
}

TwoDimenNext::~TwoDimenNext()
{
    delete ui;
}

void TwoDimenNext::on_pushButton_clicked()
{
    Save gui3;
    gui3.setModal(true);
    gui3.exec();
}

void TwoDimenNext::on_pushButton_2_clicked()
{
    Calculate gui2;
    gui2.setModal(true);
    gui2.exec();
}

void TwoDimenNext::on_pushButton_4_clicked()
{

}

void TwoDimenNext::on_pushButton_3_clicked()
{
    close();
}
