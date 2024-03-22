# include <iostream>
#include <string>
using namespace std;

class weituo
{
private:
    string name;
    int age;
    static const int id = 10;
public:
    static int x;
    weituo(string s,int age):name(s){cout << "1" << endl;}
    weituo():weituo(" ",0){cout << "2"<< endl;}
    weituo(string s):weituo(){cout << "3" << endl;}
    static  void printid(){cout << id << endl;}

};
int weituo::x = 100;

int main(int argc, char const *argv[])
{
    weituo a;
    cout << "------------" << endl;
    weituo b("xyz",24);
    cout << "------------" << endl;
    weituo c("xyz");
    a.printid();
    b.printid();

    cout << weituo::x << endl;
    weituo::printid();
    
    return 0;
}
