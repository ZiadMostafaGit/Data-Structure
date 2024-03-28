#include <iostream>
#include <string>
#include <algorithm>
#include "stack.h"
using namespace std;

template <typename T>
stack<T>::stack(int sz)
{
    arr = new T[sz];
    top = -1;
    size = sz;
}

template <typename T>
bool stack<T>::is_full()
{
    return size == top + 1;
}

template <typename T>
bool stack<T>::is_empty()
{
    return top == -1;
}

template <typename T>
void stack<T>::push(T val)
{
    if (is_full())
    {
        resize();
    }
    top++;
    arr[top] = val;
}
template <typename T>

int stack<T>::get_top()
{
    return top;
}

template <typename T>
void stack<T>::resize()
{
    T *new_arr = new T[size * 2];
    for (int i = 0; i < size; i++)
        new_arr[i] = arr[i];
    delete[] arr;
    size = size * 2;
    arr = new_arr;
}

template <typename T>
void stack<T>::pop()
{
    if (is_empty())
    {
        cout << "the stack is empty...!\n";
        return;
    }
    top--;
}

template <typename T>
int stack<T>::pick()
{
    if (is_empty())
    {
        cout << "the stack is empty...!\n";
        return 0;
    }
    return arr[top];
}

template <typename T>
void stack<T>::print()
{
    if (is_empty())
    {
        cout << "there are no elements to print..!\n";
        return;
    }
    for (int i = top; i >= 0; i--)
        cout << arr[i] << " ";

    cout << endl;
}
template <typename T>

void stack<T>::deletestack()
{
    top = -1;
}
template <typename T>

void stack<T>::reverse()
{
    int j = 0;
    int i = top;
    while (i >= j)
    {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        j++;
        i--;
    }
}

template <typename T>

bool stack<T>::Valid_Parentheses(string s)
{
    int sz = s.length();
    int t = 0;
    for (int i = 1; i < sz; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push(s[i]);
            t++;
        }
        else if (s[i] == ')' && s[t] == '(')
        {
            pop();
        }
        else if (s[i] == '{' && s[t] == '}')
        {
            pop();
        }
        else if (s[i] == ']' && s[t] == '[')
        {
            pop();
        }
    }
    if (is_empty())
        return true;
    else
        return false;
}

template <typename T>
string stack<T>::RemoveAllAdjacentDuplicatesInString(string s)
{
    int sz = s.length();

    for (int i = 0; i < sz; i++)
    {
        if (is_empty())
        {
            push(s[i]);
            continue;
        }
        if (s[i] == arr[top])
        {
            pop();
        }
        else
        {
            push(s[i]);
        }
    }
    string newstring(top + 1, '\0');
    for (int i = 0; i <= top; i++)
    {
        newstring[i] = arr[i];
    }
    return newstring;
}

//{-1, 3, 2, -5, 4};

template <typename T>
void stack<T>::Asteroid_Collision(int *array, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        if (array[i] < 0)
        {

            if (is_empty())
                push(array[i]);

            else
            {
                bool tregar = true;

                while (top >= 0)
                {
                    if (arr[top] > 0)
                    {
                        if (abs(array[i]) > arr[top])
                        {
                            pop();
                        }
                        else if (abs(array[i]) == arr[top])
                        {
                            pop();
                            tregar = false;
                            break;
                        }
                        else if (abs(array[i]) < arr[top])
                        {

                            tregar = false;
                            break;
                        }
                    }
                    else
                    {
                        push(array[i]);
                        tregar = false;
                        break;
                    }
                }
                if (tregar)
                    push(array[i]);
            }
        }

        else if (array[i] > 0)
        {

            push(array[i]);
        }
    }
}

template <typename T>
void stack<T>::printfront()
{
    for (int i = 0; i <= top; i++)
        cout << arr[i] << " ";
    cout << endl;
}
template <typename T>

void stack<T>::insert_at_bottom(int val, int pos)
{

    if (pos == -1)
    {
        arr[0] = val;
        top++;
        return;
    }
    arr[pos + 1] = arr[pos];

    return insert_at_bottom(val, pos - 1);
}

template <typename T>

int stack<T>::Score_of_Parentheses(string s)
{
    // counter=1
    // counter2=3
    int sz = s.length();
    int counter = 0;
    int counter2 = 0;
    for (int i = 0; i < sz; i++)
    {
        if (s[i] == '(' && s[i + 1] == ')')
        {
            counter++;
            i++;
        }

        if (s[i] == '(' && s[i + 1] == '(')
        {

            while (s[i] != ')' && s[i + 1] != ')')
            {
                counter2++;
                i += 2;
            }
            break;
        }
    }

    int res = (counter2 * 2) + counter;
    return res;
}

/*
template <typename T>

void stack<T>::insert_at_bottom2(int val, int pos, int end)
{

    if (pos == end)
    {
        arr[end] = val;
        return;
    }
    arr[pos] = arr[pos - 1];
    return insert_at_bottom2(val, pos - 1, end);
}
template <typename T>

void stack<T>::reverse_stack(int end)
{

    insert_at_bottom2(end + 1);
}
*/
