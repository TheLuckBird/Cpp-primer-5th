#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "date.h"
#include <stack>
using namespace std;

void erase_insert(string &s,string const &oldVal,string const &newVal)
{
    for(auto iter=s.begin();iter<s.end()-oldVal.size();)
    {
        if(oldVal==string{iter,iter+oldVal.size()})
            iter = s.erase(iter,iter+oldVal.size()),iter = s.insert(iter,newVal.begin(),newVal.end()),iter += newVal.size();
        else
            ++iter; 
    }
}

void replace(string &s,string const &oldVal,string const &newVal)
{
    for(auto iter=s.begin();iter<s.end()-oldVal.size();)
    {
        if(oldVal == string{iter,iter+oldVal.size()})
            s.replace(iter,iter+oldVal.size(),newVal),iter += newVal.size();
        else
            ++iter;
    }
}

// string realname(string &name,string qian,string hou)
// {
//     name.insert(name.begin(),qian.begin(),qian.end());
//     name.append(hou);
//     return name;
// }

string realname(string &name,string qian,string hou)
{
    name.insert(0,qian),name.insert(name.size(),hou);
    return name;
}

int main(int argc, char const *argv[])
{
    // vector<string> vs;
    
    // cout << vs.size() << endl;
    // cout << vs.capacity() << endl;
    
    // for(int id=0;id<5;++id)
    //     vs.push_back("id");
    
    // cout << vs.size() << endl;
    // cout << vs.capacity() << endl;

    // vs.reserve(10);
    // cout << vs.size() << endl;
    // cout << vs.capacity() << endl;

    // while(vs.size()!=vs.capacity())
    //     vs.push_back("0");
    
    // cout << vs.size() << endl;
    // cout << vs.capacity() << endl;

    // for(auto p:vs)
    //     cout << p << " " ;

    // vector<char> cvec{'c','p','p'};
    // string s(cvec.begin(),cvec.end());
    // cout << s << endl;

    // string s = "some string", s2 = "some other string";
    // s. insert(0,s2); //在s中位置0之前插入s2的拷贝
    // //在s[0]之前插入s2中s2[0]开始的s2.size()个字符
    // s.insert (0, s2, 0,s2.size()) ;
    // cout << s << endl;

    // string s{ "To drive straight thru is a foolish, tho courageous act." };
    // erase_insert(s,"tho", "though");
    // erase_insert(s,"thru", "through");
    // cout << s << endl;

    // string s{ "To drive straight thru is a foolish, tho courageous act." };
    // replace(s, "tho", "though");
    // replace(s, "thru", "through");
    // cout << s << endl;

    // string language = "cpp";
    // cout << realname(language,"hi "," fuck hard!") << endl;

    // string info{"cppxyz"};
    // cout << info.find("px",3) << endl;//npos,默认值是-1
    // string::size_type x = -1 ;
    // cout << x << endl;

    // cout << info.find_first_of("cp") << endl;
    // cout << info.find_last_of("p") << endl;
    // cout << info.find_first_not_of("jhbsjdb") << endl;

    // string numbers{ "123456789" };
    // string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    // string str{ "ab2c3d7R4E6" };
    // for(auto number:alphabet)
    // {
    //     string::size_type pos = 0;
    //     while((pos=str.find_first_of(number,pos))!=string::npos)
    //     {
    //         cout << pos << " " ;++pos;
    //     }
    // }

    // for(auto number:numbers)
    // {
    //     string::size_type pos = 0;
    //     while((pos=str.find_first_not_of(number,pos))!=string::npos)
    //     {
    //         cout << pos << " " ;++pos;
    //     }
    // }    
    
    string numbers{ "123456789" };
    string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    string str{ "ab2c3d7R4E6" };

    // cout << "numeric characters: ";
    // for (int pos = 0; (pos = str.find_first_of(numbers, pos)) != string::npos; ++pos)
    //     cout << str[pos] << " ";
    // cout << "\nalphabetic characters: ";
    // for (int pos = 0; (pos = str.find_first_of(alphabet, pos)) != string::npos; ++pos)
    //     cout << str[pos] << " ";
    // cout << endl;

    // for (int pos = 0; (pos = str.find_first_not_of(alphabet, pos)) != string::npos; ++pos)
    //     cout << str[pos] << " ";
    // cout << "\nalphabetic characters: ";
    // for (int pos = 0; (pos = str.find_first_not_of(numbers, pos)) != string::npos; ++pos)
    //     cout << str[pos] << " ";
    // cout << endl;  

    // string::size_type pos = 0;
    // //每步循环查找name中下一个数
    // while ((pos = str.find_first_of (alphabet, pos))!= string::npos) 
    // {
    //     cout << "found number at index: " << pos << " element is " << str[pos] << endl;
    //     ++pos; // 移动到下一个字符
    // }

    // ifstream ifs("letter.txt");
    // if (!ifs) return -1;

    // string longest;
    // auto update_with = [&longest](string const& curr)
    // {
    //     if (string::npos == curr.find_first_not_of("aceimnorsuvwxz"))
    //         longest = longest.size() < curr.size() ? curr : longest;
    // };
    // for (string curr; ifs >> curr; update_with(curr));
    // cout << longest << endl; 

    // string s{"213afy"};
    // auto a = stoi(s);
    // cout << a << endl;

    // vector<string> s{"1","2","3"};
    // int sum = 0;
    // for(auto p:s)
    // {
    //     sum += stoi(p);
    // }
    // cout << sum << endl;

    // date d("Jan 1 1900");
    // d.print();

    string expression{ "This is (pezy)." };
    bool bSeen = false;
    stack<char> stk;
    for (const auto &s : expression)
    {
        if (s == '(') { bSeen = true; continue; }
        else if (s == ')') bSeen = false;
        
        if (bSeen) stk.push(s);
    }
    
    string repstr;
    while (!stk.empty())
    {
        repstr += stk.top();//This is (yzep).
        repstr.insert(0,1,stk.top()) ;//This is (pezy).
        stk.pop();
    }
    
    expression.replace(expression.find("(")+1, repstr.size(), repstr);
    
    cout << expression << endl;

    return 0;
}
