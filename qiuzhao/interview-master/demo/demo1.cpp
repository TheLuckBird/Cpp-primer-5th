#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "记录秋招！" << endl;

    cout << "C/C++" << endl;

    int i = 5;
    const int j = 6;

    i = i + 1;
    // j = j - 1;

    // int *p2i = &i;

    auto p2i = &i;
    cout << &i << endl;
    cout << p2i << endl;

    // int const &r2i = i;
    const int &r2i = i;//const代表不能修改其绑定的对象的值，但是对于引用（绑定）的对象是否为常量未做限定。
                       //换句话说可是变量、值...,这个和引用不一样

    // r2i = 0;
    // r2i = &j;

    const int &r2cx = 0;

    //int &r2x = 0;//error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'

    // int & const r2i = i;//错误的，因为引用只是对象的别名，引用不是对象，不能用 const 修饰。
                        //error: 'const' qualifiers cannot be applied to 'int&'

    cout << r2i << endl;
    i = i + 1;
    cout << r2i << endl;

    // r2i  = r2i + 1;

    // r2i = j;

    const int *p2x = &i;
    p2x = &j;
    i = 100;
    // *p2x = *p2x + 1;
    cout << *p2x << endl;

    int * const cp = &i;
    *cp = *cp + 1; 
    cout << i << endl;
    i = 102;
    cout << *cp << endl;
    // cp = &j;//error: assignment of read-only variable 'cp'

   const int * const cp2cx = &i;
   i = 1000;
   cout << *cp2cx << endl;

    //* &左边的const代表不能修改绑定对象的内容，右边的const代表不能修改绑定的对象是哪个
    // top-level-const:表示任意对象是常量。  
    // low-level-const:表示指针指的对象是常量，用于声明引用的都是底层const

    return 0;
}
