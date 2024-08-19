#include "s21_3d_viewer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    s21_3d_viewer w;
    w.show();
    return a.exec();
}
