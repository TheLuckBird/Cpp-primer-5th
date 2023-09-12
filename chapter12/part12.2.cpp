#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    // int *fp = new int[2]{26,4};
    // cout << *fp << endl;
    // // delete []fp;
    // cout << fp[1] << endl;
    // cout << *(fp+1) << endl;

    // unique_ptr<int[]> up(new int[10]());

    // for(int i=0;i!=10;++i)
    //     cout << up[i] << " " ;
    // cout << endl;

    // shared_ptr<int> sp(new int[10]{0,1,2},[](int *p){delete []p;});
    
    // for(int i=0;i!=10;++i)
    //     cout << *(sp.get()+i) << " " ;
    // cout << endl;

    // const string s1("cpp");
    // const string s2("primer");

    // char *cp = new char[100]();
    // const string temp =s1+s2;

    // int size=0;
    // for(auto it=temp.begin();it!=temp.end();++it)
    //     cp[size++] = *it;
    
    // for(int i=0;i!=size;++i)
    //     cout << cp[i] << " " ;
    // cout << endl;
    // cout << cp << endl;

    // delete []cp;

    allocator<string> alloc;
    auto const p = alloc.allocate(10);
    string *q = p;
    string s;

    while(cin >> s&&q!=p+5) alloc.construct(q++,s);
    // while(q!=p) {cout << *(--q) << endl;}
    while(q!=p) alloc.destroy(--q);
    alloc.deallocate(p,10);
    return 0;
}
