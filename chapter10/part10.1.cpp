#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <numeric>
#include <fstream>
#include "Sales_data.h"

using namespace std;

bool isShorter (const string &s1, const string &s2)
{
    return s1.size() < s2.size() ;
}

void elimDups(vector<string> &words)
{   
    cout << "输入时：" << endl;
    for(auto p:words) cout << p << " ";
    cout << endl;
    stable_sort(words.begin(),words.end(),isShorter);
    cout << "排序后：" << endl;
    for(auto p:words) cout << p << " ";
    cout << endl;
    auto end_unique = unique(words.begin(),words.end());
    cout << "去重后：" << endl;
    for(auto p:words) cout << p << " ";
    cout << endl;
    words.erase(end_unique,words.end());
    cout << "删除后：" << endl;
    for(auto p:words) cout << p << " ";
    cout << endl;

}

bool compareIsbn(Sales_data item1,Sales_data item2)
{
    return item1.isbn() > item2.isbn();
}

bool out5(string s)
{
    return s.size() > 5;
}

int main(int argc, char const *argv[])
{
    // vector<int> ivec{1,2,3,1,2,1,1,2,4,56};
    // list<string> sl{"aa","aa","aa","cpp"};
    // int number = 1 ;
    // int c = count(ivec.begin(),ivec.end(),number);
    // cout << count(sl.cbegin(),sl.cend(),"aa") << endl;
    // std::list<std::string> l = { "aa", "aaa", "aa", "cc" };
    // std::cout << "ex 10.02: " << std::count(l.cbegin(), l.cend(), "aa") << std::endl;
    // cout << c << endl;

    // int sum = accumulate(ivec.cbegin(),ivec.cend(),0);
    // cout << sum << endl;

    // std::vector<const char *> roster1{"Mooophy", "pezy", "Queequeg"};
    // std::list<const char *> roster2{"Mooophy", "pezy", "Queequeg", "shbling", "evan617"};
    // std::cout << std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) << endl;

    // std::cout << (void*)roster1[0] << std::endl;
    // std::cout << (void*)roster2.front() << std::endl;

    // const char a[3][2] = {"A", "B", "C"};
    // const char b[3][2] = {"A", "B", "C"};

    // const char *a[3] = {"A", "B", "C"};
    // const char *b[3] = {"A", "B", "C"};

    // std::vector<const char*> v1(std::begin(a), std::end(a));
    // std::list<const char*> v2(std::begin(b), std::end(b));

    // std::cout << std::boolalpha << std::equal(v1.cbegin(), v1.cend(), v2.cbegin()) << std::endl;
    // c 风格的字符串不能使用 == 和 < 和 > 进行比较，因为这些关系运算符比较指针中的地址而不是 char 指针表示的字符串。
    // roster1 中的“Mooophy”、“pezy”、“Queequeg”和 roster2 中的“Mooophy”、“pezy”、“Queequeg”都是文字，编译器将它们优化为存储在相同的地址中。从而得到1。
    // 因此，指针指向的相同内容的文字共享相同的内存，但数组中的文字是单独存储的。
    
    // fill_n(ivec.begin(),ivec.size(),0);
    // fill(ivec.begin(),ivec.end(),0);

    // for(auto p:ivec) cout << p << " " ;

    // string word;
    // vector<string> words;
    // while(cin >> word)
    //     words.push_back(word);
    // elimDups(words);

    // string s1{"0-201-70353-X"};
    // string s2{"0-201-70353-X"};
    // string s3{"0-201-82470-1"};
    // Sales_data item1(s1),item2(s2),item3(s3);
    // vector<Sales_data> vs{item1,item2,item3};
    // sort(vs.begin(),vs.end(),compareIsbn);

    // for(auto p:vs)
    //     cout << p.isbn() << " ";
    
    // string word;
    // vector<string> words;
    // while(cin >> word)
    //     words.push_back(word);
    // cout << "输入时：" << endl;
    // for(auto p:words) cout << p << " ";
    // cout << endl;
    // auto out5iter = partition(words.begin(),words.end(),out5);
    // auto out5iter = partition(words.begin(),words.end(),[](string word){return word.size()>5;});
    // cout << words.end()-out5iter << endl;
    // cout << "排序后：" << endl;
    // for(auto p:words) cout << p << " ";
    // cout << endl;

    // for(auto iter=words.begin();iter!=out5iter;++iter)
    //     cout << *iter << " ";

    // cout <<endl << "===========" << endl;
    // string::size_type sz = 5;
    // stable_sort(words.begin(),words.end(),[](const string &a, const string &b) 
	//               { return a.size() < b.size();});
    // auto first_iter = find_if(words.begin(),words.end(),[](string word){return word.size()>5;});
    // cout << words.end()-first_iter << endl;
    // for(auto iter=first_iter;iter!=words.end();++iter)
    //     cout << *iter << " ";
    // cout << endl;
    // for(auto iter=words.begin();iter!=first_iter;++iter) cout << *iter << " ";
    // int a,b;
    // cout << "输入2个数字:"  << endl;
    // cin >> a >> b;
    // auto sum = [a,b]()->int{return a+b;};
    // cout << sum() << endl;
    // auto sum = [](int x,int y)->int{return x+y;};
    // cout << sum(a,b) << endl;

    string s1{"0-201-70353-X"};
    string s2{"0-201-70353-X"};
    string s3{"0-201-82470-1"};
    Sales_data item1(s1),item2(s2),item3(s3);
    vector<Sales_data> vs{item1,item2,item3};
    sort(vs.begin(),vs.end(),[](Sales_data x,Sales_data y){return x.isbn()>y.isbn();});
    for_each(vs.begin(),vs.end(),[](Sales_data item){cout << item.isbn();});

    return 0;
}
