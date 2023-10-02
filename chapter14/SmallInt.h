#pragma once
#include <stdexcept>

using namespace std;

class SmallInt 
{
friend
    SmallInt operator+ (const SmallInt &, const SmallInt &) ;
public:
    SmallInt (double i = 0) : val(i)
    {
        if (i< 0|| i> 255)
            throw out_of_range("Bad SmallInt value") ;
    }
    operator double() const{return val; }
private :
    double val;
};
SmallInt operator+ (const SmallInt &a, const SmallInt &b) 
{
    return a.val + b.val;
}