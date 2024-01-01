#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->vid.open(0);
    this->refresh_timer = new QTimer(this);
    //调用on_refresh_timer槽函数
    connect(this->refresh_timer,SIGNAL(timeout()),this,SLOT(on_refresh_timer()));
    this->refresh_timer->start(33);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_refresh_timer()
{
    Mat frame;
    this->vid >> frame; //将摄像头捕获的帧数赋值到frame里面去
    QImage img =  cvmat_to_qimage(frame);
    this->ui->label->setPixmap(QPixmap::fromImage(img));
}


QImage MainWindow::cvmat_to_qimage(const Mat mat)
{
    //将Mat图像转换为QImage图像
    QImage image(mat.data,mat.cols,mat.rows,mat.step,QImage::Format_RGB888);
    return image.rgbSwapped();
}


