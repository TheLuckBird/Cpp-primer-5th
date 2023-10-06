#include <iostream>
#include "Quote.h"
using namespace std;


int main(int argc, char const *argv[])
{
    // string s;
    // double price;
    // cout << "请输入书名，价格：" << endl;
    // cin >> s >> price;
    // size_t n;
    // cout << "请输入售卖数量：" << endl;
    // cin >> n;
    // Quote a(s,price);
    // Bulk_quote b(s,price,10,0.5);
    // // Bulk_quote b(a);
    // Quote c(b);

    // // cout << a.isbn() << n << "本书利润：" << a.net_price(n) ;
    // print(cout,a,n);
    // print(cout,b,40);

    // Quote a("cpp primer",10);
    // Bulk_quote b("data structure",20,10,0.5);
    // Quote c(b);
    // cout << c.isbn() << endl;
    // Bulk_quote d(b);
    // cout << d.isbn() << endl;

    Quote a("cpp primer",10);
    Bulk_quote b("data structure",20,10,0.5);
    // a.debug();
    // b.debug();

    Quote &x = b;
    x.debug();
    Quote *y = &b;
    y->debug();

    // b.discount_policy();
    // y->discount_policy();
    

    // Disc_quote d;//error: cannot declare variable 'd' to be of abstract type 'Disc_quote' Disc_quote d;

    return 0;
}
