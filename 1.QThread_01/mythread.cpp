#include "mythread.h"
//The Header use of count time
#include <QElapsedTimer>
#include <QDebug>

Generate::Generate(QObject *parent) : QThread(parent)
{

}

void Generate::recv_num(int num)
{
    m_num = num;
}

void Generate::run()
{
    qDebug() << "Grenerate random number of address is:" << QThread::currentThread();
    //EnglishL:Generate random number of vector
    //clinese:生成随机数的容器
    QVector<int> list;
    //instantiation a time object
    //实例化一个时间对象,用于记录程序运行时间
    QElapsedTimer time;

    //recore time start
    //记录时间开始
    time.start();

    //English: this  for use for Generate how many random
    //clinese:这个循环用于生成多少个随机数
    for(int i=0;i<m_num;i++)
    {
        //English:This code use for Generate 10000 within of random
        //chinese:这段代码用于生成10000以内的随机数
        list.push_back(qrand() % 100000);

    }
    int mesc = time.elapsed();
    qDebug() << "程序运行时间为:" << mesc <<"毫秒";
    emit sendArry(list);
}

Bubblesort::Bubblesort(QObject *parent) : QThread(parent)
{


}

void Bubblesort::receiveArray(QVector<int> list)
{
    m_list = list;
}

void Bubblesort::run()
{

    qDebug() << "BubbleSort of address is"<<QThread::currentThread();

    QElapsedTimer time;
    time.start();
    int temp;
    for(int i=0;i<m_list.size();++i)
    {
        for(int j=0;j<m_list.size()-i-1;++j)
        {
            if(m_list[j]>m_list[j+1])
            {
                temp = m_list[j];
                m_list[j]= m_list[j+1];
                m_list[j+1] = temp;
            }
        }
     }
    //Tike time
    int mesc = time.elapsed();
    qDebug()<<"BubbleSort Tike time: "<<mesc << "毫秒";
    emit finsh(m_list);
}



//快速排序
Quicksort::Quicksort(QObject *parent):QThread(parent)
{

}

void Quicksort::quickSort(QVector<int> &s, int l, int r)
{

    if (l < r)
    {
        int i = l, j = r;
        // 拿出第一个元素, 保存到x中,第一个位置成为一个坑
        int x = s[l];
        while (i < j)
        {
            // 从右向左找小于x的数
            while (i < j && s[j] >= x)
            {
                //左移, 直到遇到小于等于x的数
                j--;
            }
            if (i < j)
            {
                //将右侧找到的小于x的元素放入左侧坑中, 右侧出现一个坑
                //左侧元素索引后移
                s[i++] = s[j];
            }

            // 从左向右找大于等于x的数
            while (i < j && s[i] < x)
            {
                //右移, 直到遇到大于x的数
                i++;
            }
            if (i < j)
            {
                //将左侧找到的元素放入右侧坑中, 左侧出现一个坑
                //右侧元素索引向前移动
                s[j--] = s[i];
            }
        }
        //此时 i=j,将保存在x中的数填入坑中
        s[i] = x;
        quickSort(s, l, i - 1); // 递归调用
        quickSort(s, i + 1, r);
    }
}

void Quicksort::receiceArray(QVector<int> list)
{
    m_list = list;
}

void Quicksort::run()
{
    qDebug() << "QuickSort Tick Time of address is" <<QThread::currentThread();
    QElapsedTimer time;
    time.start();
    quickSort(m_list,0,m_list.size()-1);
    int mesc = time.elapsed();
    qDebug() << "qicksort Tick time :" <<mesc << "ms";
    emit finsh(m_list);

}

