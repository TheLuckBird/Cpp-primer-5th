// static
# include <string>
#include <iostream>
using namespace std;

class A{
private:
    static string type;
    int age;
public:
    void gettype(){cout << type <<endl;}
    void settype(string s){type = s;}
};

string A::type = "human";

int main(int argc, char const *argv[])
{
    A a;
    A b;

    a.gettype();
    b.gettype();

    a.settype("dog");
    b.gettype();

    return 0;
}
