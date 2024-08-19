#ifndef S21_3D_VIEWER_H
#define S21_3D_VIEWER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class s21_3d_viewer; }
QT_END_NAMESPACE

class s21_3d_viewer : public QMainWindow
{
    Q_OBJECT

public:
    s21_3d_viewer(QWidget *parent = nullptr);
    ~s21_3d_viewer();

private:
    Ui::s21_3d_viewer *ui;
};
#endif // S21_3D_VIEWER_H
