#include "stdafx.h"
#include "mainwindow.h"
#include <QSplashScreen>
#include <QtWidgets/QApplication>

using namespace std;

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	QPixmap pixmap("BestStacking.jpg");
	QSplashScreen splash(pixmap);
	splash.show();
	MainWindow w;
	w.show();
	splash.finish(&w);
	return a.exec();
	return 0;
}