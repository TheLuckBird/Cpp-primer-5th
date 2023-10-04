#pragma once

#include <string>

using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(string bookNo_,double price_):bookNo(bookNo_),price(price_){}
    virtual ~Quote() = default;
    
    string isbn() const{return bookNo;}
    virtual double net_price(size_t n) const{return n*price;};

private:
    string bookNo;
protected:
    double price=0.0;
};

class Bulk_quote:public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(string &bookNo_,double price_,size_t n,double disc):Quote(bookNo_,price_),min_qty(n),discount(disc) {}

    double net_price(size_t)const override ;
private:
    size_t min_qty = 0;
    //适用折扣政策的最低购买量
    double discount = 0.0;
    //以小数表示的折扣额 
};

double Bulk_quote::net_price(size_t cnt)const
{
    if(cnt >min_qty)
        return cnt * (1-discount) * price;
    else
        return cnt * price;
}

double print(ostream &os, const Quote &item,size_t n)
{
    double ret = item.net_price(n);
    cout << item.isbn() << n << "本书利润：" << ret << endl;
    return ret;
}