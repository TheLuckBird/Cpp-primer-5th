#include <string>
using std::string;
#include <iostream>
using std::endl; using std::cout; using std::cin;
using std::pair;
#include <vector>
using std::vector;
#include <stdexcept>
using std::runtime_error;


// bool is_prefix(vector<int> const &lhs,vector<int> const &rhs)
// {
//     if(lhs.size()>rhs.size())
//         return is_prefix(rhs,lhs);
//     for(int i=0;i!=lhs.size();++i)
//         if(lhs[i]!=rhs[i])
//             return false;
//     return true;
// }
int main(int argc, char const *argv[])
{   
    // string s;
    // string next_s = "\0";
    // unsigned sCnt = 0;
    // pair<string,int> max_duplicated;
    
    // while(cin >> s)
    // {
    //     if(s == next_s)
    //     {
    //         ++sCnt;
    //         next_s = s;
    //     }
    //     else
    //     {
    //         next_s = s;
    //         sCnt = 0;
    //     }    
    //     if(sCnt>max_duplicated.second) 
    //         max_duplicated = {s,sCnt};
    // }

    // if(max_duplicated.first.empty())
    //     cout << "There's no duplicated string." << endl;
    // else
    //     cout << max_duplicated.first << ':' << max_duplicated.second + 1;
    // string s;
    
    // while(cin >> s)
    // {
    //     for(auto c=s.begin();c!=s.end();++c)
    // {
    //     if(!isspace(*c))
    //         *c = toupper(*c);
    //     else 
    //         break;
    // }
    // cout << s << endl;
    // }
    
    // vector<int>v1{0,1,1,2},v2{0,1,1,2,3,5,8};
    // if(v1.size()<v2.size())
    // {
    //     for(auto v1_beg=v1.begin(),v2_beg=v2.begin();;++v1_beg,++v2_beg)
    //         if(*v1_beg == *v2_beg)
    //             {}
    //         else if(v1_beg == v1.end())
    //         {
    //             cout << "v1 is predix v2" << endl;
    //             break;
    //         }
    //         else 
    //         {
    //             cout << "v1 not predix v2" << endl;
    //             break;
    //         }
    // }

    // cout << (is_prefix(v1,v2) ? "yes!\n" : "no!\n");
    // string keepgoing;
    // do{
    //     cout << "input two strings:";
    //     string s1,s2;
        
    //     cin >> s1 >> s2;
    //     cout << "the longest is:" << (s1.size()>s2.size() ? s1 :s2) << endl << "more?yes:no" << endl; ;
    //     cin >> keepgoing;

    // }while(!keepgoing.empty()&&(keepgoing[0]!='n'));

    // string s;
    // string pre_s = "\0";
    // while(cin >> s)
    // {
    //     if(s == pre_s&&isupper(s[0]))
    //     {
    //         cout << s << endl;
    //         break;
    //     }
    //     else
    //     {
    //         pre_s = s;
    //     }
            
    // }
    // if(cin.eof()) 
    //     cout << "no same string." << endl;

    for (int i, j; cout << "Input two integers:\n", cin >> i >> j; )
    {
        try 
        {
            if (j == 0) 
                throw runtime_error("divisor is 0");
            cout << i / j << endl;
        }
        catch (runtime_error err) 
        {
            cout << err.what() << "\nTry again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }

    return 0;
}
