#include "threedime.h"
#include "ui_threedime.h"

ThreeDime::ThreeDime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThreeDime)
{
    ui->setupUi(this);
}

ThreeDime::~ThreeDime()
{
    delete ui;
}
