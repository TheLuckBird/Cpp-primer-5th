#include <iostream>
#include <algorithm>
#include "Sales_data.h"
#include "A.h"
#include "GetInput.h"
#include "Cmp.h"

using namespace std;

int main(int argc, char const *argv[])
{
    // string a = "a";
    // string b = "a" + a;
    // cout << b << endl;

    // Sales_data it1("cpp primer",12,2);
    // Sales_data it2("algorithm",23,2);
    
    // cout << it1 + it2 << endl;

    // cout << it1 << endl;
    // print(cout,it1);

    // it1 += it2;
    // cout << it1 << endl;

    // cout << it2 << endl;

    // A a(10);
    // cout << a << endl;

    // A x,y;
    // cin >> x >> y;
    // cout << x << endl;
    // cout << y << endl;
    // A sum = x + y;
    // // A sum;
    // // sum += x;
    // cout << ++sum << endl;

    // cout << (it1==it2? 1:0) << endl;

    // GetInput getInput;

    // std::cout << getInput() << std::endl;

    // Cmp a(1,11);
    // cout << a() << endl;

    vector<int> ivec { 1,2,4,6,3,2,1,9,68};
    Cmp c;
    int v;
    cin >> v;
    // for(auto &p:ivec)
    // {
    //     if(c(p,v))
    //         p = 0;
    // }

    for_each(ivec.begin(),ivec.end(),[&](int &p){if(c(p,v)) p=0;});

    for_each(ivec.begin(),ivec.end(),[](int p){cout << p << " ";});

    // replace_if();
    return 0;
}
