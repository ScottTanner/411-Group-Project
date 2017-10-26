/********************************************************************************
** Form generated from reading UI file 'threedimenext.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREEDIMENEXT_H
#define UI_THREEDIMENEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ThreeDimeNext
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ThreeDimeNext)
    {
        if (ThreeDimeNext->objectName().isEmpty())
            ThreeDimeNext->setObjectName(QStringLiteral("ThreeDimeNext"));
        ThreeDimeNext->resize(400, 300);
        buttonBox = new QDialogButtonBox(ThreeDimeNext);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(ThreeDimeNext);
        QObject::connect(buttonBox, SIGNAL(accepted()), ThreeDimeNext, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ThreeDimeNext, SLOT(reject()));

        QMetaObject::connectSlotsByName(ThreeDimeNext);
    } // setupUi

    void retranslateUi(QDialog *ThreeDimeNext)
    {
        ThreeDimeNext->setWindowTitle(QApplication::translate("ThreeDimeNext", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThreeDimeNext: public Ui_ThreeDimeNext {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREEDIMENEXT_H
