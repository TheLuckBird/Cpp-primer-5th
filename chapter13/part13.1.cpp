#include "Foo.h"

using namespace std;


int main(int argc, char const *argv[])
{
    Foo f1(1,"cpp");
    f1.print();
    Foo f2 = f1;
    f2.print();
    Foo f3(f1);
    return 0;
}
