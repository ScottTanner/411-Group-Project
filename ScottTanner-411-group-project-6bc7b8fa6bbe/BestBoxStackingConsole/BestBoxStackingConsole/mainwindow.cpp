#include "twodimen.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_algorithim_One_clicked()
{
    TwoDimen gui2;
    gui2.setModal(true);
    gui2.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}