#ifndef THREEDIME_H
#define THREEDIME_H

#include <QDialog>

namespace Ui {
class ThreeDime;
}

class ThreeDime : public QDialog
{
    Q_OBJECT

public:
    explicit ThreeDime(QWidget *parent = 0);
    ~ThreeDime();

private:
    Ui::ThreeDime *ui;
};

#endif // THREEDIME_H
