#include <iostream>
using namespace std;

class Vector
{

private:
    int *arr;
    int size;
    int capacity;

public:
    Vector();
    ~Vector();

    Vector(int si);

    void push_back(int item);
    void double_capacity();
    void right_rotate();
    void left_rotate();
    void right_rotate_steps(int steps);
    int pop(int idx);
    int improved_search(int idx);
    void print();
};