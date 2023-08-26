#include <iostream>
using namespace std;

int main()
{
    // int v1,v2;
    // cin >> v1;
    // cout << v1  << endl;
    // cin >> v2;
    // cout << "/*" << endl;
    // cout << "*/" << endl;
    int sum=0,v=0;
    while (cin >> v)
    {
        sum+=v;
    }
    cout << sum;
    cin.get();
    
    return 0;
}