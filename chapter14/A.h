#pragma once

#include <iostream>
#include <vector>

using namespace std;

class A{
friend ostream& operator<<(ostream &,const A &);
friend istream& operator>>(istream &,A &);
// friend:: A operator+(const A &,const A &);

public:
    A()=default;
    A(int a_):v(a_){}
    A operator+=(const A&);
    A& operator++();
private:
    int v;
    
};
ostream& operator<<(ostream &os,const A &a)
{
    os << a.v;
    return os;
}

istream& operator>>(istream &is,A &a)
{
    is >> a.v;
    if(is)
        return is;
    else
    {
        a = A();
        return is;
    }         
}

A A::operator+=(const A &a)
{
    v += a.v;
    return *this;
}

A operator+(const A &lhs,const A &rhs)
{
    // A sum;
    // sum.v = lhs.v + rhs.v;
    A sum = lhs;
    sum += rhs;
    return sum;
}

A& A::operator++()
{
    ++v;
    return *this;
}
