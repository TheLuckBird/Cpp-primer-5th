#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "StrBlob.h"

using namespace std;

auto ivec()
{
    // auto i = new vector<int>;
    shared_ptr<vector<int>> i = make_shared<vector<int>>();
    return i;
}

// auto read(vector<int> *p)
auto read(shared_ptr<vector<int>> p)
{
    int number;
    while (cin >> number)
    {
        p->push_back(number);
    } 
}

// auto print(vector<int> *p)
auto print(shared_ptr<vector<int>> p)
{
    for(auto v:*p)
        cout << v << " ";
    cout << endl;
    // delete p;
    // p = nullptr;
}


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

    // const int *p = new const int(668);
    // const int *v = new (nothrow) int(38);
    // delete p;
    // delete v;

    // shared_ptr<int> p = make_shared<int>(0);
    // cout << *p << endl;
    // *p = 1;
    // cout << *p << endl;

    // auto v = ivec();
    // read(v);
    // print(v);

    // shared_ptr<int> pi;
    // cout << pi << endl;
    // // cout << *pi << endl;
    // shared_ptr<int> pi1(new int(100));
    // cout << pi1 << endl;
    // cout << *pi1 << endl;

    // shared_ptr<int> p;
    // // p = new int();
    // p.reset(new int(10));

    shared_ptr<string> p(new string("Hello!"));
	// shared_ptr<string> p2(p);    // two users of the allocated string
	string newVal;
	if (!p.unique())
		p.reset(new string(*p)); // we aren't alone; allocate a new copy
	*p += newVal; // now that we know we're the only pointer, okay to change this object 
	// cout << *p << " " << *p2 << endl;
    cout << *p << endl;
    return 0;
}

