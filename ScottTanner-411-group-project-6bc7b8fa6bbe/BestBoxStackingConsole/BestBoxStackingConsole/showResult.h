#ifndef SHOWRESULT_H
#define SHOWRESULT_H

#include <QDialog>
#include "StackCollection.h"

namespace Ui {
class ShowResult;
}

class ShowResult : public QDialog
{
    Q_OBJECT


public:
    explicit ShowResult(QWidget *parent = 0);
	void set_StackCollection(StackCollection sc);
    ~ShowResult();
public slots:
	void Update_Table();
private:
    Ui::ShowResult *ui;
	StackCollection sc;
};

#endif // SHOWRESULT_H
