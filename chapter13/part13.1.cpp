#include <vector>
#include "Foo.h"
#include "Numbered.h"
#include "Employee.h"

using namespace std;

void f1(Foo f){}
void f2(Foo &f){}

int main(int argc, char const *argv[])
{
    // Foo f1(1,"cpp");
    // f1.print();
    // Foo f2 = f1;
    // f2.print();
    // Foo f3(f1);
    // Foo fx;
    // f1(f);
    // f2(f);
    
    // Foo *fp = new Foo(1,"cpp");
    // delete fp;

    // vector<Foo> vf;
    // vf.push_back(fx);

    
    // Numbered a,b=a,c=b;
    // f(a);f(b);f(c);

    Employee a("cpp"),b("java"),c("C");
    a.print();
    b.print();
    c.print();

    Employee d(a);
    d.print();

    Employee e = b;
    e.print();

    return 0;
}
