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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExport;
    QAction *actionExit;
    QAction *actionOne_Sized_Small_Boxes;
    QAction *actionDiffrent_Siezed_Small_Boxes;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionEdit_Boxes;
    QAction *actionAbout_BestBoxStacking;
    QAction *actionChange_Color_2D;
    QAction *actionChange_Color_3D;
    QAction *actionNight_View;
    QAction *action_ber_BestBoxStacking;
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QWidget *widget;
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
    QPushButton *pushButton_SaveValues;
    QListWidget *listWidget_Result;
    QTabWidget *tabWidge_Models;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget_ShowStacks;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QGraphicsView *graphicsView_TwoDim;
    QWidget *tab_2;
    QGridLayout *gridLayout_6;
    GLWidget *widget_GL;
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
        MainWindow->resize(1126, 872);
        QIcon icon;
        icon.addFile(QStringLiteral("Untitled-4.ico"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QLatin1String("QDialog{\n"
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
        actionDiffrent_Siezed_Small_Boxes->setEnabled(false);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionUndo->setEnabled(false);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionRedo->setEnabled(false);
        actionEdit_Boxes = new QAction(MainWindow);
        actionEdit_Boxes->setObjectName(QStringLiteral("actionEdit_Boxes"));
        actionEdit_Boxes->setEnabled(false);
        actionAbout_BestBoxStacking = new QAction(MainWindow);
        actionAbout_BestBoxStacking->setObjectName(QStringLiteral("actionAbout_BestBoxStacking"));
        actionChange_Color_2D = new QAction(MainWindow);
        actionChange_Color_2D->setObjectName(QStringLiteral("actionChange_Color_2D"));
        actionChange_Color_3D = new QAction(MainWindow);
        actionChange_Color_3D->setObjectName(QStringLiteral("actionChange_Color_3D"));
        actionNight_View = new QAction(MainWindow);
        actionNight_View->setObjectName(QStringLiteral("actionNight_View"));
        action_ber_BestBoxStacking = new QAction(MainWindow);
        action_ber_BestBoxStacking->setObjectName(QStringLiteral("action_ber_BestBoxStacking"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(276, 0));
        widget->setMaximumSize(QSize(276, 16777215));
        groupBoxContainer = new QGroupBox(widget);
        groupBoxContainer->setObjectName(QStringLiteral("groupBoxContainer"));
        groupBoxContainer->setGeometry(QRect(0, 10, 271, 171));
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

        groupBoxContainer_2 = new QGroupBox(widget);
        groupBoxContainer_2->setObjectName(QStringLiteral("groupBoxContainer_2"));
        groupBoxContainer_2->setGeometry(QRect(0, 190, 271, 171));
        groupBoxContainer_2->setStyleSheet(QStringLiteral(""));
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

        pushButton_SaveValues = new QPushButton(widget);
        pushButton_SaveValues->setObjectName(QStringLiteral("pushButton_SaveValues"));
        pushButton_SaveValues->setEnabled(false);
        pushButton_SaveValues->setGeometry(QRect(90, 740, 75, 23));
        listWidget_Result = new QListWidget(widget);
        listWidget_Result->setObjectName(QStringLiteral("listWidget_Result"));
        listWidget_Result->setGeometry(QRect(10, 410, 256, 321));

        gridLayout_4->addWidget(widget, 0, 0, 1, 1);

        tabWidge_Models = new QTabWidget(centralwidget);
        tabWidge_Models->setObjectName(QStringLiteral("tabWidge_Models"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableWidget_ShowStacks = new QTableWidget(tab_3);
        if (tableWidget_ShowStacks->columnCount() < 3)
            tableWidget_ShowStacks->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_ShowStacks->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_ShowStacks->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_ShowStacks->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_ShowStacks->setObjectName(QStringLiteral("tableWidget_ShowStacks"));

        gridLayout_3->addWidget(tableWidget_ShowStacks, 0, 0, 1, 1);

        tabWidge_Models->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        graphicsView_TwoDim = new QGraphicsView(tab);
        graphicsView_TwoDim->setObjectName(QStringLiteral("graphicsView_TwoDim"));

        gridLayout_5->addWidget(graphicsView_TwoDim, 0, 0, 1, 1);

        tabWidge_Models->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_6 = new QGridLayout(tab_2);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        widget_GL = new GLWidget(tab_2);
        widget_GL->setObjectName(QStringLiteral("widget_GL"));

        gridLayout_6->addWidget(widget_GL, 0, 0, 1, 1);

        tabWidge_Models->addTab(tab_2, QString());

        gridLayout_4->addWidget(tabWidge_Models, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1126, 40));
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
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addAction(actionEdit_Boxes);
        menuView->addAction(actionChange_Color_2D);
        menuView->addAction(actionChange_Color_3D);
        menuView->addAction(actionNight_View);
        menuHelp->addAction(actionAbout_BestBoxStacking);
        menuHelp->addAction(action_ber_BestBoxStacking);

        retranslateUi(MainWindow);

        tabWidge_Models->setCurrentIndex(0);


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
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", nullptr));
        actionEdit_Boxes->setText(QApplication::translate("MainWindow", "Edit Boxes", nullptr));
        actionAbout_BestBoxStacking->setText(QApplication::translate("MainWindow", "About BestBoxStacking", nullptr));
        actionChange_Color_2D->setText(QApplication::translate("MainWindow", "Change Color 2D", nullptr));
        actionChange_Color_3D->setText(QApplication::translate("MainWindow", "Change Color 3D", nullptr));
        actionNight_View->setText(QApplication::translate("MainWindow", "Day/Night View", nullptr));
        action_ber_BestBoxStacking->setText(QApplication::translate("MainWindow", "\303\234ber BestBoxStacking", nullptr));
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
        QTableWidgetItem *___qtablewidgetitem = tableWidget_ShowStacks->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Containers", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_ShowStacks->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Box", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_ShowStacks->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Number", nullptr));
        tabWidge_Models->setTabText(tabWidge_Models->indexOf(tab_3), QApplication::translate("MainWindow", "Data", nullptr));
        tabWidge_Models->setTabText(tabWidge_Models->indexOf(tab), QApplication::translate("MainWindow", "2D", nullptr));
        tabWidge_Models->setTabText(tabWidge_Models->indexOf(tab_2), QApplication::translate("MainWindow", "3D", nullptr));
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
