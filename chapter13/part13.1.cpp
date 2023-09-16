#include <vector>
#include <algorithm>
#include "Foo.h"
#include "Numbered.h"
#include "Employee.h"
#include "HasPtr.h"
// #include "Message.h"
#include "StrVec.h"

using namespace std;

// void f1(Foo f){}
// void f2(Foo &f){}

int main(int argc, char const *argv[])
{
    // Foo f1(1,"cpp");
    // f1.print();
    // Foo f2 = f1;
    // f2.print();
    // Foo f3(f1);
    // Foo fx;
    // f1(f);
    // f2(f);
    
    // Foo *fp = new Foo(1,"cpp");
    // delete fp;

    // vector<Foo> vf;
    // vf.push_back(fx);

    
    // Numbered a,b=a,c=b;
    // f(a);f(b);f(c);

    // Employee a("cpp"),b("java"),c("C");
    // a.print();
    // b.print();
    // c.print();

    // Employee d(a);
    // d.print();

    // Employee e = b;
    // e.print();

    // HasPtr a("cpp");
    // a.print();
    // HasPtr b;
    // b=a;
    // b.print();

    // b = b;
    // b = "cpp";

    // cout << sizeof(string) << " " << sizeof(int);

    // HasPtr a{"cpp"};
    // HasPtr b{"java"};
    // swap(a,b);
    // a.print();
    // b.print();

    // vector<HasPtr> v{a,b};
    // v.push_back(a);
    // v.push_back(b);

    // cout << "排序前：" << endl;
    // for(auto p:v)
    //     p.print();
    
    // sort(v.begin(),v.end());

    // cout << "排序后：" << endl;
    // for(auto p:v)
    //     p.print();

   StrVec sv = {"one", "two", "three"};


    return 0;
}
