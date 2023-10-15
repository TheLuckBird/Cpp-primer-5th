#pragma once
#include <cstddef>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Sequence_list
{
public:
    Sequence_list(size_t size):maxsize(size){data = new T[maxsize];};// T data[maxsize];}
    void init();//初始化线性表
    void show();//打印线性表
    size_t getItemIndex(T);//按元素取位置
    T getItem(size_t);//按位置取元素
    void insert(size_t,T);
    void deleteItem(T);
    ~Sequence_list(){delete [] data;}

private:
   size_t maxsize;
   size_t length = 0;
   T *data;

};

template<typename T> void Sequence_list<T>::init()
{
    cout << "输入元素:" << endl;
    T v;
    for(size_t i=0;(cin >> v)&&(i!=maxsize);++i,++length)
    {
        data[i] = v;
    } 
    if(length == maxsize) cout << "溢出" << endl;
}

template<typename T> void Sequence_list<T>::show()
{
    cout << "线性表：" << endl;
    for(size_t i=0;i!=length;i++)
        cout << data[i] << " ";
    cout << endl;
}

template <typename T> size_t Sequence_list<T>::getItemIndex(T v)
{
    for (size_t i = 0; i < length; i++)
    {
        if(data[i] == v) return i;
    }
    throw runtime_error("没找到");
    
}

template <typename T> T Sequence_list<T>::getItem(size_t i)
{
    if(i < 0 || i>= length) throw runtime_error("越界");
    else return data[i];
}

template <typename T> void Sequence_list<T>::insert(size_t p,T v)
{
    if(p < 0 || p>= length) throw runtime_error("越界");
    
    for(size_t i=length++;i!=p-1;--i)
        data[i+1] = data[i];
    data[p] = v;
    
}

template <typename T> void Sequence_list<T>::deleteItem(T v)
{
    size_t c = 0;//v出现的次数
    size_t gap = 0;
    for(size_t i=0;i!=length;++i)
        if(data[i] == v) ++gap,++c;
        else data[i-gap] = data[i],gap=0;
    length = length -c + 1;
}
