#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include <utility>

using namespace std;



void add_family(map<string,vector<string>> &families,string family)
{
    if(families.find(family)==families.end())
        families[family] = vector<string>();
}

auto add_child(map<string,vector<string>> &families,string family,string child)
{
    
    families[family].push_back(child);
}

auto add_child(map<string,vector<pair<string,int>>> &families,string family,string child,int age)
{
    families[family].push_back({child,age});
}

void add_word(vector<string> &svec,string word)
{
    if(find(svec.begin(),svec.end(),word) == svec.end())
        svec.push_back(word);
    else
        cout << "已有。" << endl;
}

void word_line(string file)
{
    map<string,list<int>> word_lineno;
    ifstream in(file);
    string line;
    int lineno = 0;
    string word;
    while (getline(in,line))
    {
        lineno++;
        cout << lineno << endl;
        cout << line << endl;
        istringstream in_s(line);
        
        while (in_s >> word)
        {
            word_lineno[word].push_back(lineno);
        }
        
        ++lineno;
    }
    
    for(auto p:word_lineno) 
    {
        cout <<  p.first << " ";
        for(auto v:p.second)
            cout << v << " ";
        cout << endl;
    }


}

pair<string,int> process(vector<string> &v)
{
    if(!v.empty())
        //新标准下，可以对返回值进行列表初始化
        return {v.back(),v.back().size()};
        //旧版本，必须显示构造返回值
        //return pair<string,int>(v.back(),v.back().size());
        //也可以使用make_pair
        //return (v.back(),v.back().size());
    else
        return pair<string,int> ();
}

void vp()
{
    vector<pair<string,int>> vpsi;
    string s;
    int v;
    while (cin>>s&&cin>>v)
    {
        vpsi.push_back(pair<string,int>(s,v));
        vpsi.push_back({s,v});
        vpsi.push_back(make_pair(s,v));
    }

    for_each(vpsi.cbegin(),vpsi.cend(),[](pair<string,int> p){cout <<p.first << " " << p.second << endl; });
    
}

// void word_counter()
// {
//     map<string,int> word_count;
//     string word;
//     while (cin >> word)
//     {
//         // auto it = word_count.insert({word,1});
//         pair<map<string,int>::iterator,bool> it = word_count.insert({word,1});
//         if(!it.second)
//         {
//             // ++it.first->second;
//             ++word_count[word];
//         }    
            
//     }
    
//     for(auto p:word_count)
//         cout << p.first << " " << p.second << endl;
// }

int main(int argc, char const *argv[])
{
    // map<string,size_t> word_count;
    // string word; 
    // while(cin >> word)
    //     ++word_count[word];
    // for(auto p:word_count)
    //     cout << p.first << ":" << p.second << endl;

    // set<string> exclude = {"The", "But", "And", "Or", "An", "A", 
	//                        "the", "but", "and", "or", "an", "a"}; 
    // while (cin >> word)
    // {
    //     if(exclude.find(word)==exclude.end())
    //         ++word_count[word];
    // }
    
    // for(auto p:word_count)
    //     cout << p.first << ":" << p.second << endl;
    

    // map<string,string> info = {{"p","fh"},{"language","cpp"}};
    // vector<int> ivec{1,2,3};
    // // for_each(info.cbegin(),info.cend(),[](map m){cout << m.first << ":" << m.second << endl;})
    // for_each(ivec.cbegin(),ivec.cend(),[](int i){cout << i << " ";});
    // cout << endl;
    // for(auto p:info) cout << "name:" << p.first << "-" << p.second << endl;

    // std::multiset<int> mySet;

    // // 向 multiset 中插入元素
    // mySet.insert(5);
    // mySet.insert(2);
    // mySet.insert(8);
    // mySet.insert(2); // 允许存储重复的元素

    // // 使用迭代器遍历 multiset 并输出元素
    // for (const int& num : mySet) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    // // 查找元素
    // int key = 5;
    // auto it = mySet.find(key);
    // if (it != mySet.end()) {
    //     std::cout << "Found " << key << " in multiset." << std::endl;
    // } else {
    //     std::cout << key << " not found in multiset." << std::endl;
    // }

    // // 删除元素
    // mySet.erase(2); // 删除所有值为 2 的元素

    // // 再次遍历 multiset
    // for (const int& num : mySet) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    // std::multimap<std::string, int> studentScores;

    // // 向 multimap 中插入键值对
    // studentScores.insert({"Alice", 95});
    // studentScores.insert({"Bob", 87});
    // studentScores.insert({"Alice", 92}); // 允许存储多个相同的键

    // // 使用迭代器遍历 multimap 并输出键值对
    // for (const auto& pair : studentScores) {
    //     std::cout << pair.first << ": " << pair.second << std::endl;
    // }

    // map<string,vector<string>> familys;
    // add_family(familys,"彭");
    // for(auto p:familys) 
    // {
    //     cout <<  p.first << " ";
    //     for(auto v:p.second)
    //         cout << v ;
    //     cout << endl;
    // }
        
    // add_child(familys,"彭","X");
    // for(auto p:familys) 
    // {
    //     cout <<  p.first << " ";
    //     for(auto v:p.second)
    //         cout << v ;
    //     cout << endl;
    // }

    // add_child(familys,"王","Z");
    // for(auto p:familys) 
    // {
    //     cout <<  p.first << " ";
    //     for(auto v:p.second)
    //         cout << v ;
    //     cout << endl;
    // }

    // vector<string> language{"C","C++","Java","Python"};
    // add_word(language,"C++");
    // add_word(language,"B");
    // for_each(language.begin(),language.end(),[](string word){cout << word << " ";});

    // word_line(string("word.txt"));
    
    // string line;
    // ifstream in("word.txt");
    // while(getline(in,line))
    // {
    //     cout << line << endl;
    // }
    
    // map<list<int>::iterator,int> m1;
    // map<vector<int>::iterator,int> m2;
    // std::vector<int> vi;
    // m2.insert(std::pair<std::vector<int>::iterator, int>(vi.begin(), 0));

    // but when using this one the compiler complained that
    // error: no match for 'operator<' in '__x < __y'
    // std::list<int> li;
    // m1.insert(std::pair<std::list<int>::iterator, int>(li.begin(), 0));

    // pair<string,int> psi;
    // cout << psi.first << "-" << psi.second << endl;
    // pair<string,string> pss{"cpp","primer"};
    // cout << pss.first << "-" << pss.second << endl; 
    // map<string,int> mii = {{"sd",2}};
    // for(auto p:mii)
    //     cout << p.first << "-" << p.second << endl;

    // vp();

    // map<string,vector<pair<string,int>>> families;
    // add_child(families,string("彭"),string("X"),24);
    // for(auto p:families)
    // {
    //     for(auto v:p.second)
    //         cout << p.first << " " << v.first << " " << v.second << endl;
    // }

    // set<int>::key_type x;
    // set<string>::key_type y;
    // cout << x << endl;
    // cout << y << endl;
    // map<string,int> info{{"p",12}};
    // auto map_it = info.begin();
    // cout << map_it->first << " " << (*map_it).second << endl;
    // map_it->second = 24;
    // cout << map_it->first << " " << map_it->second << endl;
    
    // for(auto p:exclude)
    //     cout << p << " ";
    // cout << endl;

    // for(auto p=exclude.cbegin();p!=exclude.cend();++p)
    //     cout  << *p <<" ";
    // cout << endl;
    // map<string,int> my_language{{"c",0},{"java",1},{"python",2},{"c++",3}};
    // for(auto p:my_language)
    // 	cout << p.first << " " << p.second << " ";
    // cout << endl;
    // for(auto p=my_language.cbegin();p!=my_language.cend();++p)
    // {
    //     cout << (*p).first << " " << (*p).second << " ";
        
    //     cout << p->first << " " << p->second << " ";
    // }    

    // word_counter();

    // map<string,int> m;
    // m["cpp"];
    // cout << m["cpp"] << endl;
    // m["cpp"]=1;
    // cout << m["cpp"] << endl;
    
    multimap<string,string> authors;
    authors.insert({"Alain de Botton", "On Love"});
    authors.insert({"Alain de Botton", "Status Anxiety"});
    authors.insert({"Alain de Botton", "Art of Travel"});
    authors.insert({"Alain de Botton", "Architecture of Happiness"});
    authors.insert({"pfh","cpp"});

    string author;
    cin >> author;
    authors.find(author);
    return 0;
}
