/********************************************************************************
** Form generated from reading UI file 'threedime.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREEDIME_H
#define UI_THREEDIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ThreeDime
{
public:

    void setupUi(QDialog *ThreeDime)
    {
        if (ThreeDime->objectName().isEmpty())
            ThreeDime->setObjectName(QStringLiteral("ThreeDime"));
        ThreeDime->resize(400, 300);

        retranslateUi(ThreeDime);

        QMetaObject::connectSlotsByName(ThreeDime);
    } // setupUi

    void retranslateUi(QDialog *ThreeDime)
    {
        ThreeDime->setWindowTitle(QApplication::translate("ThreeDime", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThreeDime: public Ui_ThreeDime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREEDIME_H
