/********************************************************************************
** Form generated from reading UI file 'calculate.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATE_H
#define UI_CALCULATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Calculate
{
public:
    QLabel *label;
    QFrame *line;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *boxY;
    QLabel *boxZ;
    QLabel *containerX;
    QLabel *containerY;
    QLabel *containerZ;
    QLabel *boxX;

    void setupUi(QDialog *Calculate)
    {
        if (Calculate->objectName().isEmpty())
            Calculate->setObjectName(QStringLiteral("Calculate"));
        Calculate->resize(316, 272);
        Calculate->setMinimumSize(QSize(316, 272));
        Calculate->setMaximumSize(QSize(316, 272));
        Calculate->setStyleSheet(QLatin1String("QDialog{\n"
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
        label = new QLabel(Calculate);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 20, 61, 20));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(12);
        label->setFont(font);
        line = new QFrame(Calculate);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 80, 281, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(Calculate);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 60, 61, 16));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI"));
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_3 = new QLabel(Calculate);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 110, 47, 13));
        QFont font2;
        font2.setFamily(QStringLiteral("Segoe UI"));
        label_3->setFont(font2);
        label_4 = new QLabel(Calculate);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 140, 47, 13));
        label_4->setFont(font2);
        label_5 = new QLabel(Calculate);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 170, 47, 13));
        label_5->setFont(font2);
        label_6 = new QLabel(Calculate);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(200, 60, 71, 20));
        label_6->setFont(font1);
        label_7 = new QLabel(Calculate);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(200, 110, 47, 13));
        label_7->setFont(font2);
        label_8 = new QLabel(Calculate);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(200, 140, 47, 13));
        label_8->setFont(font2);
        label_9 = new QLabel(Calculate);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(200, 170, 47, 13));
        label_9->setFont(font2);
        pushButton = new QPushButton(Calculate);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 230, 75, 23));
        pushButton_2 = new QPushButton(Calculate);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 230, 75, 23));
        boxY = new QLabel(Calculate);
        boxY->setObjectName(QStringLiteral("boxY"));
        boxY->setGeometry(QRect(80, 140, 47, 13));
        boxZ = new QLabel(Calculate);
        boxZ->setObjectName(QStringLiteral("boxZ"));
        boxZ->setGeometry(QRect(80, 170, 47, 13));
        containerX = new QLabel(Calculate);
        containerX->setObjectName(QStringLiteral("containerX"));
        containerX->setGeometry(QRect(260, 110, 47, 13));
        containerY = new QLabel(Calculate);
        containerY->setObjectName(QStringLiteral("containerY"));
        containerY->setGeometry(QRect(260, 140, 47, 13));
        containerZ = new QLabel(Calculate);
        containerZ->setObjectName(QStringLiteral("containerZ"));
        containerZ->setGeometry(QRect(260, 170, 47, 13));
        boxX = new QLabel(Calculate);
        boxX->setObjectName(QStringLiteral("boxX"));
        boxX->setGeometry(QRect(80, 110, 47, 13));

        retranslateUi(Calculate);

        QMetaObject::connectSlotsByName(Calculate);
    } // setupUi

    void retranslateUi(QDialog *Calculate)
    {
        Calculate->setWindowTitle(QApplication::translate("Calculate", "Calculate", nullptr));
        label->setText(QApplication::translate("Calculate", "Input", nullptr));
        label_2->setText(QApplication::translate("Calculate", "Small Box:", nullptr));
        label_3->setText(QApplication::translate("Calculate", "Width:", nullptr));
        label_4->setText(QApplication::translate("Calculate", "Height:", nullptr));
        label_5->setText(QApplication::translate("Calculate", "Length:", nullptr));
        label_6->setText(QApplication::translate("Calculate", "Container:", nullptr));
        label_7->setText(QApplication::translate("Calculate", "Width:", nullptr));
        label_8->setText(QApplication::translate("Calculate", "Height:", nullptr));
        label_9->setText(QApplication::translate("Calculate", "Length:", nullptr));
        pushButton->setText(QApplication::translate("Calculate", "Exit", nullptr));
        pushButton_2->setText(QApplication::translate("Calculate", "Continue", nullptr));
        boxY->setText(QString());
        boxZ->setText(QString());
        containerX->setText(QString());
        containerY->setText(QString());
        containerZ->setText(QString());
        boxX->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Calculate: public Ui_Calculate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATE_H
