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
        cout << "拷贝构造函数Foo(const Foo &f)" << endl;
    }

    Foo& operator=(const Foo &);
    void print();
    ~Foo(){ cout << "析构函数~Foo()" << endl;}
    // ~Foo() =delete;
private:
    int number=0;
    string s;
    // int &ref;
};

Foo& Foo::operator=(const Foo & f)
{
    cout << "拷贝复制运算符" << endl;
    number = f.number;
    s = f.s;
    return *this;
}

void Foo::print()
{
    cout << "number:" << number << " " << "string:" << s  << endl;
}


#endif