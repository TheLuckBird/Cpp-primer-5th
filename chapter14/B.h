#pragma once
#include <iostream>

using namespace std;

struct B
{
public:
    B(int =0){ cout << "B(int =0)" << endl;}//转换构造函数
    B(double){ cout << "B(double)" << endl;}
    operator int(){ cout << "operator int()" << endl;}
    operator double(){ cout << "operator double()" << endl;}
};

void f(long double);