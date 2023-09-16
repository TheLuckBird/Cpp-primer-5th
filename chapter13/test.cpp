#include "A.h"


int main(int argc, char const *argv[])
{
    // foo(new string("cpp"));
    // string s = "java";
    // foo(&s);
    // string *ps = &s;
    // foo(ps);

    string a = "cpp";
    string b(a+" primer");
    cout << a << endl;
    cout << b << endl;
    
    return 0;
}
