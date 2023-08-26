#include <iostream>
using namespace std;
int main()
{
    int i = 0, sum = 0;
    
    while (i < 10)
    {
        sum += i;
        ++i;
    }

    cout << "the sum of ten : " << sum << endl;
    
    return 0;
}