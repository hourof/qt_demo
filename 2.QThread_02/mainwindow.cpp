#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include <QThread>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QThread* t1 = new QThread;
    QThread* t2 = new QThread;
    QThread* t3 = new QThread;
    //instantiation Generate object
    Generate* gen = new Generate;
    Bubblesort* bubble = new Bubblesort;
    Quicksort* quick = new Quicksort;

    gen->moveToThread(t1);
    bubble->moveToThread(t2);
    quick->moveToThread(t3);
    connect(this,&MainWindow::string,gen,&Generate::working);
    //when start button by click,Generate random
    //当start按钮被点击,生成随机数
    connect(ui->start,&QPushButton::clicked,this,[=](){
        emit string(10000);
        //start thread
        t1->start();
    });
    connect(gen,&Generate::sendArry,bubble,&Bubblesort::working);
    connect(gen,&Generate::sendArry,quick,&Quicksort::working);
    //receive child thread send signals
    //接收子线程发送的信号
    connect(gen,&Generate::sendArry,this,[=](QVector<int> list){
        t2->start();
        t3->start();
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
    connect(this,&MainWindow::destroyed,this,[=](){
        qDebug() << "我被调用了";
        t1->quit();
        t1->wait();
        t1->deleteLater();

        t2->quit();
        t2->wait();
        t2->deleteLater();

        t3->quit();
        t3->wait();
        t3->deleteLater();

        gen->deleteLater();
        bubble->deleteLater();
        quick->deleteLater();

    });
}

MainWindow::~MainWindow()
{

    delete ui;
}

