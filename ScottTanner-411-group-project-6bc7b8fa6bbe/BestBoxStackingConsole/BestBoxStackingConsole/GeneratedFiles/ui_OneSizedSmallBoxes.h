/********************************************************************************
** Form generated from reading UI file 'OneSizedSmallBoxes.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONESIZEDSMALLBOXES_H
#define UI_ONESIZEDSMALLBOXES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_OneSized
{
public:
    QGroupBox *groupBox_Container;
    QLabel *label;
    QLineEdit *lineEdit_ContainerWidth;
    QLabel *label_2;
    QLineEdit *lineEdit_ContainerHeight;
    QLabel *label_3;
    QLineEdit *lineEdit_ContainerLength;
    QComboBox *comboBox_Containers;
    QPushButton *pushButton_ContainerSave;
    QPushButton *pushButton_ContainerDelete;
    QLabel *label_7;
    QPushButton *pushButton_Done;
    QPushButton *pushButton_DeleteCon;
    QGroupBox *groupBox_SmallBox;
    QLabel *label_4;
    QLineEdit *lineEdit_SmallBoxWidth;
    QLabel *label_5;
    QLineEdit *lineEdit_SmallBoxHeight;
    QLabel *label_6;
    QLineEdit *lineEdit_SmallBoxLength;
    QComboBox *comboBox_SmallBoxes;
    QPushButton *pushButton_SmallBoxSave;
    QPushButton *pushButton_SmallBoxDelete;
    QLabel *label_8;
    QPushButton *pushButton_Done2;
    QPushButton *pushButton_Back;
    QPushButton *pushButton_DeleteSB;
    QPushButton *pushButton_Calulate;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog_OneSized)
    {
        if (Dialog_OneSized->objectName().isEmpty())
            Dialog_OneSized->setObjectName(QStringLiteral("Dialog_OneSized"));
        Dialog_OneSized->setEnabled(true);
        Dialog_OneSized->resize(579, 412);
        QIcon icon;
        icon.addFile(QStringLiteral("Untitled-4.ico"), QSize(), QIcon::Normal, QIcon::On);
        Dialog_OneSized->setWindowIcon(icon);
        Dialog_OneSized->setStyleSheet(QLatin1String("QDialog{\n"
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
        groupBox_Container = new QGroupBox(Dialog_OneSized);
        groupBox_Container->setObjectName(QStringLiteral("groupBox_Container"));
        groupBox_Container->setEnabled(true);
        groupBox_Container->setGeometry(QRect(30, 20, 531, 161));
        label = new QLabel(groupBox_Container);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 47, 13));
        lineEdit_ContainerWidth = new QLineEdit(groupBox_Container);
        lineEdit_ContainerWidth->setObjectName(QStringLiteral("lineEdit_ContainerWidth"));
        lineEdit_ContainerWidth->setGeometry(QRect(80, 30, 141, 20));
        label_2 = new QLabel(groupBox_Container);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 47, 13));
        lineEdit_ContainerHeight = new QLineEdit(groupBox_Container);
        lineEdit_ContainerHeight->setObjectName(QStringLiteral("lineEdit_ContainerHeight"));
        lineEdit_ContainerHeight->setGeometry(QRect(80, 60, 141, 20));
        label_3 = new QLabel(groupBox_Container);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 90, 47, 13));
        lineEdit_ContainerLength = new QLineEdit(groupBox_Container);
        lineEdit_ContainerLength->setObjectName(QStringLiteral("lineEdit_ContainerLength"));
        lineEdit_ContainerLength->setGeometry(QRect(80, 90, 141, 20));
        comboBox_Containers = new QComboBox(groupBox_Container);
        comboBox_Containers->setObjectName(QStringLiteral("comboBox_Containers"));
        comboBox_Containers->setGeometry(QRect(330, 30, 191, 21));
        pushButton_ContainerSave = new QPushButton(groupBox_Container);
        pushButton_ContainerSave->setObjectName(QStringLiteral("pushButton_ContainerSave"));
        pushButton_ContainerSave->setGeometry(QRect(450, 60, 75, 23));
        pushButton_ContainerSave->setAutoDefault(false);
        pushButton_ContainerDelete = new QPushButton(groupBox_Container);
        pushButton_ContainerDelete->setObjectName(QStringLiteral("pushButton_ContainerDelete"));
        pushButton_ContainerDelete->setGeometry(QRect(10, 130, 75, 23));
        label_7 = new QLabel(groupBox_Container);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(320, 10, 47, 13));
        pushButton_Done = new QPushButton(groupBox_Container);
        pushButton_Done->setObjectName(QStringLiteral("pushButton_Done"));
        pushButton_Done->setGeometry(QRect(450, 130, 75, 23));
        pushButton_Done->setStyleSheet(QLatin1String("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#2C4167;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}"));
        pushButton_DeleteCon = new QPushButton(groupBox_Container);
        pushButton_DeleteCon->setObjectName(QStringLiteral("pushButton_DeleteCon"));
        pushButton_DeleteCon->setGeometry(QRect(450, 90, 75, 23));
        groupBox_SmallBox = new QGroupBox(Dialog_OneSized);
        groupBox_SmallBox->setObjectName(QStringLiteral("groupBox_SmallBox"));
        groupBox_SmallBox->setEnabled(true);
        groupBox_SmallBox->setGeometry(QRect(30, 190, 531, 161));
        groupBox_SmallBox->setStyleSheet(QLatin1String("QDialog{\n"
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
        label_4 = new QLabel(groupBox_SmallBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(false);
        label_4->setGeometry(QRect(20, 30, 47, 13));
        lineEdit_SmallBoxWidth = new QLineEdit(groupBox_SmallBox);
        lineEdit_SmallBoxWidth->setObjectName(QStringLiteral("lineEdit_SmallBoxWidth"));
        lineEdit_SmallBoxWidth->setEnabled(false);
        lineEdit_SmallBoxWidth->setGeometry(QRect(80, 30, 141, 20));
        label_5 = new QLabel(groupBox_SmallBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setEnabled(false);
        label_5->setGeometry(QRect(20, 60, 47, 13));
        lineEdit_SmallBoxHeight = new QLineEdit(groupBox_SmallBox);
        lineEdit_SmallBoxHeight->setObjectName(QStringLiteral("lineEdit_SmallBoxHeight"));
        lineEdit_SmallBoxHeight->setEnabled(false);
        lineEdit_SmallBoxHeight->setGeometry(QRect(80, 60, 141, 20));
        label_6 = new QLabel(groupBox_SmallBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(false);
        label_6->setGeometry(QRect(20, 90, 47, 13));
        lineEdit_SmallBoxLength = new QLineEdit(groupBox_SmallBox);
        lineEdit_SmallBoxLength->setObjectName(QStringLiteral("lineEdit_SmallBoxLength"));
        lineEdit_SmallBoxLength->setEnabled(false);
        lineEdit_SmallBoxLength->setGeometry(QRect(80, 90, 141, 20));
        comboBox_SmallBoxes = new QComboBox(groupBox_SmallBox);
        comboBox_SmallBoxes->setObjectName(QStringLiteral("comboBox_SmallBoxes"));
        comboBox_SmallBoxes->setEnabled(false);
        comboBox_SmallBoxes->setGeometry(QRect(330, 30, 191, 22));
        pushButton_SmallBoxSave = new QPushButton(groupBox_SmallBox);
        pushButton_SmallBoxSave->setObjectName(QStringLiteral("pushButton_SmallBoxSave"));
        pushButton_SmallBoxSave->setEnabled(false);
        pushButton_SmallBoxSave->setGeometry(QRect(450, 60, 75, 23));
        pushButton_SmallBoxDelete = new QPushButton(groupBox_SmallBox);
        pushButton_SmallBoxDelete->setObjectName(QStringLiteral("pushButton_SmallBoxDelete"));
        pushButton_SmallBoxDelete->setEnabled(false);
        pushButton_SmallBoxDelete->setGeometry(QRect(10, 130, 75, 23));
        label_8 = new QLabel(groupBox_SmallBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setEnabled(false);
        label_8->setGeometry(QRect(320, 10, 47, 13));
        pushButton_Done2 = new QPushButton(groupBox_SmallBox);
        pushButton_Done2->setObjectName(QStringLiteral("pushButton_Done2"));
        pushButton_Done2->setEnabled(false);
        pushButton_Done2->setGeometry(QRect(450, 130, 75, 23));
        pushButton_Done2->setStyleSheet(QLatin1String("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#2C4167;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}"));
        pushButton_Back = new QPushButton(groupBox_SmallBox);
        pushButton_Back->setObjectName(QStringLiteral("pushButton_Back"));
        pushButton_Back->setEnabled(false);
        pushButton_Back->setGeometry(QRect(360, 130, 71, 23));
        pushButton_DeleteSB = new QPushButton(groupBox_SmallBox);
        pushButton_DeleteSB->setObjectName(QStringLiteral("pushButton_DeleteSB"));
        pushButton_DeleteSB->setEnabled(false);
        pushButton_DeleteSB->setGeometry(QRect(450, 90, 75, 23));
        pushButton_Calulate = new QPushButton(Dialog_OneSized);
        pushButton_Calulate->setObjectName(QStringLiteral("pushButton_Calulate"));
        pushButton_Calulate->setEnabled(false);
        pushButton_Calulate->setGeometry(QRect(180, 370, 221, 23));
        pushButton_Calulate->setStyleSheet(QLatin1String("QPushButton{\n"
"border-style:solid;\n"
"\n"
"background-color:#3d3d3d;\n"
"color:#fff;\n"
"border-radius:7px;\n"
"}"));
        pushButton_2 = new QPushButton(Dialog_OneSized);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(470, 370, 75, 23));

        retranslateUi(Dialog_OneSized);

        QMetaObject::connectSlotsByName(Dialog_OneSized);
    } // setupUi

    void retranslateUi(QDialog *Dialog_OneSized)
    {
        Dialog_OneSized->setWindowTitle(QApplication::translate("Dialog_OneSized", "One Sized Small Boxes", nullptr));
        groupBox_Container->setTitle(QApplication::translate("Dialog_OneSized", "Container", nullptr));
        label->setText(QApplication::translate("Dialog_OneSized", "Width", nullptr));
        label_2->setText(QApplication::translate("Dialog_OneSized", "Height", nullptr));
        label_3->setText(QApplication::translate("Dialog_OneSized", "Length", nullptr));
        pushButton_ContainerSave->setText(QApplication::translate("Dialog_OneSized", "Save", nullptr));
        pushButton_ContainerDelete->setText(QApplication::translate("Dialog_OneSized", "Clear", nullptr));
        label_7->setText(QApplication::translate("Dialog_OneSized", "Load:", nullptr));
        pushButton_Done->setText(QApplication::translate("Dialog_OneSized", "Done", nullptr));
        pushButton_DeleteCon->setText(QApplication::translate("Dialog_OneSized", "Delete", nullptr));
        groupBox_SmallBox->setTitle(QApplication::translate("Dialog_OneSized", "Small Box", nullptr));
        label_4->setText(QApplication::translate("Dialog_OneSized", "Width", nullptr));
        label_5->setText(QApplication::translate("Dialog_OneSized", "Height", nullptr));
        label_6->setText(QApplication::translate("Dialog_OneSized", "Length", nullptr));
        pushButton_SmallBoxSave->setText(QApplication::translate("Dialog_OneSized", "Save", nullptr));
        pushButton_SmallBoxDelete->setText(QApplication::translate("Dialog_OneSized", "Clear", nullptr));
        label_8->setText(QApplication::translate("Dialog_OneSized", "Load:", nullptr));
        pushButton_Done2->setText(QApplication::translate("Dialog_OneSized", "Done", nullptr));
        pushButton_Back->setText(QApplication::translate("Dialog_OneSized", "Back", nullptr));
        pushButton_DeleteSB->setText(QApplication::translate("Dialog_OneSized", "Delete", nullptr));
        pushButton_Calulate->setText(QApplication::translate("Dialog_OneSized", "Calculate", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog_OneSized", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_OneSized: public Ui_Dialog_OneSized {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONESIZEDSMALLBOXES_H
