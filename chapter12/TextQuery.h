#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>

using namespace std;

class TextQuery
{
public:
    TextQuery(string file_);
    auto word_query();
    auto print();
    auto show(string s);
private:
    string file;
    vector<string> text;
    map<string,multiset<int>> word_map;
    shared_ptr<map<string,multiset<int>>> p;
    
};

inline TextQuery::TextQuery(string file_):file(file_)
{
    string line;
    ifstream fin(file);
    while(getline(fin,line))
        text.push_back(line);
}

auto TextQuery::print()
{
    for(auto p:text) cout << p << endl;
}

auto TextQuery::word_query()
{
    for(int i=0;i!=text.size();++i)
    {
        stringstream sin1(text[i]);
        string s1;
        while(sin1 >> s1)
        {
            word_map[s1].insert(i);
        }
    }
    
}

auto TextQuery::show(string s)
{
    vector<int> ivec;
    for (const auto& entry : word_map) {
        for (const auto& number : entry.second) {
            ivec.push_back(number);
        }
        unique(ivec.begin(),ivec.end());
    }

    auto answer = word_map.find(s);
    if(answer == word_map.end())
        throw out_of_range("未找到");
    auto lines = answer->second;
    vector<int> line;
    for (const auto& number : lines ){
            line.push_back(number);
    }
    cout << s << "出现的次数" << line.size() << endl;
    unique(line.begin(),line.end());
    for(auto p:line)
    {
        cout <<'\t' << "(line " << p+1 <<") " << text[p] << endl;
    }
    std::cout << std::endl;
}

#endif