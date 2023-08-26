#include <iostream>
using std::endl; using std::cout; using std::cin;
#include <vector>
using std::vector;
#include <cassert>


// void f(){
//     cout << __func__ << endl;
// }

// typedef void (*ptr_f1)();
// typedef decltype(f) *ptr_f2;

// void foo(ptr_f2)
// {
//     cout << __func__ << endl;
//     f();
// }

// void f(int x,int y)
// {
//     cout << __func__ << ':' << x+y << endl;
// }
// void (*rt_func_ptr(int x))(int,int)
// {
//     cout << x << endl;
//     return f;
// }

// using F = void(int,int);
// using FP  = void(*)(int,int);

// FP rfp(int x)
// {
//     cout <<__func__ << ':' << x << endl;
//     return f;
// }

int add(int x,int y)
{
    return x + y;
} 

int sub(int x,int y)
{
    return x - y;
}

int mul(int x,int y)
{
    return x * y;
}

int divd(int x,int y)
{   
    assert(y!=0);
    return x / y;
}

//定义指针函数的若干方式：

// using fp = int(*)(int,int);
// vector<fp> vfp{add,sub,mul,divd};

// using f = int(int,int);
// vector<f *> vfp{add,sub,mul,divd};

// using f = decltype(add);
// vector<f *> vfp{add,sub,mul,divd};

// typedef int(*fp)(int,int);
// vector<fp> vfp{add,sub,mul,divd};

// typedef int f(int,int) ;
// vector<f *> vfp{add,sub,mul,divd};

// typedef decltype(add) *fp;
// vector<fp> vfp{add,sub,mul,divd};


int main(int argc, char const *argv[])
{
    // void (*p)() =f;
    // cout << p << endl;
    // (*p)();
    // p();
    // f();

    // typedef void func1();
    // typedef decltype(f) func2;
    
    // ptr_f1 a = f;
    // foo(a);
    // ptr_f2 b = f;
    // foo(b);
    // auto f = rt_func_ptr(2);
    // f(1,2);
    // auto f = rfp(1);
    // f(1,2);

    // for(auto v:vfp)
    //     cout << v(12,3) << endl;
    return 0;
}
