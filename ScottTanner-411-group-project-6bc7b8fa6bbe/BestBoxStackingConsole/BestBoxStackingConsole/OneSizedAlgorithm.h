#ifndef ONESIZEDALGORITHM_H
#define	ONESIZEDALGORITHM_H


#include <QDialog>

namespace Ui {
	class Dialog_OneSized;
}

class Dialog_OneSized : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog_OneSized(QWidget *parent = 0);
	~Dialog_OneSized();

private slots:
	void on_OneSized_Clicked();

private:
	Ui::Dialog_OneSized *ui;

};


#endif // !ONESIZEDALGORITHM_H