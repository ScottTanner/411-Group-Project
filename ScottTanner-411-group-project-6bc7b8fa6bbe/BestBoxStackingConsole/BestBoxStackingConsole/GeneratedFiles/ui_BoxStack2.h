/********************************************************************************
** Form generated from reading UI file 'BoxStack2.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOXSTACK2_H
#define UI_BOXSTACK2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoxStack2
{
public:
    QGroupBox *groupBoxContainer_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_SmallBoxHeight;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_SmallBoxWidth;
    QLineEdit *lineEdit_SmallBoxLength;
    QPushButton *pushButton_SaveValues;
    QCommandLinkButton *commandLinkButton;
    QGroupBox *groupBoxContainer;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_ContainerWidth;
    QLabel *label_2;
    QLineEdit *lineEdit_ContainerHeight;
    QLabel *label_3;
    QLineEdit *lineEdit_ContainerLength;
    QTabWidget *tabWidge_Models;
    QWidget *tab;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QPushButton *pushButton_3;
    QWidget *tab_3;
    QPushButton *pushButton_Config;
    QTableWidget *tableWidget_Result;
    QPushButton *pushButton_Exit;

    void setupUi(QDialog *BoxStack2)
    {
        if (BoxStack2->objectName().isEmpty())
            BoxStack2->setObjectName(QStringLiteral("BoxStack2"));
        BoxStack2->setEnabled(true);
        BoxStack2->resize(990, 701);
        groupBoxContainer_2 = new QGroupBox(BoxStack2);
        groupBoxContainer_2->setObjectName(QStringLiteral("groupBoxContainer_2"));
        groupBoxContainer_2->setGeometry(QRect(0, 170, 271, 171));
        gridLayout_2 = new QGridLayout(groupBoxContainer_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lineEdit_SmallBoxHeight = new QLineEdit(groupBoxContainer_2);
        lineEdit_SmallBoxHeight->setObjectName(QStringLiteral("lineEdit_SmallBoxHeight"));
        lineEdit_SmallBoxHeight->setEnabled(false);

        gridLayout_2->addWidget(lineEdit_SmallBoxHeight, 1, 1, 1, 1);

        label_4 = new QLabel(groupBoxContainer_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(groupBoxContainer_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(groupBoxContainer_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        lineEdit_SmallBoxWidth = new QLineEdit(groupBoxContainer_2);
        lineEdit_SmallBoxWidth->setObjectName(QStringLiteral("lineEdit_SmallBoxWidth"));
        lineEdit_SmallBoxWidth->setEnabled(false);

        gridLayout_2->addWidget(lineEdit_SmallBoxWidth, 0, 1, 1, 1);

        lineEdit_SmallBoxLength = new QLineEdit(groupBoxContainer_2);
        lineEdit_SmallBoxLength->setObjectName(QStringLiteral("lineEdit_SmallBoxLength"));
        lineEdit_SmallBoxLength->setEnabled(false);

        gridLayout_2->addWidget(lineEdit_SmallBoxLength, 2, 1, 1, 1);

        pushButton_SaveValues = new QPushButton(BoxStack2);
        pushButton_SaveValues->setObjectName(QStringLiteral("pushButton_SaveValues"));
        pushButton_SaveValues->setGeometry(QRect(100, 800, 75, 23));
        commandLinkButton = new QCommandLinkButton(BoxStack2);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(190, 340, 101, 41));
        groupBoxContainer = new QGroupBox(BoxStack2);
        groupBoxContainer->setObjectName(QStringLiteral("groupBoxContainer"));
        groupBoxContainer->setGeometry(QRect(0, 0, 271, 171));
        gridLayout = new QGridLayout(groupBoxContainer);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBoxContainer);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_ContainerWidth = new QLineEdit(groupBoxContainer);
        lineEdit_ContainerWidth->setObjectName(QStringLiteral("lineEdit_ContainerWidth"));
        lineEdit_ContainerWidth->setEnabled(false);

        gridLayout->addWidget(lineEdit_ContainerWidth, 0, 1, 1, 1);

        label_2 = new QLabel(groupBoxContainer);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_ContainerHeight = new QLineEdit(groupBoxContainer);
        lineEdit_ContainerHeight->setObjectName(QStringLiteral("lineEdit_ContainerHeight"));
        lineEdit_ContainerHeight->setEnabled(false);

        gridLayout->addWidget(lineEdit_ContainerHeight, 1, 1, 1, 1);

        label_3 = new QLabel(groupBoxContainer);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_ContainerLength = new QLineEdit(groupBoxContainer);
        lineEdit_ContainerLength->setObjectName(QStringLiteral("lineEdit_ContainerLength"));
        lineEdit_ContainerLength->setEnabled(false);

        gridLayout->addWidget(lineEdit_ContainerLength, 2, 1, 1, 1);

        tabWidge_Models = new QTabWidget(BoxStack2);
        tabWidge_Models->setObjectName(QStringLiteral("tabWidge_Models"));
        tabWidge_Models->setGeometry(QRect(290, 10, 691, 651));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 170, 75, 23));
        tabWidge_Models->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 220, 75, 23));
        tabWidge_Models->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidge_Models->addTab(tab_3, QString());
        pushButton_Config = new QPushButton(BoxStack2);
        pushButton_Config->setObjectName(QStringLiteral("pushButton_Config"));
        pushButton_Config->setGeometry(QRect(20, 350, 151, 23));
        tableWidget_Result = new QTableWidget(BoxStack2);
        tableWidget_Result->setObjectName(QStringLiteral("tableWidget_Result"));
        tableWidget_Result->setGeometry(QRect(10, 380, 271, 311));
        pushButton_Exit = new QPushButton(BoxStack2);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(880, 670, 101, 23));

        retranslateUi(BoxStack2);

        tabWidge_Models->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(BoxStack2);
    } // setupUi

    void retranslateUi(QDialog *BoxStack2)
    {
        BoxStack2->setWindowTitle(QApplication::translate("BoxStack2", "Dialog", nullptr));
        groupBoxContainer_2->setTitle(QApplication::translate("BoxStack2", "Small Box", nullptr));
        lineEdit_SmallBoxHeight->setText(QString());
        label_4->setText(QApplication::translate("BoxStack2", "Width", nullptr));
        label_5->setText(QApplication::translate("BoxStack2", "Height", nullptr));
        label_6->setText(QApplication::translate("BoxStack2", "Length", nullptr));
        lineEdit_SmallBoxWidth->setText(QString());
        lineEdit_SmallBoxLength->setText(QString());
        pushButton_SaveValues->setText(QApplication::translate("BoxStack2", "Save", nullptr));
        commandLinkButton->setText(QApplication::translate("BoxStack2", "Visualize", nullptr));
        groupBoxContainer->setTitle(QApplication::translate("BoxStack2", "Container", nullptr));
        label->setText(QApplication::translate("BoxStack2", "Width", nullptr));
        lineEdit_ContainerWidth->setText(QString());
        label_2->setText(QApplication::translate("BoxStack2", "Height", nullptr));
        lineEdit_ContainerHeight->setText(QString());
        label_3->setText(QApplication::translate("BoxStack2", "Length", nullptr));
        lineEdit_ContainerLength->setText(QString());
        pushButton_2->setText(QApplication::translate("BoxStack2", "PushButton", nullptr));
        tabWidge_Models->setTabText(tabWidge_Models->indexOf(tab), QApplication::translate("BoxStack2", "2D", nullptr));
        pushButton_3->setText(QApplication::translate("BoxStack2", "PushButton", nullptr));
        tabWidge_Models->setTabText(tabWidge_Models->indexOf(tab_2), QApplication::translate("BoxStack2", "3D", nullptr));
        tabWidge_Models->setTabText(tabWidge_Models->indexOf(tab_3), QApplication::translate("BoxStack2", "Data", nullptr));
        pushButton_Config->setText(QApplication::translate("BoxStack2", "Configure", nullptr));
        pushButton_Exit->setText(QApplication::translate("BoxStack2", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BoxStack2: public Ui_BoxStack2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOXSTACK2_H
