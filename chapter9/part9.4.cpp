#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> vs;
    
    cout << vs.size() << endl;
    cout << vs.capacity() << endl;
    
    for(int id=0;id<5;++id)
        vs.push_back("id");
    
    cout << vs.size() << endl;
    cout << vs.capacity() << endl;

    vs.reserve(10);
    cout << vs.size() << endl;
    cout << vs.capacity() << endl;

    while(vs.size()!=vs.capacity())
        vs.push_back("0");
    
    cout << vs.size() << endl;
    cout << vs.capacity() << endl;

    for(auto p:vs)
        cout << p << " " ;

    return 0;
}
