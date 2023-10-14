#pragma once
#include <cstddef>
#include <iostream>

using namespace std;

template <typename T>
class Sequence_list
{
public:
    Sequence_list(size_t size):maxsize(size){data = new T[maxsize];};// T data[maxsize];}
    void init();
    void show();
    // void insert(size_t,T);
    ~Sequence_list(){delete [] data;}

private:
   size_t maxsize;
   size_t length = 0;
   T *data;

};

template<typename T> void Sequence_list<T>::init()
{
    T v;
    for(size_t i=0;(cin >> v)&&(i!=maxsize);++i,++length)
    {
        data[i] = v;
    } 
    if(length == maxsize) cout << "溢出" << endl;
}

template<typename T> void Sequence_list<T>::show()
{
    for(size_t i=0;i!=length;i++)
        cout << data[i] << " ";
    cout << endl;
}
