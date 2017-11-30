/********************************************************************************
** Form generated from reading UI file 'dialog_Color_Selector.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_COLOR_SELECTOR_H
#define UI_DIALOG_COLOR_SELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormColorSelector
{
public:
    QPushButton *pushButton_Exit;
    QGraphicsView *graphicsView_Color_View;
    QComboBox *comboBox_Color_Select;
    QPushButton *pushButton_Change_Color;

    void setupUi(QWidget *FormColorSelector)
    {
        if (FormColorSelector->objectName().isEmpty())
            FormColorSelector->setObjectName(QStringLiteral("FormColorSelector"));
        FormColorSelector->resize(498, 486);
        FormColorSelector->setMinimumSize(QSize(498, 486));
        FormColorSelector->setMaximumSize(QSize(498, 486));
        pushButton_Exit = new QPushButton(FormColorSelector);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(230, 320, 75, 23));
        graphicsView_Color_View = new QGraphicsView(FormColorSelector);
        graphicsView_Color_View->setObjectName(QStringLiteral("graphicsView_Color_View"));
        graphicsView_Color_View->setGeometry(QRect(180, 150, 181, 151));
        graphicsView_Color_View->setAutoFillBackground(true);
        comboBox_Color_Select = new QComboBox(FormColorSelector);
        comboBox_Color_Select->addItem(QString());
        comboBox_Color_Select->addItem(QString());
        comboBox_Color_Select->addItem(QString());
        comboBox_Color_Select->addItem(QString());
        comboBox_Color_Select->addItem(QString());
        comboBox_Color_Select->addItem(QString());
        comboBox_Color_Select->addItem(QString());
        comboBox_Color_Select->setObjectName(QStringLiteral("comboBox_Color_Select"));
        comboBox_Color_Select->setGeometry(QRect(190, 50, 151, 31));
        pushButton_Change_Color = new QPushButton(FormColorSelector);
        pushButton_Change_Color->setObjectName(QStringLiteral("pushButton_Change_Color"));
        pushButton_Change_Color->setGeometry(QRect(230, 110, 75, 23));

        retranslateUi(FormColorSelector);

        QMetaObject::connectSlotsByName(FormColorSelector);
    } // setupUi

    void retranslateUi(QWidget *FormColorSelector)
    {
        FormColorSelector->setWindowTitle(QApplication::translate("FormColorSelector", "Form", nullptr));
        pushButton_Exit->setText(QApplication::translate("FormColorSelector", "Exit", nullptr));
        comboBox_Color_Select->setItemText(0, QApplication::translate("FormColorSelector", "Select Item", nullptr));
        comboBox_Color_Select->setItemText(1, QApplication::translate("FormColorSelector", "Small Box First", nullptr));
        comboBox_Color_Select->setItemText(2, QApplication::translate("FormColorSelector", "Small Box Second", nullptr));
        comboBox_Color_Select->setItemText(3, QApplication::translate("FormColorSelector", "Small Box Third", nullptr));
        comboBox_Color_Select->setItemText(4, QApplication::translate("FormColorSelector", "Small Box Fourth", nullptr));
        comboBox_Color_Select->setItemText(5, QApplication::translate("FormColorSelector", "Background", nullptr));
        comboBox_Color_Select->setItemText(6, QApplication::translate("FormColorSelector", "Container", nullptr));

        pushButton_Change_Color->setText(QApplication::translate("FormColorSelector", "Change Color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormColorSelector: public Ui_FormColorSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_COLOR_SELECTOR_H
