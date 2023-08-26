#include <vector>
#include <iostream>
#include <string>
#include "Sales_item.h"
using namespace std;

int main(int argc, char const *argv[])
{   
    // vector<string> str1{"hi"};
    // vector<string> str2{10};
    // vector<string> str3{10,"hi"};
    // vector<int> i(10,-2);
    // vector<double> d(10);
    // vector<Sales_item> s;

    // cout << i[0] << endl;

    // string world;
    // vector<string> text;
    // decltype(world.size()) length = 0;

    // while(cin >> world)
    //     text.push_back(world);
    // for(auto v:text)
    //     cout << v << endl;
    // for(auto &v:text)
    //     v = "X";
    // for(auto v:text)
    //     cout << v << endl;
    // cout << text.size() << endl;

    // vector<int> v1;
    // cout << v1.size();
    // for(auto v:v1)
    //     cout << v << endl;
    
    // cout << endl;
    // vector<int> v2(10);
    // cout << v2.size() << endl;
    // for(auto v:v2)
    //     cout << v << endl;

    // string word;
    // vector<string> text;

    // while(cin >> word)
    //     text.push_back(word);
    
    // for(auto &c:text)
    //     for(auto &b:c)
    //     if(b!=' ')
    //         b = toupper(b);
    
    // for(auto v:text)
    //     cout << v << endl;

    // vector<int> v1(10,42);
    // vector<string> v2{10,"42"};
    // vector<int> v3{42,42,42,42,42,42,42,42,42,42};
    // for(decltype(v2.size()) index=0;index<v2.size();++index)
    //     cout << v2[index] << endl;

    vector<int> v;
    // decltype(v.size()) index;
    // cout << index <<endl;
    int num;
    while(cin >> num)
        v.push_back(num);
    // for(auto x:v)
    //     cout << x << endl;
    int sum = 0;
    // for(decltype(v.size()) index = 0;index<v.size()-1;++index)
    // {
    //     sum = v[index] + v[index+1];
    //     cout << sum << endl;
    // }
    for(decltype(v.size()) index=0;index<v.size();++index)
    {
        sum = v[index] + v[v.size()-index-1];   
        cout << sum << " ";
    }     
    cout << endl;
    return 0;

}
