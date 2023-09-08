#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "StrBlob.h"

using namespace std;

int main(int argc, char const *argv[])
{
    // auto p = make_shared<vector<string>>("cpp","java");
    
    // auto p = make_shared<vector<string>>(initializer_list<string>{"cpp", "java"});
    // for(auto v:*p)
    //     cout << v << endl;
    
    // StrBlob a = {"cpp","java"};
    // a.push_back("python");
    // for(auto p:a)
    //     cout << p << " " ;
    // cout << endl;

    // int *pi = new int;
    // int *pi = new int();
    // int *pi = new int(1024);
    // string *ps = new string;
    // string *ps = new string(10,'9');
    // vector<string> *pvs = new vector<string>{"1","cpp","2","python"};
    // cout << pi << ":" << *pi << endl;
    // cout << ps << ":" << *ps << endl;
    // for(auto p:*pvs) cout << p << " " ;

    // auto p = new auto("cpp");
    // auto v = new auto{1};
    // cout << *p << endl;
    // cout << *v << endl;

    const int *p = new const int(668);
    const int *v = new (nothrow) int(38);
    return 0;
}

