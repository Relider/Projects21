QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# TARGET = Settings
# TEMPLATE = app

SOURCES += \
    ../../Ccode/s21_change_position.c \
    ../../Ccode/s21_change_size.c \
    ../../Ccode/s21_input.c \
    ../../Ccode/s21_stack.c \
    glview.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    ../../Ccode/s21_3dviewer.h \
    gif.h \
    glview.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
