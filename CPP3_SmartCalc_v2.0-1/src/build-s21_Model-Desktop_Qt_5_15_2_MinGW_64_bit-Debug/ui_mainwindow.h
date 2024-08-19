/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *Button_LeftBracket;
    QPushButton *Button_4;
    QPushButton *Button_Atan;
    QLineEdit *DispX;
    QPushButton *Button_8;
    QPushButton *Button_Sub;
    QPushButton *Button_Cos;
    QPushButton *Button_PlotGraph;
    QPushButton *Button_NatLog;
    QPushButton *Button_Dot;
    QPushButton *Button_Div;
    QPushButton *Button_RightBracket;
    QPushButton *Button_5;
    QPushButton *Button_6;
    QPushButton *Button_pi;
    QPushButton *Button_Acos;
    QPushButton *Button_Add;
    QPushButton *Button_9;
    QLineEdit *Display;
    QPushButton *Button_1;
    QPushButton *Button_Log;
    QPushButton *Button_Clear;
    QPushButton *Button_2;
    QPushButton *Button_Mul;
    QPushButton *Button_Degree;
    QPushButton *Button_Sin;
    QPushButton *Button_X;
    QPushButton *Button_Asin;
    QPushButton *Button_Tan;
    QPushButton *Button_7;
    QPushButton *Button_Equal;
    QPushButton *Button_0;
    QPushButton *Button_Delet;
    QPushButton *Button_e;
    QPushButton *Button_3;
    QPushButton *Button_Mod;
    QPushButton *Button_Sqrt;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Button_LeftBracket = new QPushButton(centralwidget);
        Button_LeftBracket->setObjectName(QString::fromUtf8("Button_LeftBracket"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Button_LeftBracket->sizePolicy().hasHeightForWidth());
        Button_LeftBracket->setSizePolicy(sizePolicy1);
        Button_LeftBracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_LeftBracket, 2, 9, 1, 1);

        Button_4 = new QPushButton(centralwidget);
        Button_4->setObjectName(QString::fromUtf8("Button_4"));
        sizePolicy1.setHeightForWidth(Button_4->sizePolicy().hasHeightForWidth());
        Button_4->setSizePolicy(sizePolicy1);
        Button_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #C0C0C0;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_4, 6, 6, 1, 1);

        Button_Atan = new QPushButton(centralwidget);
        Button_Atan->setObjectName(QString::fromUtf8("Button_Atan"));
        sizePolicy1.setHeightForWidth(Button_Atan->sizePolicy().hasHeightForWidth());
        Button_Atan->setSizePolicy(sizePolicy1);
        Button_Atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Atan, 8, 10, 1, 1);

        DispX = new QLineEdit(centralwidget);
        DispX->setObjectName(QString::fromUtf8("DispX"));
        sizePolicy1.setHeightForWidth(DispX->sizePolicy().hasHeightForWidth());
        DispX->setSizePolicy(sizePolicy1);
        DispX->setStyleSheet(QString::fromUtf8("font: 22pt \"Segoe UI\";"));

        gridLayout->addWidget(DispX, 2, 4, 1, 2);

        Button_8 = new QPushButton(centralwidget);
        Button_8->setObjectName(QString::fromUtf8("Button_8"));
        sizePolicy1.setHeightForWidth(Button_8->sizePolicy().hasHeightForWidth());
        Button_8->setSizePolicy(sizePolicy1);
        Button_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #C0C0C0;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_8, 5, 7, 1, 1);

        Button_Sub = new QPushButton(centralwidget);
        Button_Sub->setObjectName(QString::fromUtf8("Button_Sub"));
        sizePolicy1.setHeightForWidth(Button_Sub->sizePolicy().hasHeightForWidth());
        Button_Sub->setSizePolicy(sizePolicy1);
        Button_Sub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Sub, 8, 5, 1, 1);

        Button_Cos = new QPushButton(centralwidget);
        Button_Cos->setObjectName(QString::fromUtf8("Button_Cos"));
        sizePolicy1.setHeightForWidth(Button_Cos->sizePolicy().hasHeightForWidth());
        Button_Cos->setSizePolicy(sizePolicy1);
        Button_Cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Cos, 6, 9, 1, 1);

        Button_PlotGraph = new QPushButton(centralwidget);
        Button_PlotGraph->setObjectName(QString::fromUtf8("Button_PlotGraph"));
        sizePolicy1.setHeightForWidth(Button_PlotGraph->sizePolicy().hasHeightForWidth());
        Button_PlotGraph->setSizePolicy(sizePolicy1);
        Button_PlotGraph->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 110, 52);\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_PlotGraph, 10, 4, 1, 1);

        Button_NatLog = new QPushButton(centralwidget);
        Button_NatLog->setObjectName(QString::fromUtf8("Button_NatLog"));
        sizePolicy1.setHeightForWidth(Button_NatLog->sizePolicy().hasHeightForWidth());
        Button_NatLog->setSizePolicy(sizePolicy1);
        Button_NatLog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_NatLog, 10, 9, 1, 1);

        Button_Dot = new QPushButton(centralwidget);
        Button_Dot->setObjectName(QString::fromUtf8("Button_Dot"));
        sizePolicy1.setHeightForWidth(Button_Dot->sizePolicy().hasHeightForWidth());
        Button_Dot->setSizePolicy(sizePolicy1);
        Button_Dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 217, 67);\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Dot, 10, 6, 1, 1);

        Button_Div = new QPushButton(centralwidget);
        Button_Div->setObjectName(QString::fromUtf8("Button_Div"));
        sizePolicy1.setHeightForWidth(Button_Div->sizePolicy().hasHeightForWidth());
        Button_Div->setSizePolicy(sizePolicy1);
        Button_Div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Div, 6, 5, 1, 1);

        Button_RightBracket = new QPushButton(centralwidget);
        Button_RightBracket->setObjectName(QString::fromUtf8("Button_RightBracket"));
        sizePolicy1.setHeightForWidth(Button_RightBracket->sizePolicy().hasHeightForWidth());
        Button_RightBracket->setSizePolicy(sizePolicy1);
        Button_RightBracket->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_RightBracket, 2, 10, 1, 1);

        Button_5 = new QPushButton(centralwidget);
        Button_5->setObjectName(QString::fromUtf8("Button_5"));
        sizePolicy1.setHeightForWidth(Button_5->sizePolicy().hasHeightForWidth());
        Button_5->setSizePolicy(sizePolicy1);
        Button_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #C0C0C0;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_5, 6, 7, 1, 1);

        Button_6 = new QPushButton(centralwidget);
        Button_6->setObjectName(QString::fromUtf8("Button_6"));
        sizePolicy1.setHeightForWidth(Button_6->sizePolicy().hasHeightForWidth());
        Button_6->setSizePolicy(sizePolicy1);
        Button_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #C0C0C0;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_6, 6, 8, 1, 1);

        Button_pi = new QPushButton(centralwidget);
        Button_pi->setObjectName(QString::fromUtf8("Button_pi"));
        sizePolicy1.setHeightForWidth(Button_pi->sizePolicy().hasHeightForWidth());
        Button_pi->setSizePolicy(sizePolicy1);
        Button_pi->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 217, 67);\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_pi, 2, 8, 1, 1);

        Button_Acos = new QPushButton(centralwidget);
        Button_Acos->setObjectName(QString::fromUtf8("Button_Acos"));
        sizePolicy1.setHeightForWidth(Button_Acos->sizePolicy().hasHeightForWidth());
        Button_Acos->setSizePolicy(sizePolicy1);
        Button_Acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Acos, 6, 10, 1, 1);

        Button_Add = new QPushButton(centralwidget);
        Button_Add->setObjectName(QString::fromUtf8("Button_Add"));
        sizePolicy1.setHeightForWidth(Button_Add->sizePolicy().hasHeightForWidth());
        Button_Add->setSizePolicy(sizePolicy1);
        Button_Add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Add, 8, 4, 1, 1);

        Button_9 = new QPushButton(centralwidget);
        Button_9->setObjectName(QString::fromUtf8("Button_9"));
        sizePolicy1.setHeightForWidth(Button_9->sizePolicy().hasHeightForWidth());
        Button_9->setSizePolicy(sizePolicy1);
        Button_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #C0C0C0;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_9, 5, 8, 1, 1);

        Display = new QLineEdit(centralwidget);
        Display->setObjectName(QString::fromUtf8("Display"));
        sizePolicy1.setHeightForWidth(Display->sizePolicy().hasHeightForWidth());
        Display->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(18);
        Display->setFont(font);
        Display->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: gray;\n"
"	border: 1px solid gray;\n"
"	color: #ffffff;\n"
"}"));
        Display->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(Display, 0, 4, 2, 6);

        Button_1 = new QPushButton(centralwidget);
        Button_1->setObjectName(QString::fromUtf8("Button_1"));
        sizePolicy1.setHeightForWidth(Button_1->sizePolicy().hasHeightForWidth());
        Button_1->setSizePolicy(sizePolicy1);
        Button_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_1, 8, 6, 1, 1);

        Button_Log = new QPushButton(centralwidget);
        Button_Log->setObjectName(QString::fromUtf8("Button_Log"));
        sizePolicy1.setHeightForWidth(Button_Log->sizePolicy().hasHeightForWidth());
        Button_Log->setSizePolicy(sizePolicy1);
        Button_Log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Log, 10, 10, 1, 1);

        Button_Clear = new QPushButton(centralwidget);
        Button_Clear->setObjectName(QString::fromUtf8("Button_Clear"));
        sizePolicy1.setHeightForWidth(Button_Clear->sizePolicy().hasHeightForWidth());
        Button_Clear->setSizePolicy(sizePolicy1);
        Button_Clear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 217, 67);\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Clear, 1, 10, 1, 1);

        Button_2 = new QPushButton(centralwidget);
        Button_2->setObjectName(QString::fromUtf8("Button_2"));
        sizePolicy1.setHeightForWidth(Button_2->sizePolicy().hasHeightForWidth());
        Button_2->setSizePolicy(sizePolicy1);
        Button_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_2, 8, 7, 1, 1);

        Button_Mul = new QPushButton(centralwidget);
        Button_Mul->setObjectName(QString::fromUtf8("Button_Mul"));
        sizePolicy1.setHeightForWidth(Button_Mul->sizePolicy().hasHeightForWidth());
        Button_Mul->setSizePolicy(sizePolicy1);
        Button_Mul->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Mul, 6, 4, 1, 1);

        Button_Degree = new QPushButton(centralwidget);
        Button_Degree->setObjectName(QString::fromUtf8("Button_Degree"));
        sizePolicy1.setHeightForWidth(Button_Degree->sizePolicy().hasHeightForWidth());
        Button_Degree->setSizePolicy(sizePolicy1);
        Button_Degree->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Degree, 5, 4, 1, 1);

        Button_Sin = new QPushButton(centralwidget);
        Button_Sin->setObjectName(QString::fromUtf8("Button_Sin"));
        sizePolicy1.setHeightForWidth(Button_Sin->sizePolicy().hasHeightForWidth());
        Button_Sin->setSizePolicy(sizePolicy1);
        Button_Sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Sin, 5, 9, 1, 1);

        Button_X = new QPushButton(centralwidget);
        Button_X->setObjectName(QString::fromUtf8("Button_X"));
        sizePolicy1.setHeightForWidth(Button_X->sizePolicy().hasHeightForWidth());
        Button_X->setSizePolicy(sizePolicy1);
        Button_X->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 217, 67);\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_X, 2, 6, 1, 1);

        Button_Asin = new QPushButton(centralwidget);
        Button_Asin->setObjectName(QString::fromUtf8("Button_Asin"));
        sizePolicy1.setHeightForWidth(Button_Asin->sizePolicy().hasHeightForWidth());
        Button_Asin->setSizePolicy(sizePolicy1);
        Button_Asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Asin, 5, 10, 1, 1);

        Button_Tan = new QPushButton(centralwidget);
        Button_Tan->setObjectName(QString::fromUtf8("Button_Tan"));
        sizePolicy1.setHeightForWidth(Button_Tan->sizePolicy().hasHeightForWidth());
        Button_Tan->setSizePolicy(sizePolicy1);
        Button_Tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Tan, 8, 9, 1, 1);

        Button_7 = new QPushButton(centralwidget);
        Button_7->setObjectName(QString::fromUtf8("Button_7"));
        sizePolicy1.setHeightForWidth(Button_7->sizePolicy().hasHeightForWidth());
        Button_7->setSizePolicy(sizePolicy1);
        Button_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_7, 5, 6, 1, 1);

        Button_Equal = new QPushButton(centralwidget);
        Button_Equal->setObjectName(QString::fromUtf8("Button_Equal"));
        sizePolicy1.setHeightForWidth(Button_Equal->sizePolicy().hasHeightForWidth());
        Button_Equal->setSizePolicy(sizePolicy1);
        Button_Equal->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 110, 52);\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Equal, 10, 5, 1, 1);

        Button_0 = new QPushButton(centralwidget);
        Button_0->setObjectName(QString::fromUtf8("Button_0"));
        sizePolicy1.setHeightForWidth(Button_0->sizePolicy().hasHeightForWidth());
        Button_0->setSizePolicy(sizePolicy1);
        Button_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #C0C0C0;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_0, 10, 7, 1, 1);

        Button_Delet = new QPushButton(centralwidget);
        Button_Delet->setObjectName(QString::fromUtf8("Button_Delet"));
        sizePolicy1.setHeightForWidth(Button_Delet->sizePolicy().hasHeightForWidth());
        Button_Delet->setSizePolicy(sizePolicy1);
        Button_Delet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 217, 67);\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Delet, 0, 10, 1, 1);

        Button_e = new QPushButton(centralwidget);
        Button_e->setObjectName(QString::fromUtf8("Button_e"));
        sizePolicy1.setHeightForWidth(Button_e->sizePolicy().hasHeightForWidth());
        Button_e->setSizePolicy(sizePolicy1);
        Button_e->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 217, 67);\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_e, 2, 7, 1, 1);

        Button_3 = new QPushButton(centralwidget);
        Button_3->setObjectName(QString::fromUtf8("Button_3"));
        sizePolicy1.setHeightForWidth(Button_3->sizePolicy().hasHeightForWidth());
        Button_3->setSizePolicy(sizePolicy1);
        Button_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #C0C0C0;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"border: 1px solid gray;\n"
"padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_3, 8, 8, 1, 1);

        Button_Mod = new QPushButton(centralwidget);
        Button_Mod->setObjectName(QString::fromUtf8("Button_Mod"));
        sizePolicy1.setHeightForWidth(Button_Mod->sizePolicy().hasHeightForWidth());
        Button_Mod->setSizePolicy(sizePolicy1);
        Button_Mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Mod, 5, 5, 1, 1);

        Button_Sqrt = new QPushButton(centralwidget);
        Button_Sqrt->setObjectName(QString::fromUtf8("Button_Sqrt"));
        sizePolicy1.setHeightForWidth(Button_Sqrt->sizePolicy().hasHeightForWidth());
        Button_Sqrt->setSizePolicy(sizePolicy1);
        Button_Sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button_Sqrt, 10, 8, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Button_LeftBracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        Button_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        Button_Atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        DispX->setText(QString());
        Button_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        Button_Sub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        Button_Cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        Button_PlotGraph->setText(QCoreApplication::translate("MainWindow", "plot graph", nullptr));
        Button_NatLog->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        Button_Dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        Button_Div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        Button_RightBracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        Button_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        Button_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        Button_pi->setText(QCoreApplication::translate("MainWindow", "pi", nullptr));
        Button_Acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        Button_Add->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        Button_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        Display->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        Button_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        Button_Log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        Button_Clear->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        Button_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        Button_Mul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        Button_Degree->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        Button_Sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        Button_X->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        Button_Asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        Button_Tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        Button_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        Button_Equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        Button_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Button_Delet->setText(QCoreApplication::translate("MainWindow", "del", nullptr));
        Button_e->setText(QCoreApplication::translate("MainWindow", "e", nullptr));
        Button_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        Button_Mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        Button_Sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
