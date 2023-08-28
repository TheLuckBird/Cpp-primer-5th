#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> ivec{1,2,3,1,2,1,1,2,4,56};
    list<string> sl{"aa","aa","aa","cpp"};
    int number = 1 ;
    int c = count(ivec.begin(),ivec.end(),number);
    cout << count(sl.cbegin(),sl.cend(),"aa") << endl;
    std::list<std::string> l = { "aa", "aaa", "aa", "cc" };
    std::cout << "ex 10.02: " << std::count(l.cbegin(), l.cend(), "aa") << std::endl;
    cout << c << endl;
    return 0;
}
