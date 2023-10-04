#include <iostream>
#include "Quote.h"
using namespace std;


int main(int argc, char const *argv[])
{
    string s;
    double price;
    cout << "请输入书名，价格：" << endl;
    cin >> s >> price;
    size_t n;
    cout << "请输入售卖数量：" << endl;
    cin >> n;
    const Quote a(s,price);
    Bulk_quote b(s,price,10,0.5);

    // cout << a.isbn() << n << "本书利润：" << a.net_price(n) ;
    print(cout,a,n);
    print(cout,b,40);
    
    return 0;
}
