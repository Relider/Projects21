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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "glview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *about_model_lable;
    QLabel *model_name_lable;
    QPushButton *gif_button;
    QPushButton *screenshot_button;
    QLabel *move_lable;
    QLabel *x_move_lable;
    QDoubleSpinBox *x_move_spin_box;
    QLabel *y_move_lable;
    QDoubleSpinBox *y_move_spin_box;
    QLabel *z_move_lable;
    QDoubleSpinBox *z_move_spin_box;
    QLabel *rotation_lable;
    QLabel *y_rotation_lable;
    QDoubleSpinBox *z_rotation_spin_box;
    QDoubleSpinBox *y_rotation_spin_box;
    QLabel *z_rotation_lable;
    QLabel *x_rotation_lable;
    QDoubleSpinBox *x_rotation_spin_box;
    QLabel *scaling_lable;
    QSlider *scaling_slider;
    QLabel *num_of_vert_lable;
    QLabel *num_of_edg_lable;
    QLabel *projection_lable;
    QLabel *color_lable;
    QPushButton *set_color_button;
    QLabel *vertices_lable;
    QSlider *vertices_slider;
    QPushButton *set_vert_color_button;
    QPushButton *set_edge_color_button;
    QSlider *edge_slider;
    QLabel *edge_lable;
    QPushButton *open_file_button;
    glview *view;
    QComboBox *vert_combo_box;
    QComboBox *edge_combo_box;
    QComboBox *projection_combo_box;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1122, 728);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        about_model_lable = new QLabel(centralwidget);
        about_model_lable->setObjectName(QString::fromUtf8("about_model_lable"));
        about_model_lable->setGeometry(QRect(800, 50, 211, 16));
        QFont font;
        font.setPointSize(16);
        about_model_lable->setFont(font);
        model_name_lable = new QLabel(centralwidget);
        model_name_lable->setObjectName(QString::fromUtf8("model_name_lable"));
        model_name_lable->setGeometry(QRect(800, 80, 311, 16));
        gif_button = new QPushButton(centralwidget);
        gif_button->setObjectName(QString::fromUtf8("gif_button"));
        gif_button->setGeometry(QRect(960, 160, 151, 32));
        gif_button->setFont(font);
        screenshot_button = new QPushButton(centralwidget);
        screenshot_button->setObjectName(QString::fromUtf8("screenshot_button"));
        screenshot_button->setGeometry(QRect(800, 160, 151, 32));
        screenshot_button->setFont(font);
        move_lable = new QLabel(centralwidget);
        move_lable->setObjectName(QString::fromUtf8("move_lable"));
        move_lable->setGeometry(QRect(800, 210, 111, 16));
        move_lable->setFont(font);
        x_move_lable = new QLabel(centralwidget);
        x_move_lable->setObjectName(QString::fromUtf8("x_move_lable"));
        x_move_lable->setGeometry(QRect(800, 230, 21, 31));
        x_move_lable->setFont(font);
        x_move_spin_box = new QDoubleSpinBox(centralwidget);
        x_move_spin_box->setObjectName(QString::fromUtf8("x_move_spin_box"));
        x_move_spin_box->setGeometry(QRect(820, 230, 71, 31));
        y_move_lable = new QLabel(centralwidget);
        y_move_lable->setObjectName(QString::fromUtf8("y_move_lable"));
        y_move_lable->setGeometry(QRect(910, 230, 21, 31));
        y_move_lable->setFont(font);
        y_move_spin_box = new QDoubleSpinBox(centralwidget);
        y_move_spin_box->setObjectName(QString::fromUtf8("y_move_spin_box"));
        y_move_spin_box->setGeometry(QRect(930, 230, 71, 31));
        z_move_lable = new QLabel(centralwidget);
        z_move_lable->setObjectName(QString::fromUtf8("z_move_lable"));
        z_move_lable->setGeometry(QRect(1020, 230, 21, 31));
        z_move_lable->setFont(font);
        z_move_spin_box = new QDoubleSpinBox(centralwidget);
        z_move_spin_box->setObjectName(QString::fromUtf8("z_move_spin_box"));
        z_move_spin_box->setGeometry(QRect(1040, 230, 71, 31));
        rotation_lable = new QLabel(centralwidget);
        rotation_lable->setObjectName(QString::fromUtf8("rotation_lable"));
        rotation_lable->setGeometry(QRect(800, 280, 111, 16));
        rotation_lable->setFont(font);
        y_rotation_lable = new QLabel(centralwidget);
        y_rotation_lable->setObjectName(QString::fromUtf8("y_rotation_lable"));
        y_rotation_lable->setGeometry(QRect(910, 300, 21, 31));
        y_rotation_lable->setFont(font);
        z_rotation_spin_box = new QDoubleSpinBox(centralwidget);
        z_rotation_spin_box->setObjectName(QString::fromUtf8("z_rotation_spin_box"));
        z_rotation_spin_box->setGeometry(QRect(1040, 300, 71, 31));
        y_rotation_spin_box = new QDoubleSpinBox(centralwidget);
        y_rotation_spin_box->setObjectName(QString::fromUtf8("y_rotation_spin_box"));
        y_rotation_spin_box->setGeometry(QRect(930, 300, 71, 31));
        z_rotation_lable = new QLabel(centralwidget);
        z_rotation_lable->setObjectName(QString::fromUtf8("z_rotation_lable"));
        z_rotation_lable->setGeometry(QRect(1020, 300, 21, 31));
        z_rotation_lable->setFont(font);
        x_rotation_lable = new QLabel(centralwidget);
        x_rotation_lable->setObjectName(QString::fromUtf8("x_rotation_lable"));
        x_rotation_lable->setGeometry(QRect(800, 300, 21, 31));
        x_rotation_lable->setFont(font);
        x_rotation_spin_box = new QDoubleSpinBox(centralwidget);
        x_rotation_spin_box->setObjectName(QString::fromUtf8("x_rotation_spin_box"));
        x_rotation_spin_box->setGeometry(QRect(820, 300, 71, 31));
        scaling_lable = new QLabel(centralwidget);
        scaling_lable->setObjectName(QString::fromUtf8("scaling_lable"));
        scaling_lable->setGeometry(QRect(800, 350, 101, 21));
        scaling_lable->setFont(font);
        scaling_slider = new QSlider(centralwidget);
        scaling_slider->setObjectName(QString::fromUtf8("scaling_slider"));
        scaling_slider->setGeometry(QRect(800, 380, 311, 25));
        scaling_slider->setMinimum(1);
        scaling_slider->setMaximum(30);
        scaling_slider->setSingleStep(1);
        scaling_slider->setPageStep(1);
        scaling_slider->setSliderPosition(1);
        scaling_slider->setOrientation(Qt::Horizontal);
        num_of_vert_lable = new QLabel(centralwidget);
        num_of_vert_lable->setObjectName(QString::fromUtf8("num_of_vert_lable"));
        num_of_vert_lable->setGeometry(QRect(800, 110, 311, 16));
        num_of_edg_lable = new QLabel(centralwidget);
        num_of_edg_lable->setObjectName(QString::fromUtf8("num_of_edg_lable"));
        num_of_edg_lable->setGeometry(QRect(800, 140, 311, 16));
        projection_lable = new QLabel(centralwidget);
        projection_lable->setObjectName(QString::fromUtf8("projection_lable"));
        projection_lable->setGeometry(QRect(800, 410, 111, 31));
        projection_lable->setFont(font);
        color_lable = new QLabel(centralwidget);
        color_lable->setObjectName(QString::fromUtf8("color_lable"));
        color_lable->setGeometry(QRect(800, 480, 81, 31));
        color_lable->setFont(font);
        set_color_button = new QPushButton(centralwidget);
        set_color_button->setObjectName(QString::fromUtf8("set_color_button"));
        set_color_button->setGeometry(QRect(860, 480, 251, 32));
        set_color_button->setFont(font);
        vertices_lable = new QLabel(centralwidget);
        vertices_lable->setObjectName(QString::fromUtf8("vertices_lable"));
        vertices_lable->setGeometry(QRect(800, 520, 71, 21));
        vertices_lable->setFont(font);
        vertices_slider = new QSlider(centralwidget);
        vertices_slider->setObjectName(QString::fromUtf8("vertices_slider"));
        vertices_slider->setGeometry(QRect(800, 550, 311, 25));
        vertices_slider->setOrientation(Qt::Horizontal);
        set_vert_color_button = new QPushButton(centralwidget);
        set_vert_color_button->setObjectName(QString::fromUtf8("set_vert_color_button"));
        set_vert_color_button->setGeometry(QRect(800, 580, 151, 32));
        set_vert_color_button->setFont(font);
        set_edge_color_button = new QPushButton(centralwidget);
        set_edge_color_button->setObjectName(QString::fromUtf8("set_edge_color_button"));
        set_edge_color_button->setGeometry(QRect(800, 690, 151, 32));
        set_edge_color_button->setFont(font);
        edge_slider = new QSlider(centralwidget);
        edge_slider->setObjectName(QString::fromUtf8("edge_slider"));
        edge_slider->setGeometry(QRect(800, 660, 311, 25));
        edge_slider->setOrientation(Qt::Horizontal);
        edge_lable = new QLabel(centralwidget);
        edge_lable->setObjectName(QString::fromUtf8("edge_lable"));
        edge_lable->setGeometry(QRect(800, 630, 71, 21));
        edge_lable->setFont(font);
        open_file_button = new QPushButton(centralwidget);
        open_file_button->setObjectName(QString::fromUtf8("open_file_button"));
        open_file_button->setGeometry(QRect(800, 10, 311, 32));
        open_file_button->setFont(font);
        view = new glview(centralwidget);
        view->setObjectName(QString::fromUtf8("view"));
        view->setGeometry(QRect(10, 10, 781, 711));
        vert_combo_box = new QComboBox(centralwidget);
        vert_combo_box->addItem(QString());
        vert_combo_box->addItem(QString());
        vert_combo_box->addItem(QString());
        vert_combo_box->setObjectName(QString::fromUtf8("vert_combo_box"));
        vert_combo_box->setGeometry(QRect(960, 580, 161, 32));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(vert_combo_box->sizePolicy().hasHeightForWidth());
        vert_combo_box->setSizePolicy(sizePolicy);
        vert_combo_box->setMinimumSize(QSize(0, 0));
        vert_combo_box->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setPointSize(16);
        font1.setStyleStrategy(QFont::PreferDefault);
        vert_combo_box->setFont(font1);
        vert_combo_box->setFocusPolicy(Qt::NoFocus);
        vert_combo_box->setEditable(false);
        vert_combo_box->setMaxVisibleItems(2);
        vert_combo_box->setMaxCount(10);
        vert_combo_box->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        vert_combo_box->setFrame(true);
        vert_combo_box->setModelColumn(0);
        edge_combo_box = new QComboBox(centralwidget);
        edge_combo_box->addItem(QString());
        edge_combo_box->addItem(QString());
        edge_combo_box->addItem(QString());
        edge_combo_box->setObjectName(QString::fromUtf8("edge_combo_box"));
        edge_combo_box->setGeometry(QRect(960, 690, 161, 32));
        sizePolicy.setHeightForWidth(edge_combo_box->sizePolicy().hasHeightForWidth());
        edge_combo_box->setSizePolicy(sizePolicy);
        edge_combo_box->setMinimumSize(QSize(0, 0));
        edge_combo_box->setMaximumSize(QSize(16777215, 16777215));
        edge_combo_box->setFont(font);
        edge_combo_box->setFocusPolicy(Qt::NoFocus);
        edge_combo_box->setEditable(false);
        edge_combo_box->setMaxVisibleItems(2);
        edge_combo_box->setMaxCount(10);
        edge_combo_box->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        edge_combo_box->setFrame(true);
        edge_combo_box->setModelColumn(0);
        projection_combo_box = new QComboBox(centralwidget);
        projection_combo_box->addItem(QString());
        projection_combo_box->addItem(QString());
        projection_combo_box->setObjectName(QString::fromUtf8("projection_combo_box"));
        projection_combo_box->setGeometry(QRect(790, 440, 331, 32));
        projection_combo_box->setFont(font);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        vert_combo_box->setCurrentIndex(1);
        edge_combo_box->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        about_model_lable->setText(QCoreApplication::translate("MainWindow", "Info about model:", nullptr));
        model_name_lable->setText(QCoreApplication::translate("MainWindow", "Model name: ", nullptr));
        gif_button->setText(QCoreApplication::translate("MainWindow", "Gif", nullptr));
        screenshot_button->setText(QCoreApplication::translate("MainWindow", "Screenshot", nullptr));
        move_lable->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        x_move_lable->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        y_move_lable->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        z_move_lable->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        rotation_lable->setText(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
        y_rotation_lable->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        z_rotation_lable->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        x_rotation_lable->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        scaling_lable->setText(QCoreApplication::translate("MainWindow", "Scaling", nullptr));
        num_of_vert_lable->setText(QCoreApplication::translate("MainWindow", "Number of vertices: ", nullptr));
        num_of_edg_lable->setText(QCoreApplication::translate("MainWindow", "Number of edges: ", nullptr));
        projection_lable->setText(QCoreApplication::translate("MainWindow", "Projection type:", nullptr));
        color_lable->setText(QCoreApplication::translate("MainWindow", "Back:", nullptr));
        set_color_button->setText(QCoreApplication::translate("MainWindow", "Set color", nullptr));
        vertices_lable->setText(QCoreApplication::translate("MainWindow", "Vertices:", nullptr));
        set_vert_color_button->setText(QCoreApplication::translate("MainWindow", "Set color", nullptr));
        set_edge_color_button->setText(QCoreApplication::translate("MainWindow", "Set color", nullptr));
        edge_lable->setText(QCoreApplication::translate("MainWindow", "Edges:", nullptr));
        open_file_button->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        vert_combo_box->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        vert_combo_box->setItemText(1, QCoreApplication::translate("MainWindow", "Smooth", nullptr));
        vert_combo_box->setItemText(2, QCoreApplication::translate("MainWindow", "Sprite", nullptr));

        edge_combo_box->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        edge_combo_box->setItemText(1, QCoreApplication::translate("MainWindow", "Solid", nullptr));
        edge_combo_box->setItemText(2, QCoreApplication::translate("MainWindow", "Dashed", nullptr));

        projection_combo_box->setItemText(0, QCoreApplication::translate("MainWindow", "Central projection", nullptr));
        projection_combo_box->setItemText(1, QCoreApplication::translate("MainWindow", "Parallel projection", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
