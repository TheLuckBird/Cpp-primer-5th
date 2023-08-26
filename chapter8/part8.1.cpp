#include <iostream>
#include <limits> 
using namespace std;

istream & foo(istream & is)
{
    string buf;
    while(is >> buf)
        cout << buf << endl;
    is.clear();
    return is;
}

void stream_state(istream &is)
{
    if(is.bad())
        cout << "cin bad!" << endl;
    if(is.fail())
        cout << "cin fail" << endl;
    if(is.eof())
        cout << "cin eof" << endl;
    if(is.good())
        cout << "cin good" << endl;
}

void sum(istream &is)
{
    int n;
    int sum = 0;
    while(is >> n,!is.eof())
    {
        if(is.bad())
            throw runtime_error("io bad");
        else if (is.fail())
        {
            cerr << "wrong input!again!" << endl;
            is.clear();
            is.ignore(100,'\n');
            continue;
        }
        else
            sum += n;
        cout << "sum:" << sum << endl;
        
    }
}


int main() {
    
    // istream &is = foo(cin);
    // cout << is.rdstate() << endl;
    // cout << is.good();

    // stream_state(cin);
    // cout << "set stream bad" << endl;
    // cin.setstate(istream::badbit);
    // stream_state(cin);
    // cout << "clear stream" << endl;
    // cin.clear();
    // stream_state(cin);
    // cout << "set stream" << endl;
    // cin.setstate(istream::badbit | istream::failbit | istream::eofbit);
    // stream_state(cin);
    // cin.clear();
    // stream_state(cin);

    // istream::iostate old_state = cin.rdstate();
    // cin.setstate(old_state);

    // sum(cin);

    // cin.setstate(istream::badbit);
    // cout << cin.failbit << endl;
    // cout << cin.badbit << endl;
    // cout << cin.goodbit << endl;
    // cout << cin.eofbit << endl;
    // cout << cin.rdstate() << endl;
    cout << cout.tie() << endl;
    cout << cin.tie() << ends;
    return 0;
}
