#ifndef HASPTR_H
#define HASPTR_H

#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr(const string &);
    HasPtr(HasPtr &);
    HasPtr& operator=(const HasPtr &); 
    ~HasPtr();
    auto print();


private:
    string *ps;
    int v;
    size_t *use;

};

HasPtr::HasPtr(const string &s=string()):ps(new string(s)),v(0),use(new size_t(1)){}
HasPtr::HasPtr(HasPtr &h):ps(new string(*(h.ps)) ),v(h.v),use(h.use){++*use;}
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

HasPtr::~HasPtr()
{
    if(--*use == 0)
    {
        delete ps;
        delete use;
    }
}

auto HasPtr::print()
{
    std::cout << ps << " " << v << endl;
}

#endif