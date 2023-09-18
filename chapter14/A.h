#pragma once

#include <iostream>

using namespace std;

class A{
friend ostream& operator<<(ostream &,const A &);
public:
    A(int a_):v(a_){}
private:
    int v;
};
ostream& operator<<(ostream &os,const A &a)
{
    os << a.v;
}


