#include <string>
#include <iostream>
using namespace std;

class Sales_data
{
private:
    string id;
public:
    string & isbn()
    {
        return id;
    }

    bool read(istream in,Sales_data a)
    {
        cout << "xx" << endl;
    }

    ostream & print(ostream out,Sales_data b)
    {
        out << b.isbn() << endl;
    }
};

int main(int argc, char const *argv[])
{
    Sales_data total;
    
    
    
    return 0;
}
