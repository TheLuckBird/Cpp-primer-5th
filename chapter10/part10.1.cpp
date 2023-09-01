#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <numeric>
#include <fstream>
#include <functional>
#include <iterator>
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

void fcnl ()
{
    size_t v1 = 42; //局部变量
    //将v1拷贝到名为f的可调用对象
    auto f = [v1]{return v1;};
    v1 = 0;
    auto j = f();//j为42;f保存了我们创建它时v1的拷贝
    cout << "j:" << j << endl;
    cout << "v1:" << v1 << endl;
}

void fcn2 ()
{
    size_t v1 = 42; //局部变量
    //将v1拷贝到名为f的可调用对象
    auto f = [&v1]{return v1;};
    v1 = 0;
    auto j = f();//j为42;f保存了我们创建它时v1的拷贝
    cout << "j:" << j << endl;
    cout << "v1:" << v1 << endl;
}

void fcn3()
{
    size_t v1 = 42;
    auto f = [v1] () mutable {return ++v1;};
    cout << v1 << endl;//42
    cout << f() << endl;//43
}

void outsix(vector<string> &vs)
{
    cout << count_if(vs.begin(),vs.end(),[](string word){return word.size()>6?1:0;});
}

bool check_size(string s,size_t sz)
{
    return s.size() < sz;
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

    // string s1{"0-201-70353-X"};
    // string s2{"0-201-70353-X"};
    // string s3{"0-201-82470-1"};
    // Sales_data item1(s1),item2(s2),item3(s3);
    // vector<Sales_data> vs{item1,item2,item3};
    // sort(vs.begin(),vs.end(),[](Sales_data x,Sales_data y){return x.isbn()>y.isbn();});
    // for_each(vs.begin(),vs.end(),[](Sales_data item){cout << item.isbn();});

    // fcnl();
    // fcn2();
    // fcn3();
    // vector<string> vs{"cpp","c","object-c","java","python","go","gyujgfyug"};
    // outsix(vs);
    // int v;
    // cin >> v;
    // auto f = [&v]()->bool{for(;v!=0;){cout << --v << endl;}return true;};
    // f();

    // int i = 7;
    // auto check_and_decrement = [&i]() { return i > 0 ? !--i : !i; };
    // std::cout << "ex10.21: ";
    // while(!check_and_decrement())
    //     std::cout << i << " ";
    // std::cout << i << std::endl;

    // string s{"cpp"};
    // vector<int> ivec{0,1,2,3,4};
    // find_if()
    
    // vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7 };
    // string str("123456");
    // auto result = find_if(vec.begin(), vec.end(), bind(check_size, str, std::placeholders::_1));
    // if (result != vec.end())
    //     cout << *result << endl;
    // else
    //     cout << "Not found" << endl;

    // vector<int> vec{ 0, 1,1,1,1, 2,1,2, 3, 4, 5, 6, 7,9 };
    // std::vector<int> vec{ 1, 1, 3, 3, 5, 5, 7, 7, 9 };
    // list<int> li;
    // unique_copy(vec.begin(),vec.end(),back_inserter(li));
    // for(auto p:li) cout << p << " ";

    // std::vector<int> vec{ 1, 1, 3, 3, 5, 5, 7, 7, 9 };
    // std::list<int> lst;
    
    // std::unique_copy(vec.begin(), vec.end(), back_inserter(lst));
    // for (auto i : lst)
    //     std::cout << i << " ";
    // std::cout << std::endl;

    // vector<int> ivec{1,9};
    // list<int> il;
    // deque<int> id;
    // forward_list<int> ifo;
    // copy(ivec.begin(),ivec.end(),inserter(il,il.begin()));
    // for(auto p:il) cout << p <<" ";
    // cout << endl;
    // copy(ivec.begin(),ivec.end(),back_inserter(id));
    // for(auto p:id) cout << p <<" ";
    // cout << endl;
    // copy(ivec.begin(),ivec.end(),front_inserter(ifo));
    // for(auto p:ifo) cout << p <<" ";
    // cout << endl;

    // istream_iterator<int> int_iter(cin),eof;
    // vector<int> ivec(int_iter,eof);
    // for(auto p:ivec) cout << p <<" ";
    // cout << endl;
    // cout << "标准输入cin的和:" << accumulate(int_iter,eof,0);

    ostream_iterator<int> int_oi(cout," ");
    list<int> li{1,9,1,1,2,3};
    for(auto p:li)
        *int_oi++ = p;
    cout << endl;
    copy(li.begin(),li.end(),int_oi);


    return 0;
}
