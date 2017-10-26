#include "save.h"
#include "ui_save.h"

Save::Save(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Save)
{
    ui->setupUi(this);
}

Save::~Save()
{
    delete ui;
}

void Save::on_pushButton_2_clicked()
{
    close();
}
