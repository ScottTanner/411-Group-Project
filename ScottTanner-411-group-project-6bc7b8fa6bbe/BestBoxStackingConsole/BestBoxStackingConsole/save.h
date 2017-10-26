#ifndef SAVE_H
#define SAVE_H

#include <QDialog>
#include <string>

namespace Ui {
class Save;
}

class Save : public QDialog
{
    Q_OBJECT

public:
    explicit Save(QWidget *parent = 0);
	void setFlagBox(bool flag);
	void setValues(double boxX,double boxY, double boxZ);
	void setlistStingsPair(std::list<std::pair<std::string, std::list<double>>> listStringsPair);
    ~Save();

private slots:
    void on_pushButton_Cancel_clicked();
	void on_pushButton_Save_clicked();

private:
    Ui::Save *ui;
	bool flagBox;
	std::string name;
	std::string boxX;
	std::string boxY;
	std::string boxZ;
	std::list<std::pair<std::string, std::list<double>>> listStringsPair;
};

#endif // SAVE_H
