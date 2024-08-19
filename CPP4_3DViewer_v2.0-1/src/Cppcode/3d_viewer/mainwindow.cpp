#include "mainwindow.h"
#include "ui_mainwindow.h"

extern "C" {
#include "gif.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->view->info.p = NULL;
  ui->view->info.v = NULL;
  settings = new QSettings;
  loadSettings();
  // translate
  connect(ui->x_move_spin_box, SIGNAL(valueChanged(double)), this,
          SLOT(translation_value_changed_X(double)));
  connect(ui->y_move_spin_box, SIGNAL(valueChanged(double)), this,
          SLOT(translation_value_changed_Y(double)));
  connect(ui->z_move_spin_box, SIGNAL(valueChanged(double)), this,
          SLOT(translation_value_changed_Z(double)));

  // rotate
  connect(ui->x_rotation_spin_box, SIGNAL(valueChanged(double)), this,
          SLOT(rotation_value_changed_X(double)));
  connect(ui->y_rotation_spin_box, SIGNAL(valueChanged(double)), this,
          SLOT(rotation_value_changed_Y(double)));
  connect(ui->z_rotation_spin_box, SIGNAL(valueChanged(double)), this,
          SLOT(rotation_value_changed_Z(double)));

  // scale
  connect(ui->scaling_slider, SIGNAL(valueChanged(int)), this,
          SLOT(scale_value_changed(int)));

  // type of lines and verts
  connect(ui->vert_combo_box, SIGNAL(activated(int)), this,
          SLOT(vert_type_activated(int)));
  connect(ui->edge_combo_box, SIGNAL(activated(int)), this,
          SLOT(lines_type_activated(int)));

  // sliders
  connect(ui->vertices_slider, SIGNAL(valueChanged(int)), this,
          SLOT(size_vert_changed(int)));
  connect(ui->edge_slider, SIGNAL(valueChanged(int)), this,
          SLOT(size_lines_changed(int)));

  // projection
  connect(ui->projection_combo_box, SIGNAL(activated(int)), this,
          SLOT(projection_type_activated(int)));

  // open file
  //  connect(ui->open_file_button, SIGNAL(clicked()), this,
  //          SLOT(on_open_file_button_clicked()));

  // color buttons
  connect(ui->set_vert_color_button, SIGNAL(clicked()), this,
          SLOT(color_vert_button_clicked()));
  connect(ui->set_edge_color_button, SIGNAL(clicked()), this,
          SLOT(color_lines_button_clicked()));
  connect(ui->set_color_button, SIGNAL(clicked()), this,
          SLOT(color_back_button_clicked()));
}

MainWindow::~MainWindow() {
  saveSettings();
  delete ui;
}

// translate
void MainWindow::translation_value_changed_X(double value) {
  double xmove = 0.5 * (value - ui->view->move[0]);
  ui->view->move[0] = value;
  s21_move(&(ui->view->info), xmove, 0, 0);
  ui->view->update();
}

void MainWindow::translation_value_changed_Y(double value) {
  double ymove = 0.5 * (value - ui->view->move[1]);
  ui->view->move[1] = value;
  s21_move(&(ui->view->info), 0, ymove, 0);
  ui->view->update();
}

void MainWindow::translation_value_changed_Z(double value) {
  double zmove = 0.5 * (value - ui->view->move[2]);
  ui->view->move[2] = value;
  s21_move(&(ui->view->info), 0, 0, zmove);
  ui->view->update();
}

// rotate
void MainWindow::rotation_value_changed_X(double value) {
  double xrot = (value - ui->view->rotation[0]) / 180 * M_PI;
  ui->view->rotation[0] = value;
  s21_turn(&(ui->view->info), xrot, 0, 0);
  ui->view->update();
}

void MainWindow::rotation_value_changed_Y(double value) {
  double yrot = (value - ui->view->rotation[1]) / 180 * M_PI;
  ui->view->rotation[1] = value;
  s21_turn(&(ui->view->info), 0, yrot, 0);
  ui->view->update();
}

void MainWindow::rotation_value_changed_Z(double value) {
  double zrot = (value - ui->view->rotation[2]) / 180 * M_PI;
  ui->view->rotation[2] = value / 180 * M_PI;
  s21_turn(&(ui->view->info), 0, 0, zrot);
  ui->view->update();
}

// scale
void MainWindow::scale_value_changed(int value) {
  if (ui->view->scale_value <= (double)value) {
    ui->view->scale = (double)value;
  } else {
    ui->view->scale = 1 / (double)value;
  }
  ui->view->scale_value = value;
  ui->view->update();
}

// type of lines and verts
void MainWindow::vert_type_activated(int value) {
  ui->view->type_vert = value;
  ui->view->update();
}

void MainWindow::size_vert_changed(int value) {
  ui->view->size_vert = (double)value;
  ui->view->update();
}

void MainWindow::lines_type_activated(int value) {
  ui->view->type_lines = value;
  ui->view->update();
}

void MainWindow::size_lines_changed(int value) {
  ui->view->size_lines = (double)value;
  ui->view->update();
}

// projection
void MainWindow::projection_type_activated(int value) {
  ui->view->projection = value;
  ui->view->update();
}

// open file
void MainWindow::on_open_file_button_clicked() {
  QString temp = QCoreApplication::applicationDirPath();
  temp.resize(temp.size() - 38);
  QString fileName = QFileDialog::getOpenFileName(
      0, tr("Open file"), temp + "/models", tr("Object files (*.obj)"));

  int index = fileName.lastIndexOf("/", -1);
  ui->model_name_lable->setText("•File name: " +
                                fileName.right(fileName.length() - index - 1));
  ui->view->filePath = fileName;
  ui->view->openFile();
  ui->num_of_vert_lable->setText("•Number of vertices: " +
                                 QString::number(ui->view->num_of_vert));
  ui->num_of_edg_lable->setText("•Number of edges: " +
                                QString::number(ui->view->num_of_lines));
  ui->view->update();
}

// color buttons
void MainWindow::color_vert_button_clicked() {
  QColor colour = QColorDialog::getColor(Qt::white, this, "Select color:");
  ui->view->color_vert = colour;
  ui->view->update();
}

void MainWindow::color_lines_button_clicked() {
  QColor colour = QColorDialog::getColor(Qt::white, this, "Select color:");
  ui->view->color_lines = colour;
  ui->view->update();
}

void MainWindow::color_back_button_clicked() {
  QColor colour = QColorDialog::getColor(Qt::white, this, "Select color:");
  ui->view->color_back = colour;
  ui->view->update();
}

// screenshot
void MainWindow::on_screenshot_button_clicked() {
  QImage img(ui->view->size(), QImage::Format_RGB32);
  QPainter painter(&img);

  QString temp = QCoreApplication::applicationDirPath();
  temp.resize(temp.size() - 38);
  QString fileName = QFileDialog::getSaveFileName(
      this, tr("Save file"), temp + "/images", tr("JPG (*.jpg);; BMP (*.bmp)"));

  bool res = false;
  ui->view->render(&painter);
  res = img.save(fileName);
  if (res == true) {
    QMessageBox msgBox;
    msgBox.setText("Screenshot saved successfully.");
    msgBox.exec();
  } else {
    QMessageBox::warning(this, "", "Failed to save screenshot.");
  }
}

// gif
void MainWindow::on_gif_button_clicked() {
  QString temp = QCoreApplication::applicationDirPath();
  temp.resize(temp.size() - 38);
  QString fileName = QFileDialog::getSaveFileName(
      this, tr("Save gif"), temp + "/images", tr("GIF (*.gif)"));

  if (!fileName.isEmpty()) {
    QImage img(ui->view->size(), QImage::Format_RGB32);
    QPainter painter(&img);
    QImage img640_480;
    QTime dieTime;
    int width = 640;
    int height = 480;
    GifWriter gif;
    QByteArray ba = fileName.toLocal8Bit();
    const char *c_str = ba.data();
    GifBegin(&gif, c_str, width, height, 100);

    for (int i = 0; i < 50; ++i) {
      ui->view->render(&painter);
      img640_480 = img.scaled(QSize(640, 480));
      GifWriteFrame(&gif, img640_480.bits(), width, height, 100);
      dieTime = QTime::currentTime().addMSecs(100);
      while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }

    GifEnd(&gif);
    QMessageBox msgBox;
    msgBox.setText("GIF saved successfully.");
    msgBox.exec();
  } else {
    QMessageBox::warning(this, "", "Failed to save gif.");
  }
}

void MainWindow::saveSettings() {
  settings->beginGroup("form");
  settings->setValue("type", ui->view->projection);
  settings->setValue("vert_scale", ui->view->size_vert);
  settings->setValue("edge", ui->view->type_lines);
  settings->setValue("edge scale", ui->view->size_lines);
  settings->endGroup();
}

void MainWindow::loadSettings() {
  settings->beginGroup("form");
  ui->view->projection = settings->value("type").toInt();
  ui->projection_combo_box->setCurrentIndex(ui->view->projection);
  ui->view->size_vert = settings->value("vert_scale").toInt();
  ui->vertices_slider->setValue(ui->view->size_vert);
  ui->view->type_lines = settings->value("edge").toInt();
  ui->edge_combo_box->setCurrentIndex(ui->view->type_lines);
  ui->view->size_lines = settings->value("edge scale").toInt();
  ui->edge_slider->setValue(ui->view->size_lines);
  settings->endGroup();
}
