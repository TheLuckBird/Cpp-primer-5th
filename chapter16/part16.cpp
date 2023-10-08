#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstring>

using namespace std;

class Test
{
public:
    Test() = default;
    Test(int a_):a(a_){}
    bool operator<(const Test &y)
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

int main(int argc, char const *argv[])
{
    // int i=1,j=4;
    // cout << compare(i,j) << endl;
    // cout << compare(1,2) << endl;
    cout << compare(string("cpp"),string("java")) << endl;
    // Test a(1);
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
    cout << compare("c","h") << endl;

    return 0;
}
