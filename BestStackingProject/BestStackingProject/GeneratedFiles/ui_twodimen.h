/********************************************************************************
** Form generated from reading UI file 'twodimen.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWODIMEN_H
#define UI_TWODIMEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TwoDimen
{
public:
    QLabel *label;
    QFrame *line;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *TwoDimen)
    {
        if (TwoDimen->objectName().isEmpty())
            TwoDimen->setObjectName(QStringLiteral("TwoDimen"));
        TwoDimen->resize(400, 300);
        TwoDimen->setMaximumSize(QSize(400, 300));
        label = new QLabel(TwoDimen);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 30, 121, 20));
        line = new QFrame(TwoDimen);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 60, 381, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        comboBox = new QComboBox(TwoDimen);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(150, 80, 111, 22));
        lineEdit = new QLineEdit(TwoDimen);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 140, 113, 20));
        lineEdit_2 = new QLineEdit(TwoDimen);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 170, 113, 20));
        lineEdit_3 = new QLineEdit(TwoDimen);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(60, 200, 113, 20));
        label_2 = new QLabel(TwoDimen);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 140, 31, 16));
        label_3 = new QLabel(TwoDimen);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 170, 41, 16));
        label_4 = new QLabel(TwoDimen);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 200, 47, 13));
        pushButton = new QPushButton(TwoDimen);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 200, 111, 23));
        pushButton_3 = new QPushButton(TwoDimen);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 260, 75, 23));
        pushButton_2 = new QPushButton(TwoDimen);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 260, 75, 23));

        retranslateUi(TwoDimen);

        QMetaObject::connectSlotsByName(TwoDimen);
    } // setupUi

    void retranslateUi(QDialog *TwoDimen)
    {
        TwoDimen->setWindowTitle(QApplication::translate("TwoDimen", "Container Configuration", nullptr));
        label->setText(QApplication::translate("TwoDimen", "Container Configuration", nullptr));
        comboBox->setItemText(0, QApplication::translate("TwoDimen", "Container 1", nullptr));
        comboBox->setItemText(1, QApplication::translate("TwoDimen", "Container 2", nullptr));

        label_2->setText(QApplication::translate("TwoDimen", "Width:", nullptr));
        label_3->setText(QApplication::translate("TwoDimen", "Height:", nullptr));
        label_4->setText(QApplication::translate("TwoDimen", "Length:", nullptr));
        pushButton->setText(QApplication::translate("TwoDimen", "Save", nullptr));
        pushButton_3->setText(QApplication::translate("TwoDimen", "Next", nullptr));
        pushButton_2->setText(QApplication::translate("TwoDimen", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TwoDimen: public Ui_TwoDimen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWODIMEN_H
