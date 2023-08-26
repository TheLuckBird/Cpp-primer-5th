#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[2][3]  = {0,1,2,3,4,5};
    int b[2][2];
    for(auto &p:b)
    {
        for(auto q:p)
            cout << q << ' ';
        cout << endl;
    }
        
    // int (&ref)[3] = a[0];
    // for(auto v:ref)
    //     cout << v <<' ';
    // cout << endl;

    // for(auto &p:a)
    // {
    //     for(auto q:p)
    //         cout << q << ' ';
    //     cout << endl;
    // }
        
	// for(auto p=a;p!=a+2;++p)
    // {
    //     for(auto q = *p;q!=*p+3;++q)
    //         cout << *q << ' ';
    //     cout << endl;
    // }

    // for(auto v=begin(a);v!=end(a);++v)
    // {
    //     for(auto p=begin(*v);p!=end(*v);++p)
    //         cout << *p << ' ';
    //     cout << endl;

    // }

    // for(auto &c1:a)
    // {
    //     for(auto c2:c1)
    //         cout << c2 << ' ';
    //     cout << endl;
    // }


    return 0;


}
