// #ifndef STRVEC_H
// #define STRVEC_H

// #endif
#pragma once

#include <string>
#include <memory>
#include <utility>
#include <initializer_list>

using namespace std;
class StrVec
{
public:
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(const StrVec &);
    StrVec(std::initializer_list<std::string>);
    StrVec& operator=(const StrVec &);
    ~StrVec();

    void push_back(const string &s);
    void reserve(size_t n);
    size_t size() const{ return first_free - elements;}
    size_t capacity() const { return cap - elements;}
    string* begin()const { return elements;}
    string* end()const { return first_free;}

private:
    string *elements;
    string *first_free;
    string *cap;
    
    static allocator<string> alloc;

    
    pair<string*,string*> alloc_n_copy(const string*,const string*);
    void free();
    void chk_n_alloc(){ if(size()==capacity()) reallocate();}
    void reallocate();

};

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++,s);
}

pair<string*,string*> StrVec::alloc_n_copy(const string *b,const string *e)
{
    auto data = alloc.allocate(e-b);
    return {data,uninitialized_copy(b,e,data)};
}

void StrVec::free()
{
    if(elements)
    {
        for(auto p=first_free;p!=elements;--p)
            alloc.destroy(p);
        alloc.deallocate(elements,cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto data = alloc_n_copy(s.begin(),s.end());
    elements = data.first;
    first_free = cap = data.second;
}

StrVec& StrVec::operator=(const StrVec &s)
{
    auto data = alloc_n_copy(s.begin(),s.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::~StrVec(){ free();}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2*size():1;

    auto newdata = alloc.allocate(newcapacity);

    auto dest = newdata;
    auto elem = elements;

    for(size_t i=0;i!=size();++i)
        alloc.construct(dest++,std::move(*elem++));
    
    free();

    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t n)
{
    auto  p = alloc.allocate(n);
    elements = first_free = p;
    cap = p + n;
}

inline
StrVec::StrVec(std::initializer_list<std::string> il)
{
	// call alloc_n_copy to allocate exactly as many elements as in il
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
