#ifndef NUMBERED_H
#define NUMBERED_H

#include <iostream>

using namespace std;

class Numbered
{
public:
    Numbered(){mysn = seq++;}
    Numbered(const Numbered &);

    int mysn = 0;
private:
    static int seq;
};

int Numbered::seq = 0;
Numbered::Numbered(const Numbered &s){ mysn = seq++;}
void f(Numbered s){ cout << s.mysn << endl;}
#endif