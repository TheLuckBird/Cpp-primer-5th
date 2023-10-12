#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstring>
#include <list>
#include <algorithm>
#include "Blob.h"

using namespace std;

class Test
{
public:
    Test() = default;
    Test(int a_):a(a_){}
    bool operator<(const Test &y) const
    {
        return a < y.a;
    }
private:
    int a = 0;
};

template <typename T>
int compare(const T &v1,const T &v2)
{
    if(v1 < v2) return 1;
    else return 0;
}

template <unsigned M,unsigned N>
int compare(const char(&a)[M],const char(&b)[N])
{
    return strcmp(a,b);
}

template <unsigned M>
int compare(const char(&a)[M], const char(&b)[M])
{
    return strcmp(a, b);
}

template <typename T> 
T self(T *p)
{
    return *p;
}

template <typename T> 
T self(shared_ptr<T> p)
{
    return *p;
}//模板也可以重载啊

// template<typename T> inline T min(const T&,const T&);//声明

template <typename I,typename T> I Find(I b,I e,const T &c)
{
    while(b!=e && *b!=c)
        ++b;
    cout << "自定义Find" << endl;
    return b;
}//find这么简单？

template <typename M,size_t N> void print(const M (&a)[N])
{
    for(auto i=begin(a);i!=end(a);i++)
        cout << *i << " " ;
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // int i=1,j=4;
    // cout << compare(i,j) << endl;
    // cout << compare(1,2) << endl;
    // cout << compare(string("cpp"),string("java")) << endl;
    // Test a(5);
    // Test b(2);
    // cout << compare(a,b) << endl;
    // // cout << (a<b) << endl;
    // cout << compare(vector<int>{1,2},vector<int>{3,4}) << endl; 

    // auto a = make_shared<int>(42);
    // cout << self(a) << endl;
    // // int a = 42;
    // cout << self(new int(42)) << endl;
    // cout << self(new string("cpp primer")) << endl;
    // // cout << self(new vector<int>{1,2}) << endl;
    // cout << self("pp") << endl;
    // cout << compare("c","h") << endl;

    // min(1,2);

    // vector<int> ivec{0,2,1,3,5};
    // cout << (Find(ivec.begin(),ivec.end(),56)==ivec.end() ? "没有找到" : "找到了") << endl;
    // list<string> ls{"cpp","primer"};
    // cout << (find(ls.begin(),ls.end(),"cpp2")==ls.end() ? "没有找到" : "找到了") << endl;

    // int ivec[4] = {1,23,0,88};
    // print(ivec);
    // string svec[2] = {"cpp","primer"};
    // print(svec);
    // print("hello");

    // Blob<int> data ({1,2,3}) ;

    // for(size_t i=0;i!=data.size();++i)
    //     data[i] = data[i]*data[i];
    // for(size_t i=0;i!=data.size();++i)
    //     cout << data[i] << " ";
    // cout << endl;

    // int a = 10;
    // cout << (*(&a)) << endl;
    // cout << *a << endl;

    return 0;
}
