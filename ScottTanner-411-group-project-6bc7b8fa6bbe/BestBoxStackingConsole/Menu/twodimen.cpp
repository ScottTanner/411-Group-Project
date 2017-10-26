#include"save.h"
#include "twodimennext.h"
#include "twodimen.h"
#include "ui_twodimen.h"

TwoDimen::TwoDimen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TwoDimen)
{
    ui->setupUi(this);
}

TwoDimen::~TwoDimen()
{
    delete ui;
}

void TwoDimen::on_pushButton_3_clicked()
{
    TwoDimenNext gui2;
    gui2.setModal(true);
    gui2.exec();
}

void TwoDimen::on_pushButton_clicked()
{
    Save gui3;
    gui3.setModal(true);
    gui3.exec();
}

void TwoDimen::on_pushButton_2_clicked()
{
    close();
}

void TwoDimen::on_pushButton_4_clicked()
{
    ui->lineEdit_3->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit->setText("");
}
