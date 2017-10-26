#ifndef THREEDIMENEXT_H
#define THREEDIMENEXT_H

#include <QDialog>

namespace Ui {
class ThreeDimeNext;
}

class ThreeDimeNext : public QDialog
{
    Q_OBJECT

public:
    explicit ThreeDimeNext(QWidget *parent = 0);
    ~ThreeDimeNext();

private:
    Ui::ThreeDimeNext *ui;
};

#endif // THREEDIMENEXT_H
