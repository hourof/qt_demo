#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <qtimer.h>
#include <QDebug>
#include <QImage>
using namespace  cv;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
     QImage cvmat_to_qimage(const Mat mat);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    VideoCapture vid;
    QTimer *refresh_timer;

public slots:   //用于声明公开的槽函数
    void on_refresh_timer();

};

#endif // MAINWINDOW_H
