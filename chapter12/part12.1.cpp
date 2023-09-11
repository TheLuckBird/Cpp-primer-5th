#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
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

struct connection {
    std::string ip;
    int port;
    connection(std::string ip_, int port_):ip(ip_), port(port_){ }
};
struct destination {
    std::string ip;
    int port;
    destination(std::string ip_, int port_):ip(ip_), port(port_){ }
};

connection connect(destination* pDest)
{
    std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
    return *pConn;
}

void disconnect(connection pConn)
{
    std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << std::endl;
}

void end_connection(connection *pConn)
{
    disconnect(*pConn);
}

void f(destination &d)
{
    connection conn = connect(&d);
    std::shared_ptr<connection> p(&conn, end_connection);
    std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
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

    // shared_ptr<string> p(new string("Hello!"));
	// // shared_ptr<string> p2(p);    // two users of the allocated string
	// string newVal;
	// if (!p.unique())
	// 	p.reset(new string(*p)); // we aren't alone; allocate a new copy
	// *p += newVal; // now that we know we're the only pointer, okay to change this object 
	// // cout << *p << " " << *p2 << endl;
    // cout << *p << endl;

    // destination dest("202.118.176.67", 3316);
    // f(dest);

    // unique_ptr<string> ups (new string("coo"));
    // unique_ptr<string> p(ups);
    // unique_ptr<string> p1 = ups;

    fstream fin("word.txt");
    StrBlob s;
    // StrBlobPtr sp(s);
    string line;

    while(getline(fin,line))
    {
        s.push_back(line);
    }

    for(auto it=s.begin();neq(it,s.end());it.incr())
    {
        cout << it.deref() << endl;
    }

    return 0;
}

