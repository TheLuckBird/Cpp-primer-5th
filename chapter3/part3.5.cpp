#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// const char s1[] = "hi";
// const char s2[] = "cpp";

int main(int argc, char const *argv[])
{
    // const char s[3] = "cp";
    // int *a[10];
    // int *(&ref)[10] = a; 

    // unsigned scores[11] = {};
    // unsigned grade;
    // while(cin >> grade)
    //     ++scores[grade/10];
    // for(auto v:scores)
    //     cout << v <<' ';
    // cout << endl;

    // int a[10];
    // int index = 0;
    // for(auto &v:a)
    //     v = index++;
    // for(auto v:a)
    //     cout << v << ' ';
    // cout << endl;

    // vector<int> a(10);
    // for(decltype(a.size()) index=0;index<10;++index)
    //     a[index] = index;
    // for(auto index=a.begin();index!=a.end();++index)
    //     cout << *index << ' ';
    // cout << endl;
    // vector<int> b(a);//初始化另一个vector
    // for(auto index=b.begin();index!=b.end();++index)
    //     cout << *index << ' ';
    // cout << endl;
    
    // int a[] = {0,1,2,4,5};
    // auto p = a;
    // auto p1 = &a[3];
    // cout << p << endl;
    // cout << *p << endl;
    // cout << p1 << endl;
    // cout << *p1 << endl;
    // auto e = &a[3];
    // for(auto p=a;p!=e;++p)
    //     cout << *p << ' ';
    // cout << endl;
    // for(auto p=begin(a),q=end(a);p!=q;++p)
    //     cout << *p << ' ';
    // cout << endl;
    // for(auto p=begin(a),q=end(a);p!=q;++p)
    //     *p = 0;
    // for(auto p=begin(a),q=end(a);p!=q;++p)
    //     cout << *p << ' ';
    // cout << endl;

    // int a[] = {0,1,2,4,5};
    // int b[] = {0,1,6,4,5};

    // for(auto a_p=begin(a),b_p=begin(b),a_q=end(a),b_q=end(b);a_p!=a_q&&b_p!=b_q;++a_p,++b_p)
    //     if(*a_p == *b_p)
    //         cout << "a equal b" << endl;
    //     else
    //         cout << "a not equal b" << endl;

    // vector<int> v1{0,1,2,4,5};
    // vector<int> v2{0,0,2,4,5};

    // if(v1==v2)
    //     cout << "v1 equal v2";
    // else
    //     cout << "v1 not equal v2";

    // string s1{"hi"};
    // string s2{"cpp"};
    
    // if(s1 == s2)
    //     cout << "s1=s2" << endl;
    // else if(s1 < s2)
    //     cout << "s1<s2" << endl;
    // else
    //     cout << "s1>s2" << endl;

    // if(strcmp(s1,s2) == 0)
    //     cout << "s1=s2" << endl;
    // else if(strcmp(s1,s2) > 0)
    //     cout << "s1>s2" << endl;
    // else
    //     cout << "s1<s2" << endl;

    // constexpr size_t len = strlen(s1)+strlen(s2)+1+strlen(" ");
    // char s3[len];
    // strcpy(s3,s1);
    // strcat(s3," ");
    // strcat(s3,s2);
    // cout << s3 << endl;

    int array[] = {0,1,2,3};
    vector<int> vt(begin(array),end(array));
    for(auto v=vt.begin();v!=vt.end();++v)
        cout << *v << ' ';
    cout << endl;

    return 0;
}
