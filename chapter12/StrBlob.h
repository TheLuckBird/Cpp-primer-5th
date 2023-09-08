#ifndef STRBLOB_H
#define STRBLOB_H
#include <memory>
#include <string>
#include <vector>
#include <initializer_list>

using namespace std;

class StrBlob
{
public:
    using size_type = vector<string>::size_type;

    StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
    StrBlob(std::initializer_list<std::string> il):data(make_shared<vector<string>>(il)){ }

    vector<string>::iterator begin() { return data->begin(); }
    vector<string>::iterator end() { return data->end(); }

    
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


#endif