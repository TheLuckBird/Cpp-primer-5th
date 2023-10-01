// #pragma once
#ifndef STRSIZE_H
#define STRSIZE_H

using namespace std;

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

class Strsize
{
public:
    bool operator()(string &,int);
    void print();
private:
    map<string,int> str_ifo;

};

bool Strsize::operator()(string &s,int l=0)
{
    str_ifo[s] = s.size();
    if(l==s.size())
        return true;
    else
        return false;
}

void Strsize::print()
{
    vector<int> cnt;
    for(auto p:str_ifo)
    {
        // cout << p.first << ":" << p.second << endl;
        cnt.push_back(p.second); 
    }
    for(int i=0;i!=10;++i)
    {
        cout << "长度为" << i << "的单词个数：" << count(cnt.begin(),cnt.end(),i) << endl;
    }     

}

#endif