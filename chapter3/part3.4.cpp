#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    // string s("some string");
    // auto v = s.begin();
    // if(s.begin() != s.end())
    //     *v = toupper(*v);
    // for(auto index=s.begin();index!=s.end()&&!isspace((*index));++index)
    //     *index = toupper(*index);
    // cout << s << endl; 

    // vector<string> s{"some","string"};
    
    // for(auto it = s.cbegin();it!=s.cend()&&!(*it).empty();++it)
    //     cout << *it << ' ';
    // cout << endl;
    // for(auto it = s.cbegin();it!=s.cend()&&!(it->empty());++it)
    //     cout << *it << ' ';
    // cout << endl;
    // vector<string> text;
    // for (string line; getline(cin, line); text.push_back(line));
    
    // for (auto& word : text)
    // {
    //     for (auto& ch : word)
    //         if (isalpha(ch)) ch = toupper(ch);
    //     cout << word << " ";
    // }
    // vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    // for(auto it=v.begin();it!=v.end();++it)
    //     *it = *(it)*2;
    // for(auto c:v)
    //     cout << c << ' ';
    
    // cout << endl;
    // int num;
    // vector<int> i;
    // while(cin >> num)
    // 	i.push_back(num);
    // for(auto index=i.begin();index!=i.end()-1;++index)
    //     cout << *index+*(index+1) << ' ';
    // cout << endl;
    
    // for(auto left=i.begin(),right=i.end()-1;left<=right;++left,--right)
    //     cout << *left + *right << ' ';
    // cout << endl;
    double grade;
    vector<double> grades;
    vector<int> score;
    while(cin >> grade)
        grades.push_back(grade);
    for(auto i=grades.begin();i!=grades.end();++i)
    {
        if ((*i) > 0.0)
            score.push_back((*i) / 10);
        else if((*i) == 100)
            score.push_back(10);
        else 
            cout << "输入不合法!" << endl;
    }
    for(auto i=score.begin();i!=score.end();++i)    
        cout << *i << ' ';
    cout << endl;   

    return 0;
}
