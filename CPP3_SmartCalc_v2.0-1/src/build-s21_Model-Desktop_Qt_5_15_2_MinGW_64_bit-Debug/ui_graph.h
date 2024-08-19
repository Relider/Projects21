/********************************************************************************
** Form generated from reading UI file 'graph.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Graph
{
public:
    QGridLayout *gridLayout;
    QPushButton *PlotButton;
    QLabel *labelY;
    QLineEdit *MinX;
    QLineEdit *MinY;
    QLineEdit *MaxY;
    QLabel *labelX;
    QLineEdit *MaxX;
    QCustomPlot *widget;
    QLineEdit *Display;

    void setupUi(QWidget *Graph)
    {
        if (Graph->objectName().isEmpty())
            Graph->setObjectName(QString::fromUtf8("Graph"));
        Graph->resize(689, 491);
        gridLayout = new QGridLayout(Graph);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PlotButton = new QPushButton(Graph);
        PlotButton->setObjectName(QString::fromUtf8("PlotButton"));

        gridLayout->addWidget(PlotButton, 2, 3, 1, 1);

        labelY = new QLabel(Graph);
        labelY->setObjectName(QString::fromUtf8("labelY"));

        gridLayout->addWidget(labelY, 2, 5, 1, 1);

        MinX = new QLineEdit(Graph);
        MinX->setObjectName(QString::fromUtf8("MinX"));

        gridLayout->addWidget(MinX, 2, 0, 1, 1);

        MinY = new QLineEdit(Graph);
        MinY->setObjectName(QString::fromUtf8("MinY"));

        gridLayout->addWidget(MinY, 2, 4, 1, 1);

        MaxY = new QLineEdit(Graph);
        MaxY->setObjectName(QString::fromUtf8("MaxY"));

        gridLayout->addWidget(MaxY, 2, 6, 1, 1);

        labelX = new QLabel(Graph);
        labelX->setObjectName(QString::fromUtf8("labelX"));

        gridLayout->addWidget(labelX, 2, 1, 1, 1);

        MaxX = new QLineEdit(Graph);
        MaxX->setObjectName(QString::fromUtf8("MaxX"));

        gridLayout->addWidget(MaxX, 2, 2, 1, 1);

        widget = new QCustomPlot(Graph);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout->addWidget(widget, 0, 0, 1, 7);

        Display = new QLineEdit(Graph);
        Display->setObjectName(QString::fromUtf8("Display"));

        gridLayout->addWidget(Display, 1, 0, 1, 7);


        retranslateUi(Graph);

        QMetaObject::connectSlotsByName(Graph);
    } // setupUi

    void retranslateUi(QWidget *Graph)
    {
        Graph->setWindowTitle(QCoreApplication::translate("Graph", "Form", nullptr));
        PlotButton->setText(QCoreApplication::translate("Graph", "Plot", nullptr));
        labelY->setText(QCoreApplication::translate("Graph", "Y", nullptr));
        MinX->setText(QCoreApplication::translate("Graph", "-20", nullptr));
        MinY->setText(QCoreApplication::translate("Graph", "-10", nullptr));
        MaxY->setText(QCoreApplication::translate("Graph", "10", nullptr));
        labelX->setText(QCoreApplication::translate("Graph", "X", nullptr));
        MaxX->setText(QCoreApplication::translate("Graph", "20", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graph: public Ui_Graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H
