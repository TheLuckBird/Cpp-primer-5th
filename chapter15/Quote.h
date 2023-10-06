#pragma once

#include <string>

using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(string bookNo_,double price_):bookNo(bookNo_),price(price_){}
    Quote(const Quote &q):bookNo(q.bookNo),price(q.price){}
    virtual ~Quote() = default;
    
    string isbn() const{return bookNo;}
    virtual double net_price(size_t n) const{return n*price;};
    virtual void debug() const;

private:
    string bookNo;
protected:
    double price=0.0;
};

class Disc_quote:public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string &bookNo_,double price_):Quote(bookNo_,price_){}
    Disc_quote(const string &bookNo_,double price_,size_t quantity_,double discount_)
    :Quote(bookNo_,price_),quantity(quantity_),discount(discount_){}
    double net_price(size_t) const = 0;
    void foo(Quote &q){q = *this;}
    pair<size_t, double> discount_policy() const{ return {quantity, discount}; }

    // using Quote::bookNo;
protected:
    size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote:public Disc_quote
{
public:
    Bulk_quote() = default;
    // Bulk_quote(const string &bookNo_,double price_,size_t n,double disc):Disc_quote(bookNo_,price_),min_qty(n),discount(disc) {}
    // Bulk_quote(const Bulk_quote &b):Disc_quote(b),min_qty(b.min_qty),discount(b.discount){}
    Bulk_quote(const string &bookNo_,double price_,size_t n,double disc):
    Disc_quote(bookNo_,price_,n,disc){}

    double net_price(size_t)const override ;
    void debug() const override;
// private:
//     size_t min_qty = 0;
//     //适用折扣政策的最低购买量
//     double discount = 0.0;
//     //以小数表示的折扣额 
};

double Bulk_quote::net_price(size_t cnt)const
{
    if(cnt >quantity)
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

void Quote::debug() const
{
    cout << "bookNo:" << bookNo << " price:" << price << endl;
}

void Bulk_quote::debug() const
{
    Quote::debug();
    cout << "min_qty:" << quantity <<" discount:" << discount << endl;
}