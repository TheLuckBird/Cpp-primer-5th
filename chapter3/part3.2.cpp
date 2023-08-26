#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    // string s1,s2;
    // cin >> s1 >> s2;
    // cout << s1 << endl;
    // cout << s2 << endl;

    // string world;
    // while (cin >> world)
    // {
    //     cout << world << endl;
    // }
    
    // string line;
    // while (getline(cin,line))
    // {
    //     if(!line.empty())
    //     {
    //         cout << line << endl;
    //         cout << "字符个数：" <<line.size() << endl;
    //     }    
    // }

    // string str1 = "abc";
    // string str2 = "abcd";
    // string str3 = "aec";

    // cout << (str1 < str2) << endl;//true
    // cout << (str1 < str3) << endl;//true
    // cout << (str2 < str3) << endl;//true

    // cout << (str1+str2) << endl;//abcabcd
    // cout << (str1 + "!" + "!") << endl;
    // string str1,str2;

    // cout << "输入两个字符串："  << endl;
    // cin >> str1 >> str2;
    
    // if(str1 == str2)
    //     cout << "str1==str2";
    // else if(str1 < str2)
    //     cout << str1;
    // else
    //     cout << str2;

    // return 0;

    // if(str1.size() == str2.size())
    //     cout << "str1==str2";
    // else if(str1.size() > str2.size()) 
    //     cout << str1 << ':' << str1.size();
    // else
    //     cout << str2 << ':' << str2.size();

    // cout << "longer string:" << ((str1.size() > str2.size() )? str1:str2) << endl;
    // string str;
    // for (string s; cin >> s; str+=(s.empty()? "":" ")+s);
    // cout << str << endl;
    // string s("hello cpp,i like cpp,yes!");
    // decltype(s.size()) punct_count = 0;//推断出无符号整数类型
    // for(auto c:s)
    //     if(ispunct(c))
    //         punct_count++;
    // cout << punct_count << endl;
    // string str("hello cpp");
    // for(auto &c:str)
    //     c = toupper(c);
    // cout << str << endl;
    // for(decltype(str.size()) index=0;index<str.size() && !isspace(str[index]);++index)
    //     str[index] = toupper(str[index]);
    // cout << str << endl;

    // const string hexdigits = "01234546789ABCDEF";

    // string result;
    // string::size_type n;

    // cout << "输入十进制数值：";
    // while (cin >> n)
    //     if(n < hexdigits.size())
    //         result += hexdigits[n];
    // cout << result << endl;

    // string hexdigits = "01234546789ABCDEF";

    // for(auto &c :hexdigits)
    //     c = 'X';
    // cout << hexdigits << endl;

    // for(decltype(hexdigits.size()) index=0;index<hexdigits.size();++index)
    //     hexdigits[index]='X';
    // cout << hexdigits << endl;

    string str("hi,cpp!!!");

    for(auto &c:str)
    	    if(ispunct(c))
                // cout << c;
                c = '\0';
    cout << str << endl;
}
