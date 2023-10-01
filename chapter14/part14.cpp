#include <iostream>
#include <algorithm>
#include <map>
#include <functional>
#include "Sales_data.h"
#include "A.h"
#include "GetInput.h"
#include "Cmp.h"
#include "Strsize.h"
#include "SmallInt.h"

using namespace std;

int add(int i,int j)
{
    return i+j;
}

int main(int argc, char const *argv[])
{
    // string a = "a";
    // string b = "a" + a;
    // cout << b << endl;

    // Sales_data it1("cpp primer",12,2);
    // Sales_data it2("algorithm",23,2);
    
    // cout << it1 + it2 << endl;

    // cout << it1 << endl;
    // print(cout,it1);

    // it1 += it2;
    // cout << it1 << endl;

    // cout << it2 << endl;

    // A a(10);
    // cout << a << endl;

    // A x,y;
    // cin >> x >> y;
    // cout << x << endl;
    // cout << y << endl;
    // A sum = x + y;
    // // A sum;
    // // sum += x;
    // cout << ++sum << endl;

    // cout << (it1==it2? 1:0) << endl;

    // GetInput getInput;

    // std::cout << getInput() << std::endl;

    // Cmp a(1,11);
    // cout << a() << endl;

    // vector<int> ivec { 1,2,4,6,3,2,1,9,68};
    // Cmp c;
    // int v;
    // cin >> v;
    // // for(auto &p:ivec)
    // // {
    // //     if(c(p,v))
    // //         p = 0;
    // // }

    // for_each(ivec.begin(),ivec.end(),[&](int &p){if(c(p,v)) p=0;});

    // for_each(ivec.begin(),ivec.end(),[](int p){cout << p << " ";});

    // replace_if();

    // map<string,int> str_ifo;

    // Strsize a;
    // string s = "cpp";
    // // cout << a(s,3) << endl;

    // while (cin >> s)
    // {
    //     a(s);
    // }
    
    // a.print();

    // plus<int> intAdd;
    // cout << intAdd(1,2) << endl;
    // plus<string> stringAdd;
    // cout << stringAdd("cpp"," primer") << endl;
    // negate<int> intNegate;
    // cout << intNegate(intAdd(2,3)) << endl;

    // // vector<string> svec{"cpp","c","java","python"};
    // // sort(svec.begin(),svec.end(),greater<string>());
    // // for_each(svec.begin(),svec.end(),[](string s){ cout << s << " ";});
    // // cout << endl;

    // string s="cpp",y="primer";
    // vector<string*> spvec{&s,&y};
    // for_each(spvec.begin(),spvec.end(),[](string *s){ cout << s << " ";});
    // cout << endl;
    // // sort(spvec.begin(),spvec.end(),[](string*a,string*b){return a<b;});
    // // sort(spvec.begin(),spvec.end(),less<string*>());
    // sort(spvec.begin(),spvec.end(),greater<string*>());
    // for_each(spvec.begin(),spvec.end(),[](string *s){ cout << s << " ";});
    // cout << endl;

    // using std::placeholders::_1;

    // std::vector<int> ivec { 1, 111, 1111, 11111 };
    // int count = std::count_if (ivec.cbegin(), ivec.cend(), std::bind(std::greater<int>(), _1, 1024));
    // std::cout << count << std::endl;

    // std::vector<std::string> svec { "pooh", "pooh", "pezy", "pooh" };
    // auto found = std::find_if (svec.cbegin(), svec.cend(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
    // std::cout << *found << std::endl;

    // std::transform(ivec.begin(), ivec.end(), ivec.begin(), std::bind(std::multiplies<int>(), _1, 2));
    // for (int i : ivec) std::cout << i << " ";
    // std::cout << std::endl;

    // cout << greater<int>()(3,2) << endl;

    // auto data = { 2, 3, 4, 5 };
    // int input;
    // std::cin >> input;
    // std::modulus<int> mod;
    // auto predicator = [&](int i){ return 0 == mod(input, i); };
    // auto is_divisible = std::any_of(data.begin(), data.end(), predicator);
    // std::cout << (is_divisible ? "Yes!" : "No!") << std::endl;

    // int (*fp)(int,int) = add;//add存在二义性问题，存储函数指针而非函数名字可以解决该问题
    // map<string,function<int(int,int)>> f= {{"+",fp},{"*",[](int i,int j){return i*j;}}};
    // cout << f["+"](1,2) << endl;
    // cout << f["*"](2,2) << endl;

    SmallInt si;
    si = 4;
    cout << si +3 << endl;

    return 0;
}
