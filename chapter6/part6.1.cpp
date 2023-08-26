#include <iostream>
using std::endl; using std::cout;

// int add(int num)
// {
//     int sum = 0;
    
//     do{
//         sum += num;
//     }while(num--);

//     return sum;
// }

int a(void)
{
    static int sv = 0;
    return ++sv;
}

int main(int argc, char const *argv[])
{
    // int sum = add(100);
    // cout << "the sum of 100:" << sum <<endl; 
    for(int i=0;i!=10;++i)
        cout << a() << endl;
    return 0;
}
