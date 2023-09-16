#ifndef HASPTR_H
#define HASPTR_H

#include <string>

using namespace std;

class HasPtr
{
    friend void swap(HasPtr &,HasPtr &);
public:
    HasPtr(const string &);
    HasPtr(const HasPtr &);
    HasPtr& operator=(const HasPtr &); 
    bool operator<(const HasPtr &);
    ~HasPtr();
    void print();


private:
    string *ps;
    int v;
    size_t *use;

};

inline void swap(HasPtr &lhs,HasPtr &rhs)
{
    cout << "执行swap" << endl;
    using std::swap;
    swap(lhs.ps,rhs.ps);
    swap(lhs.v,rhs.v);
}

HasPtr::HasPtr(const string &s=string()):ps(new string(s)),v(0),use(new size_t(1)){}
HasPtr::HasPtr(const HasPtr &h):ps(new string(*(h.ps)) ),v(h.v),use(h.use){++*use;}
HasPtr& HasPtr::operator=(const HasPtr &h)
{
    ++*h.use;
    if(--*use)
    {
        delete ps;
        delete use;
    }
    ps = h.ps;
    v = h.v;
    use = h.use;
    return *this;//返回本对象
}

bool HasPtr::operator<(const HasPtr &rhs)
{
    return *ps < *rhs.ps;
}

HasPtr::~HasPtr()
{
    if(--*use == 0)
    {
        delete ps;
        delete use;
    }
}

void HasPtr::print()
{
    std::cout << *ps << " " << v << endl;
}

#endif