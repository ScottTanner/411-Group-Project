#include "calculate.h"
#include "ui_calculate.h"

Calculate::Calculate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calculate)
{
    ui->setupUi(this);
}

Calculate::~Calculate()
{
    delete ui;
}

void Calculate::on_pushButton_clicked()
{
    close();
}
