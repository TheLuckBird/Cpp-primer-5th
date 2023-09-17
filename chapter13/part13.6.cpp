#include <iostream>
#include <utility>

using namespace std;

int main(int argc, char const *argv[])
{
    int i = 42;
    int& ri = i;
    int&& rri = 42;
    int& r = rri;
    int && rr = std::move(rri);
    cout << rr << endl;


    return 0;
}
