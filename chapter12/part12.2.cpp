#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int *fp = new int[2]{26,4};
    cout << *fp << endl;
    // delete []fp;
    cout << fp[1] << endl;
    cout << *(fp+1) << endl;
    return 0;
}
