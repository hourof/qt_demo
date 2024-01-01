#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include <QThreadPool>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //instantiation Generate object
    Generate* gen = new Generate;
    Bubblesort* bubble = new Bubblesort;
    Quicksort* quick = new Quicksort;
    connect(this,&MainWindow::string,gen,&Generate::recv_num);
    //when start button by click,Generate random
    //当start按钮被点击,生成随机数
    connect(ui->start,&QPushButton::clicked,this,[=](){
        emit string(10000);
        //start thread
        QThreadPool::globalInstance()->start(gen);
    });
    connect(gen,&Generate::sendArry,bubble,&Bubblesort::receiveArray);
    connect(gen,&Generate::sendArry,quick,&Quicksort::receiceArray);
    //receive child thread send signals
    //接收子线程发送的信号
    connect(gen,&Generate::sendArry,this,[=](QVector<int> list){
        QThreadPool::globalInstance()->start(bubble);
        QThreadPool::globalInstance()->start(quick );
        for(int i=0;i<list.size();++i)
        {
            ui->randlist->addItem(QString::number(list.at(i)));

        }

    });
    connect(bubble,&Bubblesort::finsh,this,[=](QVector<int> list){
        for(int i =0; i< list.size();++i)
        {
            ui->bubblelist->addItem(QString::number(list.at(i)));
        }
    });
    connect(quick,&Quicksort::finsh,this,[=](QVector<int> list){
        for(int i=0;i<list.size();++i)
        {
            ui->quicklist->addItem(QString::number(list.at(i)));
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

