#include <iostream>
using namespace std;

//统计输入中每个值连续出现的次数
int main()
{
    int current_v=0,next_v=0;
    if(cin >> current_v)
    {
        int v_times = 1;
        while (cin >> next_v)
        {
            if(next_v == current_v)
                ++v_times;
            else
            {
                cout << current_v << "出现" << v_times << "次" << endl;
                current_v = next_v;
                v_times = 1;
            }
        }
        cout << current_v << "出现" << v_times << "次" << endl;
        
    }
    return 0;
}