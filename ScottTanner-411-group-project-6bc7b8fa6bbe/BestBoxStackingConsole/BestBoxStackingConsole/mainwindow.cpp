#include "OneSizedAlgorithm.h"
#include "mainwindow.h"
#include "ui_boxstacking.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	connect(ui->actionOne_Sized_Small_Boxes, &QAction::triggered, this, &MainWindow::on_OneSized_clicked);
	connect(ui->actionExit, &QAction::triggered, this, &MainWindow::on_Exit_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Exit_clicked()
{
	close();
}

void MainWindow::on_OneSized_clicked()
{
	Dialog_OneSized oneSized;
	oneSized.setModal(true);
	oneSized.exec();
}
