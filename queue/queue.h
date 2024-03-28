#include <iostream>
using namespace std;

class queue
{

private:
    int *arr;
    int size;
    int added_elemint;
    int front;
    int rear;

public:
    queue(int val);
    int next(int pos);
    bool is_empty();
    bool is_full();
    void enqueue(int val);
    int dequeue();
};
