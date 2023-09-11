#ifndef STRBLOB_H
#define STRBLOB_H
#include <memory>
#include <string>
#include <vector>
#include <initializer_list>

using namespace std;

class StrBlobPtr
{
    friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr():curr(0){ }
    // StrBlobPtr(StrBlob &a,size_t sz=0):wptr(a.data),curr(sz){ }
    

    string& deref() const
    {
        auto p = check(curr,"dereference past end");
        return (*p)[curr];
    }

    StrBlobPtr& incr()
    {
        check(curr,"increment past of end");
        ++curr;
        return *this;
    }


private:
    shared_ptr<vector<string>> check(size_t i,const string &msg) const
    {
        auto ret = wptr.lock();
        if(!ret)
            throw runtime_error("unbound StrBlobPtr");
        if(i >= ret->size())
            throw out_of_range(msg);
        return ret;
    }
    weak_ptr<vector<string>> wptr;
    size_t curr;
};
class StrBlob
{
    friend class StrBlobPtr;
public:
    using size_type = vector<string>::size_type;

    StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
    StrBlob(std::initializer_list<std::string> il):data(make_shared<vector<string>>(il)){ }

    // StrBlobPtr begin() { return StrBlobPtr(*this);}
    // StrBlobPtr end() { auto ret = StrBlobPtr(*this,data->size());return ret; }

    
    void push_back(const std::string &t) { data->push_back(t); }

    string & front(){ check(0,"front on empty StrBlob");return data->front();}


private:
    shared_ptr<vector<string>> data;
    void check(size_type sz,string msg)
    {
        if(sz >= data->size())
            throw out_of_range(msg);
    }

};

inline
bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	// if the underlying vector is the same 
	if (l == r) 
		// then they're equal if they're both null or 
		// if they point to the same element
		return (!r || lhs.curr == rhs.curr);
	else
		return false; // if they point to difference vectors, they're not equal
}

inline
bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !eq(lhs, rhs); 
}

#endif