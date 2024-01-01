#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QVector>
//class Generate About
//English:This class is used to generate randow nubers
//chinese:该类用于生成随机数
class Generate : public QThread
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);
    void recv_num(int num);
protected:
    //English:When you create Generate instantiaction object time ,run function   auto call
    //clinese:当你创建Generate实例化对象时,run函数会自己调用,相当于构造函数

    void run() override;

signals:
    //use for return Grenerate random of singnal
    void sendArry(QVector<int> list);
private:
    int m_num;
};
//BubbleList
//冒泡排序的类
class Bubblesort : public QThread
{
    Q_OBJECT
public:
    //use for statement display constructor
    explicit Bubblesort(QObject *parent = nullptr);
    void receiveArray(QVector<int> list);

protected:
    void run() override;
signals:

     void finsh(QVector<int> list);
 private:
     QVector<int> m_list;
};

class Quicksort : public QThread
{
    Q_OBJECT
public:
    explicit Quicksort(QObject *parent = nullptr);
    void receiceArray(QVector<int> list);
protected:
    void run() override;
private:
     QVector<int> m_list;
     void quickSort(QVector<int> &s, int l, int r);
signals:

   void finsh(QVector<int> list);
};

#endif // MYTHREAD_H
