#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

istream & foo(istream & is)
{
    string buf;
    while(is >> buf)
        cout << buf << endl;
    is.clear();
    return is;
}

void read_info(string filename,vector<string> &vs)
{
    fstream fs(filename);
    if(!fs)
        cerr << "no data" << endl;
        
    string buf;

    while (getline(fs,buf))
    {
        vs.push_back(buf);
    }
}

bool valid(const string& str)
{
    return isdigit(str[0]);
}

string format(const string& str)
{
    return str.substr(0,3) + "-" + str.substr(3,3) + "-" + str.substr(6);
}

int main(int argc, char const *argv[])
{
    
    // foo(iss);

    vector<string> vs;
    string filename{"people_number.txt"};

    read_info(filename,vs);
    // istringstream iss;

    // for(auto p:vs)
    // {
    //     // istringstream iss(p);
    //     iss.clear();
    //     iss.str(p);
    //     string buf;
    //     while(iss >> buf)
    //         cout << buf << endl;

    // }
    ostringstream oss;
    for(auto p:vs)
    {
        
        oss << p << ",";    
    }
    cout << oss.str();

    return 0;
}
