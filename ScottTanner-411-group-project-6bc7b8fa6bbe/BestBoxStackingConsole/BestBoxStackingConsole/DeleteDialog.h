#ifndef DELETE_H
#define DELETE_H

#include <QDialog>
#include <string>

namespace Ui {
	class DeleteDialog;
}

class DeleteDialog : public QDialog
{
	Q_OBJECT
public:
	explicit DeleteDialog(QWidget *parent = 0);
	~DeleteDialog();
	void fill_ComboSMBox(bool small = false);

private slots:
void on_DeleteButton_Clicked();
void on_CancelDelete_Clicked();
private:
	Ui::DeleteDialog *ui;
	std::string filename;
	std::string boxName;
	std::list<std::pair<std::string, std::list<double>>> listStringsPair;
};
#endif // !DELETE_H
