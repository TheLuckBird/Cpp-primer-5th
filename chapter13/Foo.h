#ifndef FOO_H
#define FOO_H

#include <iostream>

using namespace std;
class Foo//类名首字母大写
{
public:
    Foo()
    { 
        cout << "默认构造函数" << endl;
    }

    Foo(int number_,string s_):number(number_),s(s_)
    {
        cout << "Foo(int number_,string s_)构造函数" << endl;
    }

    Foo(const Foo &f): number(f.number),s(f.s)
    { 
        cout << "拷贝构造函数" << endl;
    }

    Foo& operator=(const Foo &);
    void print();
private:
    int number=0;
    string s;
};

Foo& Foo::operator=(const Foo & f)
{
    number = f.number;
    s = f.s;
    return *this;
}

void Foo::print()
{
    cout << "number:" << number << " " << "string:" << s  << endl;
}
#endif