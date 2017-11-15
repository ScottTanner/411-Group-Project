/********************************************************************************
** Form generated from reading UI file 'boxstacking.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOXSTACKING_H
#define UI_BOXSTACKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExport;
    QAction *actionExit;
    QAction *actionOne_Sized_Small_Boxes;
    QAction *actionDiffrent_Siezed_Small_Boxes;
    QWidget *centralwidget;
    QTabWidget *tabWidge_Models;
    QWidget *tab;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBoxContainer;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_ContainerWidth;
    QLabel *label_2;
    QLineEdit *lineEdit_ContainerHeight;
    QLabel *label_3;
    QLineEdit *lineEdit_ContainerLength;
    QGroupBox *groupBoxContainer_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit_SmallBoxWidth;
    QLabel *label_5;
    QLineEdit *lineEdit_SmallBoxHeight;
    QLabel *label_6;
    QLineEdit *lineEdit_SmallBoxLength;
    QTableWidget *tableWidget_Result;
    QPushButton *pushButton_SaveValues;
    QCommandLinkButton *commandLinkButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuNew;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(951, 681);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionOne_Sized_Small_Boxes = new QAction(MainWindow);
        actionOne_Sized_Small_Boxes->setObjectName(QStringLiteral("actionOne_Sized_Small_Boxes"));
        actionDiffrent_Siezed_Small_Boxes = new QAction(MainWindow);
        actionDiffrent_Siezed_Small_Boxes->setObjectName(QStringLiteral("actionDiffrent_Siezed_Small_Boxes"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidge_Models = new QTabWidget(centralwidget);
        tabWidge_Models->setObjectName(QStringLiteral("tabWidge_Models"));
        tabWidge_Models->setGeometry(QRect(290, 0, 1081, 871));
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
        groupBoxContainer = new QGroupBox(centralwidget);
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

        groupBoxContainer_2 = new QGroupBox(centralwidget);
        groupBoxContainer_2->setObjectName(QStringLiteral("groupBoxContainer_2"));
        groupBoxContainer_2->setGeometry(QRect(0, 170, 271, 171));
        gridLayout_2 = new QGridLayout(groupBoxContainer_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_4 = new QLabel(groupBoxContainer_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_SmallBoxWidth = new QLineEdit(groupBoxContainer_2);
        lineEdit_SmallBoxWidth->setObjectName(QStringLiteral("lineEdit_SmallBoxWidth"));
        lineEdit_SmallBoxWidth->setEnabled(false);

        gridLayout_2->addWidget(lineEdit_SmallBoxWidth, 0, 1, 1, 1);

        label_5 = new QLabel(groupBoxContainer_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        lineEdit_SmallBoxHeight = new QLineEdit(groupBoxContainer_2);
        lineEdit_SmallBoxHeight->setObjectName(QStringLiteral("lineEdit_SmallBoxHeight"));
        lineEdit_SmallBoxHeight->setEnabled(false);

        gridLayout_2->addWidget(lineEdit_SmallBoxHeight, 1, 1, 1, 1);

        label_6 = new QLabel(groupBoxContainer_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        lineEdit_SmallBoxLength = new QLineEdit(groupBoxContainer_2);
        lineEdit_SmallBoxLength->setObjectName(QStringLiteral("lineEdit_SmallBoxLength"));
        lineEdit_SmallBoxLength->setEnabled(false);

        gridLayout_2->addWidget(lineEdit_SmallBoxLength, 2, 1, 1, 1);

        tableWidget_Result = new QTableWidget(centralwidget);
        tableWidget_Result->setObjectName(QStringLiteral("tableWidget_Result"));
        tableWidget_Result->setGeometry(QRect(10, 380, 271, 391));
        pushButton_SaveValues = new QPushButton(centralwidget);
        pushButton_SaveValues->setObjectName(QStringLiteral("pushButton_SaveValues"));
        pushButton_SaveValues->setGeometry(QRect(100, 800, 75, 23));
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(190, 340, 101, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 951, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuNew = new QMenu(menuFile);
        menuNew->setObjectName(QStringLiteral("menuNew"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(menuNew->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExport);
        menuFile->addAction(actionExit);
        menuNew->addAction(actionOne_Sized_Small_Boxes);
        menuNew->addAction(actionDiffrent_Siezed_Small_Boxes);

        retranslateUi(MainWindow);

        tabWidge_Models->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BestBoxStacking", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
        actionExport->setText(QApplication::translate("MainWindow", "Export", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionOne_Sized_Small_Boxes->setText(QApplication::translate("MainWindow", "One Sized Small Boxes", nullptr));
        actionDiffrent_Siezed_Small_Boxes->setText(QApplication::translate("MainWindow", "Diffrent Sized Small Boxes", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        tabWidge_Models->setTabText(tabWidge_Models->indexOf(tab), QApplication::translate("MainWindow", "2D", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        tabWidge_Models->setTabText(tabWidge_Models->indexOf(tab_2), QApplication::translate("MainWindow", "3D", nullptr));
        groupBoxContainer->setTitle(QApplication::translate("MainWindow", "Container", nullptr));
        label->setText(QApplication::translate("MainWindow", "Width", nullptr));
        lineEdit_ContainerWidth->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Height", nullptr));
        lineEdit_ContainerHeight->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Length", nullptr));
        lineEdit_ContainerLength->setText(QString());
        groupBoxContainer_2->setTitle(QApplication::translate("MainWindow", "Small Box", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Width", nullptr));
        lineEdit_SmallBoxWidth->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Height", nullptr));
        lineEdit_SmallBoxHeight->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Length", nullptr));
        lineEdit_SmallBoxLength->setText(QString());
        pushButton_SaveValues->setText(QApplication::translate("MainWindow", "Save", nullptr));
        commandLinkButton->setText(QApplication::translate("MainWindow", "Visualize", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuNew->setTitle(QApplication::translate("MainWindow", "New", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOXSTACKING_H
