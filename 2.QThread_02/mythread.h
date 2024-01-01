#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QVector>
//class Generate About
//English:This class is used to generate randow nubers
//chinese:该类用于生成随机数
class Generate : public QObject
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);
    void working(int num);

signals:
    //use for return Grenerate random of singnal
    void sendArry(QVector<int> num);
private:
    int m_num;
};
//BubbleList
//冒泡排序的类
class Bubblesort : public QObject
{
    Q_OBJECT
public:
    //use for statement display constructor
    explicit Bubblesort(QObject *parent = nullptr);
    void working(QVector<int> list);

signals:

     void finsh(QVector<int> list);
};

class Quicksort : public QObject
{
    Q_OBJECT
public:
    explicit Quicksort(QObject *parent = nullptr);
    void working(QVector<int> list);
private:
     void quickSort(QVector<int> &s, int l, int r);
signals:

   void finsh(QVector<int> list);
};

#endif // MYTHREAD_H
