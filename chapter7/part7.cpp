#include <string>
using std::string;
#include <iostream> 
using std::endl; using std::cin; using std::cout;
#include <vector>
using std::vector;
#include "Sale_data.h"
#include "person.h"
#include "Screen.h"
#include "Window_mgr.h"

int main(int argc, char const *argv[])
{
    // Sale_data total;
    // if(cin >> total.bookNo >>total.units_sold >>total.revenue)
    // {
    //     Sale_data trans;
    //     while(cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
    //     {
    //         if(total.bookNo == trans.bookNo)
    //         {
    //             total.units_sold += trans.units_sold;
    //             total.revenue +=trans.revenue;
    //         }
    //     }
    // }
    // else
    //     cout << "no data?" << endl;
    
    // cout << total.bookNo << '\t' << total.units_sold << '\t' << total.revenue;

    // person p;
    // cin >> p.name >> p.address;
    // cout << p.get_name() << endl;
    // string name = p.get_name();
    // cout << p.get_address() << endl;
    // name = "bsd";
    // cout << name << endl;

    // person p,q;
    // read(cin,p);
    // read(cin,q);
    // cout << p.name << endl;
    // print(cout,p) << endl;
    // print(cout,q) << endl;

    // person q;
    // print(cout,q);
    // person p("bg","vgshui");
    // cout << endl;
    // print(cout,p);
    // cout << endl;
    // person x(cin);
    // print(cout,x);

    // Screen myscreen(5,5,'h');
    // myscreen.display(cout);
    // myscreen.move(4,0).set('#').display(cout);

    // Window_mgr window;
    // window.show(0);
    // window.clear(0);
    // window.show(0);

    // Sale_data item1("",1,1) ;
    // Sale_data item2();
    // string s = "fghj";
    // Sale_data item(s);
    // cout << item1.units_sold << endl;
    // // cout << item2.units_sold << endl;
    // Sale_data item3;
    // cout << item3.revenue << endl;

    // string null_book = "999-9999-999";
    // Sale_data item;
    // item.combine(null_book);
    // Sale_data item; 
    // cout << item.rate << endl;

    // vector<double> vec(Sale_data::vecSize); 
    // Sale_data::vec = {1,2,3};
    // cout << Sale_data::vec[1] <<endl;
    cout << Sale_data::vec[1] <<endl;
    Sale_data::vec = {1,2,3};
    cout << Sale_data::vec[1] <<endl;
    return 0;
}
