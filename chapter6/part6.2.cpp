#include <iostream>
using std::endl; using std::cout; using std::cin;
#include <string>
using std::string;
using std::initializer_list;
#include <vector>
using std::vector;
#include "D:\code\cpp\GCC_4_7_0\6\make_plural.h"
#include <cassert>

#define NDEBUG

// inline void swap(int &p,int &q)
// {   
//     int temp = p;
//     p = q;
//     q = temp;
// }

// string::size_type find_char(const string &s,char c,string::size_type &ocr)
// {
//     auto index = s.size();
//     ocr = 0;
//     for(decltype(index) i=0;i!=s.size();++i)
//     {
//         if(s[i] == c){
//             if(index == s.size())
//                 index = i;
//             ++ocr;
//         }
//     }
//     return ocr;
// }
// bool find_upper(const string &s)
// {
//     for(auto c:s)
//     {
//         if(isupper(c))
//             return true;
//     }
//     return false;
// }

// string to_upper(string &s)
// {
//     for(auto &c:s)
//     {
//         c = toupper(c);
//     }
//     return s;
// }

// void swap_ptr(int *&p,int *&q)
// {
//     int *&temp = p;
//     p = q;
//     q = temp;
// }

// void vp(initializer_list<string> list)
// {
//     for(auto &v:list)
//         cout << v << ' ';
// }

// void sum(initializer_list<int> list)
// {
//     int sum = 0;
//     for(auto &v:list)
//         sum += v;
//     cout << "the sum:" << sum << endl; 
// }

// void print_vector(vector<int>::iterator p,vector<int>::iterator q)
// {

// #ifndef NDEBUG
//         cout << (q-p) << endl;
// #endif

//     if(p!=q)
//     {
//         cout << *p << ' '; 
//         print_vector(++p,q);
//     }
//     return ;
// }

// void print()
// {
//     cout << "print()" << endl;
// }

// void print(int a)
// {
//     cout << "print(int a)" << endl;
// }

// void print(int a,int b)
// {
//     cout << "print(int a,int b)" << endl;
// }

// void print(double a,double b)
// {
//     cout << "print(double a,double b)" << endl;
// }

// void f(char *){}
// void f(char * const){}
// void f(char &){}

int main(int argc, char const *argv[])
{
    // int x = 1, y = 2;
    // swap(1,2);//非常量引用的初始值必须为左值
    // for(int x,y;cout << "enter two number:",cin >> x >> y;)
    // {
    //     swap(x,y);
    //     cout << x << endl;
    //     cout << y << endl;
    // }
    
    // string s;
    // cin >> s;
    // string::size_type ocr;

    // string::size_type idx = find_char(s,'a',ocr);

    // cout << "a ocr times in s:" << ocr << endl;
    // cout << "a first index in s:" << idx << endl; 
    // string s;
    // cin >> s;
    // bool is_upper = find_upper(s);
    // cout << is_upper << endl;
    // string upper = to_upper(s);
    // cout << s << endl;

    // int x = 1, y = 2;
    // int * a = &x;
    // int * b = &y;
    // swap_ptr(a,b);
    // cout << x << endl;
    // cout << y << endl;

    // string s;
    // for(int i = 0;i!=argc;++i)
    // {
    //     s = s + ' ' + argv[i];
    // }
    // cout << s <<endl;

    // initializer_list<string> string_llist;
    // string_llist = {"hi,cpp!","i want a job!"};
    // string s = "ok!";

    // vp({"hi,cpp!","i want a job!",s});

    // const int a[] = {1,2,3,4,5,6,7,8,9};
    // int a = 10,b = 20,c = 30;
    // sum({a,b,c,40});

    // vector<int> a = {1,2,3};
    // print_vector(a.begin(),a.end());

    // cout << make_plural(5,"cpp","!!!") << endl;
    // int x  = 1, y = 2;
    // assert(x>y);
    // cout << __func__ << endl;
    // cout << __FILE__ << endl;
    // cout << __LINE__ << endl;
    // cout << __DATE__ << endl;
    // cout << __TIME__ << endl;

    // print(2.56,42);
    // print();
    // print(42);
    // print(2.56,3.14);
    return 0;
}
