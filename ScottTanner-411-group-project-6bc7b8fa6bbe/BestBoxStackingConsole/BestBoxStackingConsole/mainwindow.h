#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
	void set_container(double cX, double cY, double cZ, double boxX, double boxY, double boxZ);
	~MainWindow();

	

private slots:
	void on_OneSized_clicked();
	void on_Exit_clicked();

private:
    Ui::MainWindow *ui;
	double containerX;
	double containerY;
	double containerZ;
	double smallBoxX;
	double smallBoxY;
	double smallBoxZ;
};

#endif // MAINWINDOW_H
