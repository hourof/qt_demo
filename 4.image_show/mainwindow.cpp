#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QPainter>
#include <QPicture>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->pushButton_2,&QPushButton::clicked,&MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    /*
        getopenfilename作用:用于打开文件
        parameter1(this):指定当前父对象
        parameter2(tr):指定选择框的标题
        parameter3():文件路径
        parameter4():要打开的文件格式，可以打开多种文件的格式用*.jpg *.png
        return: 返回打开文件的绝对路径
    */
    QString  filename = QFileDialog::getOpenFileName
            (this,tr("Open Image"),"d:\\opencvcode",tr("(*.jpg *.png)\n(*.bmp)\n(*.png)"));
    qDebug() <<filename ;
    QImage image = QImage(filename);
    qDebug() <<"image" <<image;
     QPixmap tempPixmap = QPixmap::fromImage(image);
    //isnull判断图像内容是否为空，如果为空，返回true,否则返回flase
    if(!image.isNull())
    {
        ui->label->setPixmap(tempPixmap);
        ui->statusbar->showMessage(tr("open image success"),30000);
    }
}

void MainWindow::on_pushButton1_clicked()
{
    qDebug() << "123";
    this->close();
}

