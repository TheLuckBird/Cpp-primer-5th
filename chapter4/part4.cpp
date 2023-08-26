#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    // vector<int> vt{0,1,2,3,-1};
    // auto pbeg = vt.begin();
    // while(pbeg!=vt.end() && *pbeg>=0)
    // {
    //     cout << *pbeg++ << ' ';
    // }
    // cout << endl;
    // for(auto p=vt.begin();p!=vt.end() && *p>=0;++p)
    //     cout << *p << ' ';

    // for(auto p=vt.begin();p!=vt.end();++p)
    // {
    //     cout << ((*p)%2?(*p)*2:*p);
    //     cout << ' ';
    // }
    
    // double grade = 99;
    // string finalgrade = (grade>90)?"high pass":grade<60?"fail":grade<75?"low pass":"pass";
    // cout << finalgrade;

    // unsigned long grade = 0;
    // grade |= 1UL << 27;
    // cout << grade;

    // char c = 'q';
    // cout << ~('q'<<6);
    // auto i = sizeof(int);
    // cout << i << endl;
    // size_t d = sizeof(double);
    // cout << d << endl;
    // cout << sizeof(char) << endl;
    // cout << sizeof(long) << endl;
    // cout << sizeof(long long) << endl;
    // cout << sizeof(string) << endl;
    // cout << sizeof(vector<double>) << endl;
    // cout << sizeof(vector<string>) << endl;
    // cout << sizeof(int *) << endl;
    // cout << sizeof(double *) << endl;
    // int i[10],*p=i;
    // cout << (sizeof(i)/sizeof(*i));
    // cout << endl;
    // cout << (sizeof(p)/sizeof(*p));    

    // int n = 1;
    // int m = (++n, std::cout << "n = " << n << '\n', ++n, 2 * n);
    // std::cout << "m = " << (++m, m) << '\n';

    // int somevalue = 0;
    // int x = 0,y = 0;
    // // (somevalue?++x,++y:--x),--y;
    // // cout << somevalue?++x,++y:--x,--y;
    // // cout << endl;
    // somevalue ? (++x,++y):(--x,--y);
    // cout << y << endl;
    // cout << x;

    // double d = 3.14;
    // void *p = &d;
    // auto q = static_cast<double*> (p);
    // cout << *q;
    // char c ='a';
    // const char *p = &c;
    // // auto q = const_cast<char*>(p);
    // // *q = 'b';
    // // cout << *q << endl;
    // // cout << c << endl;
    // // cout << *p << endl;
    // // const_cast<char&>(c) = 'b';
    // *const_cast<char*>(p) = 'b';
    // cout << c << endl;
    
    const char c = 'a';
    const char *pc = &c;
    char *p = const_cast<char*>(pc);
    *p = 'b';
    cout << *pc << endl;
    cout << c;

    return 0;
}
