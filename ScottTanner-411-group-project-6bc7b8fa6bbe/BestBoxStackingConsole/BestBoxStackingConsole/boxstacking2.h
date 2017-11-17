#ifndef BOXSTACKING2_H
#define BOXSTACKING2_H

#include <QDialog>

namespace Ui {
	class boxstacking2;
}

class boxstacking2 : public QDialog
{
	Q_OBJECT

public:
	explicit boxstacking2(QWidget *parent = 0);
	~boxstacking2();

private:
	Ui::boxstacking2 *ui;
};

#endif // BOXSTACKING2_H
