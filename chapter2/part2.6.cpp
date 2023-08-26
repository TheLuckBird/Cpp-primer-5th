#include <iostream>
#include <string>
using namespace std;

struct Sale_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{   
    double price;
    Sale_data data1,data2;
    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    
    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    if(data1.bookNo == data2.bookNo)
    {
        Sale_data total;
        total.bookNo = data1.bookNo;
        total.units_sold = data1.units_sold + data2.units_sold;
        total.revenue = data1.revenue + data2.revenue;
        cout << total.bookNo << total.units_sold << total.revenue << endl;
    }
    else
        cout << "书名不同";
    return 0;
}