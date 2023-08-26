#ifndef PERSON_H
#define PERSON_H

#include <string>
using std::string;
#include <iostream>
using std::istream; using std::ostream;

struct person
{
friend istream& read(istream& is,person& p);
friend ostream& print(ostream& os,person& p);

private:
    string name = "pfh";
    string address = "cqut";

public:
    person() = default;
    person(string n,string addr):name(n),address(addr){}
    person(istream& is);

    string get_name() const;
    string get_address() const;
    

};
string person::get_name() const 
{
    return name;
}

string person:: get_address() const
{
    return address;
}

istream& read(istream& is,person& p)
{
    is >> p.name >>p.address;
    return is;
}

ostream& print(ostream& os,person& p)
{
    os << p.name << ' ' <<  p.address;
    return os;
}

person::person(istream& is)
{
    read(is, *this);
}

#endif