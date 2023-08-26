#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int i = 1024;
    int j = 4201;
    int &ref_i = i;//ref_i指向i
    cout << ref_i << endl;//1024
    cout << ref_i+1 <<endl;//1025
    //int &ref;//引用必须初始化
    ref_i = j;
    cout << ref_i << endl;//4201
    cout << ref_i-1 << endl;//4200
    //int &X = 1;//错

    int * r;
    // int b = 0;
    // r = b;
    r = & i;
    cout << "r:" << r << endl;
    if (r)
        cout << "true" << endl;
    cout << *r << endl;
    *r = 10;
    cout << *r << endl;
    cout << i << endl;

    int &a = *r;
    cout << "a:"<< a << endl;

    int *&y=r;
    cout << "y:" << y << endl;

    return 0;
}
