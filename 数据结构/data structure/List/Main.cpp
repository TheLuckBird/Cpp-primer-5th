#include "Sequence_list.h"
#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    // cout << "hi" << endl;
    Sequence_list<int> array(4);
    array.init();
    array.show();
    return 0;
}
