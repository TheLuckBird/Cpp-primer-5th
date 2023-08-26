#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    const int i = 1;
    // int &ref = i；//非常量引用不能指向常量对象
    const int &ref = i;
    // ref = 2;//const的引用不能修改其绑定的对象
    int j = 2;
    const int &ref_a = 3;//const int &ref_a = j;
    cout << ref_a << endl;
    // int &k = 4;
    //上一行报错信息：cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'

    int x = 1;
    int y = 10;
    int &ref_x = x;
    ref_x = y;
    cout << ref_x << endl;
    cout << x << endl;//10

    cout << "-----------" << endl; ;
    int p = 1;
    int *const ptr = &p;
    const int *const ptr1 = &p;
    // ptr1 = &i;
    cout << ptr <<endl;
    *ptr = 2;
    // *ptr1 = 3;
    cout << *ptr <<endl;
    cout << p <<endl;

    const int *m;
    cout << m << endl;

    const int *a = nullptr;//a是指向整型常量对象的指针
    constexpr int *b = nullptr;//b是指向整型对象的常量指针
    return 0;
}
