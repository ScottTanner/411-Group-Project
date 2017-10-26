/********************************************************************************
** Form generated from reading UI file 'twodimennext.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWODIMENNEXT_H
#define UI_TWODIMENNEXT_H

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

class Ui_TwoDimenNext
{
public:
    QLabel *label;
    QFrame *line;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_4;

    void setupUi(QDialog *TwoDimenNext)
    {
        if (TwoDimenNext->objectName().isEmpty())
            TwoDimenNext->setObjectName(QStringLiteral("TwoDimenNext"));
        TwoDimenNext->resize(400, 300);
        TwoDimenNext->setMaximumSize(QSize(400, 300));
        TwoDimenNext->setStyleSheet(QLatin1String("QDialog{\n"
"\n"
"}\n"
"\n"
"QMenuBar{\n"
"background-color:#1d1d1d;\n"
"padding:5px;\n"
"	font: 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"QMenuBar::item{\n"
"background-color:#1d1d1d;\n"
"color:#fff;\n"
"padding:5px;\n"
"\n"
"}\n"
"\n"
"QMenu{\n"
"color:#fff;\n"
"padding:0;\n"
"}\n"
"\n"
"QMenu::item:selected{\n"
"color:#fff;\n"
"background-color:#00aba9;\n"
"}\n"
"\n"
"QTableWidget{\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"  selection-background-color: #da532c;\n"
"border:solid;\n"
"border-width:3px;\n"
"border-color:#da532c;\n"
"}\n"
"QHeaderView::section{\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"border:none;\n"
"border-top-style:solid;\n"
"border-width:1px;\n"
"border-top-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"color:#fff;\n"
"\n"
"}\n"
"QHeaderView{\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1"
                        ", y2:0, stop:0 rgba(20, 158, 217, 255), stop:1 rgba(36, 158, 217, 255));\n"
"\n"
"border:none;\n"
"border-top-style:solid;\n"
"border-width:1px;\n"
"border-top-color:#149ED9;\n"
"color:#fff;\n"
"	font: 75 12pt \"Calibri\";\n"
"}\n"
"\n"
"QTableCornerButton::section{\n"
"border:none;\n"
"background-color:#149ED9;\n"
"}\n"
"\n"
"QListWidget{\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"}\n"
"\n"
"QMenu{\n"
"background-color:#3d3d3d;\n"
"}\n"
"QStatusBar{\n"
"background-color:#7e3878;\n"
"color:#fff;\n"
"}\n"
"QComboBox\n"
"{\n"
"border-style:solid;\n"
"\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}\n"
"QPushButton:hover{\n"
"color:#ccc;\n"
"	background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(45, 45, 45, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
"	border-color:#2d89ef;\n"
"border-width:2p"
                        "x;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.517, y2:1, stop:0 rgba(29, 29, 29, 255), stop:0.505682 rgba(45, 45, 45, 255), stop:1 rgba(29, 29, 29, 255));\n"
"}\n"
"\n"
"\n"
"QTabWidget::tab{\n"
"background-color:#3d3d3d;\n"
"}\n"
"\n"
"QLineEdit{\n"
"border-radius:0;\n"
"}\n"
"\n"
"QProgressBar{\n"
"border-radius:0;\n"
"text-align:center;\n"
"color:#fff;\n"
"background-color:transparent;\n"
"border: 2px solid #e3a21a;\n"
"border-radius:7px;\n"
"	font: 75 12pt \"Open Sans\";\n"
"\n"
"}\n"
"\n"
"QProgressBar::chunk{\n"
"background-color:#2d89ef;\n"
"width:20px;\n"
"}"));
        label = new QLabel(TwoDimenNext);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 30, 181, 20));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(12);
        label->setFont(font);
        line = new QFrame(TwoDimenNext);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 60, 381, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        comboBox = new QComboBox(TwoDimenNext);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(150, 80, 111, 22));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI"));
        comboBox->setFont(font1);
        pushButton = new QPushButton(TwoDimenNext);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 130, 111, 23));
        pushButton_2 = new QPushButton(TwoDimenNext);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 260, 75, 23));
        pushButton_3 = new QPushButton(TwoDimenNext);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 260, 75, 23));
        lineEdit = new QLineEdit(TwoDimenNext);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 130, 113, 20));
        lineEdit_2 = new QLineEdit(TwoDimenNext);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 160, 113, 20));
        lineEdit_3 = new QLineEdit(TwoDimenNext);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(80, 190, 113, 20));
        label_2 = new QLabel(TwoDimenNext);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 130, 47, 13));
        label_2->setFont(font1);
        label_3 = new QLabel(TwoDimenNext);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 160, 47, 13));
        label_3->setFont(font1);
        label_4 = new QLabel(TwoDimenNext);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 190, 47, 13));
        label_4->setFont(font1);
        pushButton_4 = new QPushButton(TwoDimenNext);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(260, 160, 111, 23));

        retranslateUi(TwoDimenNext);

        QMetaObject::connectSlotsByName(TwoDimenNext);
    } // setupUi

    void retranslateUi(QDialog *TwoDimenNext)
    {
        TwoDimenNext->setWindowTitle(QApplication::translate("TwoDimenNext", "SmallBox Configuration", nullptr));
        label->setText(QApplication::translate("TwoDimenNext", "Small Box Configuration", nullptr));
        comboBox->setItemText(0, QApplication::translate("TwoDimenNext", "Small Box 1", nullptr));
        comboBox->setItemText(1, QApplication::translate("TwoDimenNext", "Small Box 2", nullptr));

        pushButton->setText(QApplication::translate("TwoDimenNext", "Save", nullptr));
        pushButton_2->setText(QApplication::translate("TwoDimenNext", "Next", nullptr));
        pushButton_3->setText(QApplication::translate("TwoDimenNext", "Exit", nullptr));
        label_2->setText(QApplication::translate("TwoDimenNext", "Width:", nullptr));
        label_3->setText(QApplication::translate("TwoDimenNext", "Height:", nullptr));
        label_4->setText(QApplication::translate("TwoDimenNext", "Length:", nullptr));
        pushButton_4->setText(QApplication::translate("TwoDimenNext", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TwoDimenNext: public Ui_TwoDimenNext {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWODIMENNEXT_H
