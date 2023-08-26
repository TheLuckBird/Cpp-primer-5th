#include <iostream>
#include "Sales_item.h"
using namespace std;

int main(int argc, char const *argv[])
{
    // for (Sales_item item;cin >> item;cout << item << endl);    
    // Sales_item item1,item2;
    // cin >> item1;
    // cin >> item2;
    // cout << item1 + item2 << endl;
    // return 0;
    //练习 1.22
    Sales_item current_item,next_item;
    if(cin >> current_item)//判断输入是否有效，并将第一个输入给current_item
    {
        while (cin >> next_item)//将下一个输入给next_item
        {
            if (current_item.isbn() == next_item.isbn())//isbn()值相同的相加
                current_item += next_item;
            else//不同的打印上一个，继续迭代
            {
                cout << current_item << endl;
                current_item = next_item;
            }
        }
        cout << current_item << endl;
        
    }
    else
    {
        // no input! warn the user
        std::cerr << "No data?!" << std::endl;
        return -1;  // indicate failure
    }
    return 0;
}

