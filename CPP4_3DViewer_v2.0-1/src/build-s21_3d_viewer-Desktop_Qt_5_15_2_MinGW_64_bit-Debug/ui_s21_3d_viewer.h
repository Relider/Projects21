/********************************************************************************
** Form generated from reading UI file 's21_3d_viewer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S21_3D_VIEWER_H
#define UI_S21_3D_VIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_s21_3d_viewer
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *s21_3d_viewer)
    {
        if (s21_3d_viewer->objectName().isEmpty())
            s21_3d_viewer->setObjectName(QString::fromUtf8("s21_3d_viewer"));
        s21_3d_viewer->resize(800, 600);
        centralwidget = new QWidget(s21_3d_viewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        s21_3d_viewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(s21_3d_viewer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        s21_3d_viewer->setMenuBar(menubar);
        statusbar = new QStatusBar(s21_3d_viewer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        s21_3d_viewer->setStatusBar(statusbar);

        retranslateUi(s21_3d_viewer);

        QMetaObject::connectSlotsByName(s21_3d_viewer);
    } // setupUi

    void retranslateUi(QMainWindow *s21_3d_viewer)
    {
        s21_3d_viewer->setWindowTitle(QCoreApplication::translate("s21_3d_viewer", "s21_3d_viewer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class s21_3d_viewer: public Ui_s21_3d_viewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S21_3D_VIEWER_H
