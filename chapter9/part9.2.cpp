#include <vector>
#include <iostream>
#include <list>
#include <deque>
#include <forward_list>
#include <array>

using namespace std;

// bool search(vector<int> &vi,int &number)
// {
//     auto b = vi.begin();
//     auto e = vi.end();
//     while(b != e)
//     {
//         if((*b) == number)
//             return true;
//         ++b;
//     }
//     return false;
// }

int search(vector<int> &vi,int &number)
{
    auto b = vi.begin();
    auto e = vi.end();
    while(b != e)
    {
        if((*b) == number)
            return *b;
        ++b;
    }
    return 99999;
}

bool cmp_int_vec(vector<int> &vi1,vector<int> &vi2)
{
    if(vi1 == vi2)
        return true;
    else
        return false;
}

void cmp_int_vec(vector<int> &vi1,list<int> &vi2)
{
    cout << "element compare:" << endl;
    if(vi1.empty() && !vi2.empty())
        cout << "vi1 < vi2" << endl;
    else if(!vi1.empty() && vi2.empty())
        cout << "vi1 > vi2" << endl;
    else
    {
        auto bi_vi1 = vi1.begin();
        auto ei_vi1 = vi1.end();
        auto bi_vi2 = vi2.begin();
        auto ei_vi2 = vi2.end();
        while (bi_vi1!=ei_vi1 && bi_vi2!=ei_vi2 )
        {
            if((*bi_vi1) == (*bi_vi2))
                cout << "=" << endl;
            else if((*bi_vi1) > (*bi_vi2))
                cout << ">" << endl;
            else
                cout << "<" << endl;

            ++bi_vi1;
            ++bi_vi2;
            
        }
        cout << "compare result:" << endl;
        if(bi_vi1==ei_vi1 && bi_vi2==ei_vi2)
            cout << "vi1 = vi2" << endl;
        else if(bi_vi1!=ei_vi1)
            cout << "vi1 > vi2" << endl;
        else
            cout << "vi1 < vi2" << endl;
    }
       
    

}

void insert_string(forward_list<string> &fls,string &s1,string &s2)
{
    auto pre = fls.before_begin();
    auto curr = fls.begin();
    while(curr!=fls.end())
    {
        if(*curr == s1)
        {
            fls.insert_after(curr,s2);
            return;
        }
        else
        {
            pre = curr;
            ++curr;
        }
    }

    fls.insert_after(pre,s2);
}

void find_and_insert(forward_list<string> &list, string const& to_find, string const& to_add)
{
    auto prev = list.before_begin();
    for (auto curr = list.begin(); curr != list.end(); prev = curr++)
    {
        if (*curr == to_find)
        {
            list.insert_after(curr, to_add);
            return;
        }
    }
    list.insert_after(prev, to_add);
}

int main(int argc, char const *argv[])
{
    // cout << "输入查询的数字：" << endl;
    // int number;
    // cin >> number;
    // vector<int> vi = {11,23,675,78,1,787,99,100};

    // bool is_find = search(vi,number);
    // if(is_find)
    //     cout << "查询到了" << number;
    // else
    //     cout << "没查到" << number;

    // cout << search(vi,number) << endl;

    // list<string> a = { "Milton","Shakespeare", "Austen"};
    // auto it1 = a.begin();//list<string> : :iterator
    // auto it2 = a.rbegin (); // list<string> : :reverse_iterator
    // auto it3 = a.cbegin (); // list<string> : :const_iterator
    // auto it4 = a.crbegin();// list<string> : :const_reverse_iterator

    // auto it1 = a.begin();//list<string> : :iterator
    // list<string>::iterator it2 = a.begin();//list<string> : :iterator
    
    // list<string> authors = {"Milton", "Shakespeare", "Austen"};
    // vector<const char*> articles = {"a", "an", "the" };
    // list<string> list2 (authors) ;//正确:类型匹配
    //deque<string> authList(authors); //错误:容器类型不匹配
    //vector<string> words (articles); //错误:容器类型必须匹配
    //正确:可以将const char*元素转换为string
    // forward_list<string> words (articles.begin(), articles.end () );

    // string it;
    // deque<string> list(authors.begin(),it); 

    // vector<int> ivec (10,-1) ;
    // // 10个int元素，每个都初始化为-1
    // list<string> svec (10,"hi ! ");
    // //10个strings;每个都初始化为"hi
    // forward_list<int> ivec1(10) ;
    // // 10个元素，每个都初始化为0
    // deque<string> svec1(10) ;
    // // 10个元素，每个都是空string

    // array<int, 42> x;
    // //类型为:保存42个int的数组
    // array<string, 10> y;
    // //类型为:保存10个string的数组

    // array<int,10> ial;
    // //10个默认初始化的int
    // array<int,10> ia2 = {0,1,2,3,4,5,6,7,8,9};
    // //列表初始化
    // array<int,10> ia3 = {42}; 
    // //ia3 [0]为42，剩余元素为0

    // list<int> li(4,4);
    // vector<int> vin(5,5);
    // // vector<double> vd(li.begin(),li.end());
    // vector<double> vd(vin.begin(),vin.end());
    // for(auto p:vd)
    //     cout << p << " ";

    // array<int, 10> al = {0,1,2,3,4,5,6,7,8,9};
    // array<int, 10> a2 = {0}; //所有元素值均为0
    // al = a2;//替换a1中的元素
    // a2 = {0}; //错误:不能将一个花括号列表赋予数组

    // list<string> names;
    // vector<const char*> oldstyle;
    // // names = oldstyle;
    // names.assign(oldstyle.cbegin(),oldstyle.cend());
    // names.assign(2,"hu");

    // cout << *(names.begin());

    // list<const char *> lcp{"pfh","xyz"};
    // vector<string> vs;
    // vs.assign(lcp.cbegin(),lcp.cend());
    // for(auto p:vs)
    //     cout << p << endl;

    // vector<int> vi1 = {0,1,2,3};
    // vector<int> vi2 = {0,1,2,3};
    // vector<int> vi3 = {0,1,2,3,4};
    // vector<int> vi4 = {5};

    // cout << cmp_int_vec(vi1,vi2) << endl;
    // cout << cmp_int_vec(vi1,vi3) << endl;
    // cout << cmp_int_vec(vi1,vi4) << endl;

    // vector<int> vi = {1,2,5};
    // list<int> li = {1,2,3};
    // cmp_int_vec(vi,li);
    
    // cout << (vector<int>(vi.begin(),vi.end()) == li ? true : false) << endl;
    // std::cout << (std::list<int>(vi.begin(), vi.end()) == li ? "true" : "false") << std::endl;//用迭代器定义一个同类型容器，==要求
    //深受打击。

    // list<int> list;

    // for(size_t idx=0;idx!=4;++idx)
    //     list.push_front(idx);
    
    // cout << "----------" << endl;

    // for(auto p:list)
    //     cout << p << ' ';
    
    // list.insert(list.end(),-1);

    // cout << "----------" << endl;

    // for(auto p:list)
    //     cout << p << ' ';

    // list.insert(list.begin(),4);    
    // cout << "----------" << endl;

    // for(auto p:list)
    //     cout << p << ' ';

    // int i;
    // auto iter = list.begin();
    // while(cin >> i)
    //     iter = list.insert(iter,i);

    // cout << "----------" << endl;

    // for(auto p:list)
    //     cout << p << ' ';

    // string input;
    // deque<string> output;
    // while(cin >> input)
    //     output.push_back(input);
    // //better code
    // //  for (string str; cin >> str; input.push_back(str));
    // for(auto p:output)
    //     cout << p << " ";

    // list<int> number{0,1,2,3,4};
    // deque<int> ou_number;
    // deque<int> ji_number;
    // for(auto p:number)
    // {
    //     // if(p%2==0)
    //     //     ou_number.push_back(p);
    //     // else
    //     //     ji_number.push_back(p);
    //     //better code
    //     p % 2 ==0 ? ou_number.push_back(p) : ji_number.push_back(p);
    // }

    // for(auto p:ou_number)
    //     cout << p << " ";
    // cout << endl;
    // for(auto p:ji_number)
    //     cout << p << " ";

    // list<string> c{"pfh","cpp","data struct"};
    // //在解引用一个迭代器或调用front或back之前检查是否有元素
    // if ( !c.empty())
    // {
    //     // val和val2是c中第一个元素值的考贝
    //     auto val = *c.begin (), val2= c.front ();
    //     //val3和val4是c中最后一个元素值的拷贝
    //     auto last =c.end () ;
    //     auto val3 = *(--last); //不能递减forward_list迭代器
    //     auto val4 =c.back(); // forward_list不支持

    //     cout << val << " " << val2 << endl;
    //     cout << val3 << " " << val4 << endl;
    // }

    // if(!c.empty())
    // {
    //     c.front() = "xyz";
    //     auto v = c.back();
    //     v = "C";
    //     auto &V = c.back();
    //     V = "B";
    // }

    // vector<string> svec;
    // //空vector
    // //cout << svec[0];
    // //运行时错误:svec中没有元素!
    // cout << svec.at (0);
    // //抛出一个out_of_range异常

    // vector<string> c;
    // auto &v1 = c.at(0);
    // auto v2 = c.at(0);
    // v2 = "xyz";
    // cout << c[0] << endl;
    // cout << *c.begin() << endl;
    // cout <<  c.front() << endl;

    // int a[] = {0,1,78,99,79879};
    // vector<int> vi(a,end(a));

    // for(auto iter=vi.begin();iter!=vi.end();++iter)
    // {
    //     if(*iter%2==0)
    //         vi.erase(iter);

    // }

    // for(auto p:vi) cout << p << " ";

    // forward_list<int> fli={1,2,3,4,5};

    // auto pre = fli.before_begin();
    // auto curr = fli.begin();

    // for(;curr!=fli.end();)
    // {
    //     if(*curr%2==0)
    //     {
    //         pre = curr;
    //         ++curr;
    //     }

    //     else
    //         curr = fli.erase_after(pre);
    // }

    // for(auto p:fli) cout << p << " ";

    // forward_list<string> fls{"pfh","i","cpp","!"};
    // string s1 = "i";
    // string s2 = "love";
    // insert_string(fls,s1,s2);
    // // find_and_insert(fls,s1,s2);
    // for(auto p:fls) cout << p << " ";

    // //傻瓜循环，删除偶数元素，复制每个奇数元素
    // vector<int> vi = {0,1,2,3,4,5,6, 7,8,9};
    // auto iter = vi.begin(); // 调用begin而不是cbegin，因为我们要改变vi
    // while (iter != vi.end()) 
    // {
    //     if (*iter % 2) 
    //     {
    //         iter =  vi.insert(iter, *iter); //复制当前元素
    //         iter += 2; //向前移动迭代器，跳过当前元素以及插入到它之前的元素
    //         } 
    //     else
    //         iter = vi.erase (iter) ;//删除偶数元素
    // }
    // //不应向前移动迭代器，iter指向我们删除的元素之后的元素
    // for(auto p:vi) cout << p << " ";


    //傻瓜循环，删除偶数元素，复制每个奇数元素
    // forward_list<int> vi = {0,1,2,3,4,5,6,7,8,9};
    // auto pre = vi.before_begin();
    // auto iter = vi.begin(); // 调用begin而不是cbegin，因为我们要改变vi
    // while (iter != vi.end()) 
    // {
    //     if (*iter % 2) 
    //     {
    //         iter = vi.insert_after(pre, 999); //复制当前元素
    //         //向前移动迭代器，跳过当前元素以及插入到它之前的元素
    //         advance(iter,2);
    //         advance(pre,2);
    //         } 
    //     else
    //     {
    //         iter = vi.erase_after (pre) ;//删除偶数元素
            
    //     }
            
    // }
    // //不应向前移动迭代器，iter指向我们删除的元素之后的元素

    // for(auto p:vi) cout << p << " ";

    vector<int> vi = {0,1,2,3,4,5,6, 7,8,9};
    auto iter = vi.begin(); 
    while (iter != vi.end())    
    {
        if (*iter % 2) 
        {
            iter = vi.insert(iter, *iter);    
            iter += 2; 
        }
        else
            ++iter;       
        
    }
        
    for(auto p:vi) cout << p << " ";
    
    return 0;
}
