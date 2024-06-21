#include <iostream>
#include "array.h"
using namespace std;

Vector::Vector()
{
    capacity = 100;
    arr = new int[capacity];
    size = 0;
}

Vector::Vector(int si)
{
    capacity = 100;
    if (si > capacity)
        capacity = si;
    size = 0;
    arr = new int[capacity];
}

Vector::~Vector()
{
    delete[] arr; // Free the memory allocated for the array
}

void Vector::push_back(int value)
{
    if (size == capacity)
        double_capacity();

    arr[size] = value;
    size++;
}

void Vector::double_capacity()
{
    capacity *= 2;
    int *new_arr = new int[capacity];
    for (int i = 0; i < size; i++)
    {
        new_arr[i] = arr[i];
    }
    swap(arr, new_arr);
    delete[] new_arr; // Free the memory of the old array
}
void Vector::right_rotate()
{
    if (size > 0)
    {
        int temp = arr[size - 1];
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }
}

void Vector::left_rotate()
{
    if (size > 0)
    {
        int temp = arr[0];
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = temp;
    }
}
// 1 2 3 4 5
void Vector::right_rotate_steps(int steps)
{
    while (steps--)
    {
        right_rotate();
    }
}

int Vector::pop(int idx)
{
    if (idx >= 0 && idx < size)
    {
        int item = arr[idx];
        for (int i = idx; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        return item;
    }
    return -1;
}

int Vector::improved_search(int idx)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == idx)
        {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            return i;
        }
    }
    return -1;
}

void Vector::print()
{

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}