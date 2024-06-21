#include <iostream>
#include "queue.h"
using namespace std;

queue::queue(int val)
{
    arr = new int[val];
    rear = front = 0;
    added_elemint = 0;
    size = 0;
}

int queue::next(int pos)
{
    pos++;
    if (pos == size)
    {
        pos = 0;
        return pos;
    }
}

bool queue::is_empty()
{
    return added_elemint == 0;
}
bool queue::is_full()
{
    return added_elemint == size;
}

void queue::enqueue(int val)
{

    if (is_full())
    {
        cout << "queue is full" << endl;
        return;
    }
    arr[rear] = val;
    rear++;
    added_elemint++;
}
int queue::dequeue()
{

    if (is_empty())
    {
        cout << "the queue is empty" << endl;
        return;
    }
    int val = arr[front];
    front = next(front);
    added_elemint--;
    return val;
}