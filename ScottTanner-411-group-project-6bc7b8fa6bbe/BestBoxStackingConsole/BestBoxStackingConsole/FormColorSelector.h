#ifndef FORMCOLORSELECTOR_H
#define FORMCOLORSELECTOR_H

#include <QDialog>
#include <QGraphicsItem>
#include <QColorDialog>


namespace Ui {
	class FormColorSelector;
}

class FormColorSelector : public QDialog

{
	Q_OBJECT
public:
	explicit FormColorSelector(QWidget *parent = 0);
	~FormColorSelector();
	QColor get_smallBoxFirst();
	QColor get_smallBoxSecond();
	QColor get_smallBoxThird();
	QColor get_smallBoxFourth();
	QColor get_container();
	QColor get_backGround();

private slots:
	void on_pushButton_Change_Color_clicked();
	void on_pushButton_Exit_clicked();

private:
	QColor smallBoxFirst;
	QColor smallBoxSecond;
	QColor smallBoxThird;
	QColor smallBoxFourth;
	QColor container;
	QColor backGround;
	QColorDialog colors;
	QGraphicsScene *scene;
	Ui::FormColorSelector *ui;
	QColor color;
	void colorChanged(QColor color);
	void colorChangedTarget();

};

#endif //FORMCOLORSELECTOR_H