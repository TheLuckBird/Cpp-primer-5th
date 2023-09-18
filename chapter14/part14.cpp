#include <iostream>
#include "Sales_data.h"
#include "A.h"

using namespace std;

int main(int argc, char const *argv[])
{
    // string a = "a";
    // string b = "a" + a;
    // cout << b << endl;

    Sales_data it1("cpp primer",12,2);
    Sales_data it2("algorithm",23,2);

    cout << it1 << endl;
    print(cout,it1);

    it1 += it2;
    cout << it1 << endl;

    cout << it2 << endl;

    A a(10);
    cout << a << endl;

    return 0;
}
