#ifndef A_H
#define A_H

#include <string>
#include <iostream>

using namespace std;

void foo(string *ps)
{
    cout << *ps << endl;
    // delete ps;
}

#endif

