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
    QComboBox *comboBox_Container;
    QLineEdit *lineEdit_Width;
    QLineEdit *lineEdit_Height;
    QLineEdit *lineEdit_Length;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_Save;
    QPushButton *pushButton_Next;
    QPushButton *pushButton_Exit;
    QPushButton *pushButton_Clear;

    void setupUi(QDialog *TwoDimen)
    {
        if (TwoDimen->objectName().isEmpty())
            TwoDimen->setObjectName(QStringLiteral("TwoDimen"));
        TwoDimen->resize(400, 300);
        TwoDimen->setMaximumSize(QSize(400, 300));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        TwoDimen->setFont(font);
        TwoDimen->setStyleSheet(QLatin1String("QDialog{\n"
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
        label = new QLabel(TwoDimen);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 30, 181, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI"));
        font1.setPointSize(12);
        label->setFont(font1);
        line = new QFrame(TwoDimen);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 60, 381, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        comboBox_Container = new QComboBox(TwoDimen);
        comboBox_Container->addItem(QString());
        comboBox_Container->addItem(QString());
        comboBox_Container->setObjectName(QStringLiteral("comboBox_Container"));
        comboBox_Container->setGeometry(QRect(150, 80, 111, 22));
        comboBox_Container->setFont(font);
        lineEdit_Width = new QLineEdit(TwoDimen);
        lineEdit_Width->setObjectName(QStringLiteral("lineEdit_Width"));
        lineEdit_Width->setGeometry(QRect(70, 120, 121, 20));
        lineEdit_Height = new QLineEdit(TwoDimen);
        lineEdit_Height->setObjectName(QStringLiteral("lineEdit_Height"));
        lineEdit_Height->setGeometry(QRect(70, 150, 121, 20));
        lineEdit_Length = new QLineEdit(TwoDimen);
        lineEdit_Length->setObjectName(QStringLiteral("lineEdit_Length"));
        lineEdit_Length->setGeometry(QRect(70, 180, 121, 20));
        label_2 = new QLabel(TwoDimen);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 120, 41, 16));
        label_2->setFont(font);
        label_3 = new QLabel(TwoDimen);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 150, 41, 16));
        label_3->setFont(font);
        label_4 = new QLabel(TwoDimen);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 180, 47, 13));
        label_4->setFont(font);
        pushButton_Save = new QPushButton(TwoDimen);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));
        pushButton_Save->setGeometry(QRect(240, 120, 111, 23));
        pushButton_Save->setFont(font);
        pushButton_Next = new QPushButton(TwoDimen);
        pushButton_Next->setObjectName(QStringLiteral("pushButton_Next"));
        pushButton_Next->setGeometry(QRect(10, 260, 75, 23));
        pushButton_Exit = new QPushButton(TwoDimen);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(300, 260, 75, 23));
        pushButton_Clear = new QPushButton(TwoDimen);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(240, 150, 111, 23));

        retranslateUi(TwoDimen);

        QMetaObject::connectSlotsByName(TwoDimen);
    } // setupUi

    void retranslateUi(QDialog *TwoDimen)
    {
        TwoDimen->setWindowTitle(QApplication::translate("TwoDimen", "Container Configuration", nullptr));
        label->setText(QApplication::translate("TwoDimen", "Container Configuration", nullptr));
        comboBox_Container->setItemText(0, QApplication::translate("TwoDimen", "Container 1", nullptr));
        comboBox_Container->setItemText(1, QApplication::translate("TwoDimen", "Container 2", nullptr));

        label_2->setText(QApplication::translate("TwoDimen", "Width:", nullptr));
        label_3->setText(QApplication::translate("TwoDimen", "Height:", nullptr));
        label_4->setText(QApplication::translate("TwoDimen", "Length:", nullptr));
        pushButton_Save->setText(QApplication::translate("TwoDimen", "Save", nullptr));
        pushButton_Next->setText(QApplication::translate("TwoDimen", "Next", nullptr));
        pushButton_Exit->setText(QApplication::translate("TwoDimen", "Exit", nullptr));
        pushButton_Clear->setText(QApplication::translate("TwoDimen", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TwoDimen: public Ui_TwoDimen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWODIMEN_H
