#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

class Employee
{
public:
    int id;
    Employee();
    Employee(string);
    Employee(Employee&);
    Employee& operator=(const Employee &);
    auto print();

private:
    string name;
    static int seq;
};

Employee::Employee():id(seq++){}
Employee::Employee(string name_):name(name_),id(seq++){}
Employee::Employee(Employee &e):name(e.name),id((e.seq)++){}
Employee&Employee::operator=(const Employee &e){name=e.name;id=e.seq++;return *this;}

int Employee::seq = 0;

auto Employee::print()
{
    cout << "ID:" << id << "  name:" << name << endl;
}
#endif