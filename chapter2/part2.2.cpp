#include <iostream>
using namespace std;
int so =42;
int main(int argc, char const *argv[])
{
    cout << so <<endl;
    int so = 24;
    cout << so <<endl;
    cout << :: so << endl;
    string s;//("hi cpp!")
    // cin >> s;
    cout << s << endl;
    // int i = 3.14;
    // int i = {3.14};
    // int i {3};
    int i (0);
    cout << i << endl;

    double b = 99.09;

    extern int e;//声明一个变量而非定义
    int k;//声明并定义

    int a = 100, sum = 0;
    for (int i = 0; i != 10; i++)
    {
        sum += i;
    }
    cout << sum << endl;

    return 0;
}

