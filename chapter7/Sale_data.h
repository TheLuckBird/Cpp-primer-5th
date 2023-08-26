#ifndef SALE_DATA_H
#define SALE_DATA_H

#include <string>
using std::string;
#include <vector>
using std::vector;

class Sale_data
{
public:    
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    constexpr static double rate = 0.5;
    static const int vecSize = 20;
    static vector<double> vec;

    // Sale_data() = default;
    Sale_data(const string &s, unsigned n, double p): bookNo(s),units_sold(n),revenue(p) 
    {
        cout << "constructor initialize bookno" << endl;
        cout << bookNo << ' ' << units_sold << ' ' << revenue << ' ' <<  rate << endl;
    }

    Sale_data():Sale_data("",0,0.0f)
    {
        cout << "Sale_data()" << endl;
    }

    Sale_data(const string &s):Sale_data(s,0,0.0f)
    {
        cout << "Sale_data(string &s)" << endl;
    }

    string isbn() const
    {
        return bookNo;  
    }

    Sale_data combine(const Sale_data &rhs);

private:
    static Sale_data mem0;
    Sale_data *mem1;
    // Sale_data mem2;
};

Sale_data Sale_data::combine(const Sale_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

constexpr double Sale_data::rate;
// vector<double> Sale_data::vec = {4,5,6}; 
vector<double> Sale_data::vec(Sale_data::vecSize) ;
#endif