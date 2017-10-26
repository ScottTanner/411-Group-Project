/********************************************************************************
** Form generated from reading UI file 'showresult.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWRESULT_H
#define UI_SHOWRESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowResult
{
public:
    QTableWidget *tableWidget_ShowStacks;
    QListWidget *listWidget_ShowResult;

    void setupUi(QDialog *ShowResult)
    {
        if (ShowResult->objectName().isEmpty())
            ShowResult->setObjectName(QStringLiteral("ShowResult"));
        ShowResult->resize(716, 339);
        tableWidget_ShowStacks = new QTableWidget(ShowResult);
        if (tableWidget_ShowStacks->columnCount() < 3)
            tableWidget_ShowStacks->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_ShowStacks->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_ShowStacks->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_ShowStacks->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_ShowStacks->setObjectName(QStringLiteral("tableWidget_ShowStacks"));
        tableWidget_ShowStacks->setGeometry(QRect(380, 40, 311, 192));
        listWidget_ShowResult = new QListWidget(ShowResult);
        listWidget_ShowResult->setObjectName(QStringLiteral("listWidget_ShowResult"));
        listWidget_ShowResult->setGeometry(QRect(50, 40, 256, 192));

        retranslateUi(ShowResult);

        QMetaObject::connectSlotsByName(ShowResult);
    } // setupUi

    void retranslateUi(QDialog *ShowResult)
    {
        ShowResult->setWindowTitle(QApplication::translate("ShowResult", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_ShowStacks->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ShowResult", "Container", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_ShowStacks->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ShowResult", "Box", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_ShowStacks->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ShowResult", "Number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowResult: public Ui_ShowResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWRESULT_H
