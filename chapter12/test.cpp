#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    string file = "storyDataFile";
    TextQuery q1(file);
    q1.word_query();
    q1.print();
    q1.show(string("guygdfu"));
    

    // map<string,set<int>> word_map;
    // string s = "cpp";
    // word_map[s] = 1;

    // std::map<std::string, std::multiset<int>> word_map;

    // // 添加值到 map 中
    // word_map["apple"].insert(1);
    // word_map["apple"].insert(1);
    // word_map["apple"].insert(1);
    // word_map["apple"].insert(2);
    // word_map["banana"].insert(3);
    
    // // 遍历 map
    // for (const auto& entry : word_map) {
    //     std::cout << entry.first << ": ";
    //     for (const auto& number : entry.second) {
    //         std::cout << number << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}
