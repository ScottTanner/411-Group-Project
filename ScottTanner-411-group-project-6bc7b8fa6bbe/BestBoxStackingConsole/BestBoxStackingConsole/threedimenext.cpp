#include "threedimenext.h"
#include "ui_threedimenext.h"

ThreeDimeNext::ThreeDimeNext(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThreeDimeNext)
{
    ui->setupUi(this);
}

ThreeDimeNext::~ThreeDimeNext()
{
    delete ui;
}
