#include <iostream>
#include <typeinfo>
using namespace std;
int main(int argc, char const *argv[])
{
    typedef int integer;
    integer i = 10;
    cout << i << endl;

    using character = char ;
    character ch ='h';
    cout << ch << endl;

    double d = 3.14;
    typedef double* pointer_double;
    const pointer_double pd = &d;
    cout << *pd << endl;//3.14 
    const pointer_double *dd = &pd;
    cout << **dd << endl;//3.14 

    auto j = 10, *p = &j;
    auto k = j + p;
    cout << p << endl;
    cout << k <<endl;

    // auto x = 10, y =10.1;

    integer v = 0, &ref_v = v;
    auto auto_v = v;

    const int i_auto = i, &ref_i_auto = i_auto;
    auto a = i_auto;//整数，const int i_auto是顶层const
    auto b = ref_i_auto;//整数，ref_i_auto是i的别名
    auto c = &i;//整型指针
    auto e = &i_auto;//e是指向整型常量对象的指针，

    const int x = 42;
    auto y = x;
    const auto &z = x;
    auto *q = &x;
    const auto m = x;
    const auto &n = x;
    cout << typeid(y).name() << endl;
    cout << typeid(z).name() << endl;
    cout << typeid(q).name() << endl;
    cout << typeid(m).name() << endl;
    cout << typeid(n).name() << endl;

    const int ci = 10, &cr = ci, *cip =&ci;
    decltype(ci) l = 12;
    decltype(cr) s = i;
    decltype(*cip) f = i;
    cout << l << endl;
    cout << s << endl;

    return 0;
}
