#pragma once
#include <vector>
using namespace std;

class QueueArray
{
public:
    QueueArray(size_t max):maxsize(max){theArray.resize(maxsize);}
    void enqueue(int);
    int dequeue();
    bool empty();
private:
    vector<int> theArray;
    size_t front = 0;
    size_t back = 0;
    size_t currentsize = 0;
    size_t maxsize;
};

void QueueArray::enqueue(int val)
{
    if(currentsize < theArray.size())
    {
        theArray[back] = val;
        ++back;
        ++currentsize; 
    }

}

int QueueArray::dequeue()
{
    if(!empty())
    {
        int temp = theArray[front];
        ++front;
        --currentsize;
        return temp;  
    }
    else
        return -1;

}

bool QueueArray::empty()
{
    return currentsize == 0;
}