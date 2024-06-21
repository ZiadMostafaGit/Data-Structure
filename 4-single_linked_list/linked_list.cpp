#include <iostream>
#include "linked_list.h"
#include <assert.h>
using namespace std;

node::node()
{
    data = 0;
    next = nullptr;
}
node::node(int value)
{

    data = value;
    next = nullptr;
}

linked_list::linked_list()
{

    head = nullptr;
    tail = nullptr;
    length = 0;
}
linked_list::~linked_list()
{

    node *temp = head;
    while (temp->next != nullptr)
    {

        node *next = temp->next;
        delete temp;
        temp = next;
    }
    delete temp;
}

void linked_list::insert_back(int value)
{

    node *new_node = new node(value);
    if (tail == nullptr)
    {

        head = tail = new_node;
        length++;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
        length++;
    }
}

void linked_list::insert_front(int value)
{

    node *new_node = new node(value);

    if (tail == nullptr)
    {
        head = tail = new_node;
        length++;
    }
    else
    {

        new_node->next = head;
        head = new_node;
        length++;
    }
}

void linked_list::delete_head()
{

    node *temp = head;
    head = head->next;
    delete temp;
    length--;
}
int linked_list::get_nth_from_front(int value)
{
    if (value > length)
        return -1;
    else if (value == length)
        return tail->data;
    else
    {

        node *temp = head;
        value--;
        for (int i = 0; i < value; i++)
        {
            if (temp->next != NULL)
                temp = temp->next;
            else
                return -1;
        }

        int res = temp->data;
        return res;
    }
}

int linked_list::get_nth_from_back(int value)
{
    value--;
    int id = length - value;
    return get_nth_from_front(id);
}

bool linked_list::is_the_same(linked_list *linked)
{

    if (length != linked->length)
        return false;
    else
    {

        node *temp = head;
        node *temp2 = linked->head;
        for (int i = 0; i < length; i++)
        {
            if (temp->data != temp2->data)
                return false;
            temp = temp->next;
            temp2 = temp2->next;
        }
        return true;
    }
}

void linked_list::print_list()
{

    node *temp = head;
    while (temp->next != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int linked_list::get_length()
{

    return length;
}

int linked_list::delete_with_key(int value)
{

    node *temp = head;
    node *prev = head;
    int idx = 1;
    while (temp->next != NULL)
    {

        if (temp->data == value)
        {
            prev->next = temp->next;
            delete temp;
            length--;
            return idx;
        }
        prev = temp;
        temp = temp->next;
        idx++;
    }

    return -1;
}

void linked_list::swap_pair()
{

    node *cur = head;
    node *prev = cur;
    cur = head->next;
    while (cur->next != nullptr || prev->next != nullptr)
    {

        swap(prev->data, cur->data);
        if (cur->next == nullptr)
            return;

        prev = cur->next;
        cur = prev->next;
    }
}

void linked_list::swap_node(node *node1, node *node2)
{

    node *temp = node1;
    node1 = node2;
    node2 = temp;
    delete temp;
}
void linked_list::reverse_list()
{
    if (!head || !head->next)
    {
        // Empty list or only one node, no need to reverse
        return;
    }

    node *prev = nullptr;
    node *current = head;
    node *next = nullptr;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

void linked_list::insert_in_order(int value)
{

    node *new_node = new node(value);
    node *cur = head;
    node *prev = head;

    if (head == nullptr && tail == nullptr)
        head = tail = new_node;
    else
    {

        if (new_node->data > tail->data)
        {
            tail->next = new_node;
            tail = new_node;
        }
        else if (new_node->data < head->data)
        {
            new_node->next = head;
            head = new_node;
        }
        else if ((new_node->data) > (head->data) && (new_node->data) < (tail->data))
        {

            while (cur->next != nullptr)
            {

                if ((cur->data) > (new_node->data))
                {
                    prev->next = new_node;
                    new_node->next = cur;
                    return;
                }
                else
                {

                    prev = cur;
                    cur = cur->next;
                }
            }
        }
    }
}

void linked_list::delete_next_node(node *n)
{
    // Delete the next of the current node
    // Handle if next is tail case
    assert(n);

    node *temp = n->next;
    bool is_tail = temp == tail;

    // node->next in middle to delete
    // temp->next = temp->next->next;
    n->next = temp->next;
    delete temp;
    length--;

    if (is_tail)
        tail = n;
}

void linked_list::delete_even_positions()
{ // O(n) time - O(1) memory
    if (length <= 1)
        return;
    // maintain previous and delete its next (even order)
    for (node *cur = head->next, *prv = head; cur;)
    {
        delete_next_node(prv); // prev is odd, prev-next is even
        if (!prv->next)        // tail
            break;
        cur = prv->next->next;
        prv = prv->next;
    }
}

void linked_list::swap_head_and_tail()
{

    node *temp = head->next;
    tail->next = temp;

    while (temp->next != tail)
        temp = temp->next;

    temp->next = head;
    head->next = nullptr;
    temp = head;
    head = tail;
    tail = temp;
}

void linked_list::lift_rotate(int value)
{

    if (value < 1)
        cout << "can not rotate less than one time\n";

    else if (value == length)
        return;
    else
    {

        if (value >= length)
            value = value % length;

        node *temp = head;

        for (int i = 0; i < value - 1; i++)
        {
            temp = temp->next;
        }

        tail->next = head;
        head = temp->next;
        tail = temp;
        tail->next = nullptr;
    }
}

void linked_list::delete_tail()
{

    node *temp = head;
    node *temp2 = tail;
    while (temp->next != nullptr)
    {

        temp2 = temp;
        temp = temp->next;
    }
    tail = temp;
    delete temp2;
    length--;
}

void linked_list::delete_node(node *prev, node *cur)

{
    if (prev == NULL) // deleting the head node
    {
        head = cur->next;
        delete cur;
    }
    else // deleting any other node
    {
        prev->next = cur->next;
        delete cur;
    }
}

void linked_list::remove_duplicates()
{

    int arr[length];
    for (int i = 0; i < length; i++)
        arr[i] = 0;
    node *temp = head;
    node *prev = head;
    while (temp->next != nullptr)
    {

        arr[temp->data]++;
        if (arr[temp->data] > 1)
        {
            delete_next_node(prev);

            temp = prev->next;
        }
        else
        {
            if (temp->next == nullptr)
                prev = temp;
            else
            {
                prev = temp;

                temp = temp->next;
            }
        }
    }

    arr[temp->data]++;
    if (arr[temp->data] > 1)

        delete_next_node(prev);
}

void linked_list::remove_last_occurance(int value)
{

    node *cur = head->next;
    node *prev = head;
    while (cur->next != nullptr)
    {

        if (cur->next->data == value)
        {
            prev = cur;
        }
        cur = cur->next;
    }
    delete_next_node(prev);
}
void linked_list::moveToEnd(int key)
{

    node *pKey = head;
    node *pCrawl = head;
    while (pCrawl != NULL)
    {
        if (pCrawl != pKey && pCrawl->data != key)
        {
            pKey->data = pCrawl->data;
            pCrawl->data = key;
            pKey = pKey->next;
        }
        if (pKey->data != key)
            pKey = pKey->next;
        pCrawl = pCrawl->next;
    }
}

int linked_list::max(node *temp)
{
    // Base case: if the list is empty, return a very small number
    if (temp == nullptr)
        return -1;

    // Recursive case: return the maximum between the current data and the max of the rest of the list
    return std::max(temp->data, max(temp->next));
}

node *linked_list::get_head()
{

    return head;
}
void linked_list::arrange_odd_even()
{ // O(n) time - O(1) memory
    if (length <= 1)
        return;
    // maintain previous and delete its next (even order)
    int len = length;
    if (length % 2 != 0)
        len--;
    len /= 2;

    int i = 0;
    cout << len << endl;
    for (node *cur = head->next, *prv = head; i < len; i++)
    {
        insert_back(cur->data);
        delete_next_node(prv); // prev is odd, prev-next is even
        if (!prv->next)        // tail
            break;
        cur = prv->next->next;
        prv = prv->next;
    }
}

// void linked_list::moveToEnd(int key)
// {
//     int len = length;
//     node *cur = head;
//     node *prev = head;
//     while (len)
//     {
//         if (cur->data == key)
//         {
//             insert_back(key);
//             delete_node(prev, cur);
//         }
//         prev = cur;
//         cur = cur->next;
//         len--;
//     }
// }

// void linked_list::insert_alternatig(linked_list *linked2)
// {
//     // node *cur1 = head;
//     // node *prev1 = head;
//     // node *cur2 = linked2->head;
//     // node *prev2 = linked2->head;
//     // while (cur1->next != nullptr && cur2->next != nullptr)
//     // {
//     //     cur1->next = cur2;
//     //     cur2->next = prev1->next;
//     //     cur1 = prev1->next;
//     //     cur2 = prev2->next;
//     //     prev1 = prev1->next;
//     //     prev2 = prev2->next;
//     // }
// }
void linked_list::insert_alternatig(linked_list *linked2)
{
    {
        node *cur1 = head;
        node *prev1 = nullptr;
        node *cur2 = linked2->head;
        node *prev2 = nullptr;

        while (cur1 != nullptr && cur2 != nullptr)
        {
            prev1 = cur1;
            prev2 = cur2;

            cur1 = cur1->next;
            cur2 = cur2->next;

            prev1->next = prev2;
            prev2->next = cur1;
        }

        if (cur1 == nullptr && prev1 != nullptr)
        {
            prev1->next = cur2;
        }
    }
}

// void linked_list::insert_alternatig(linked_list *linked2)
// {
//     node *cur1 = head;
//     node *cur2 = linked2->head;
//     while (cur1 != nullptr && cur2 != nullptr)
//     {
//         node *temp = cur2->next;
//         cur2->next = cur1->next;
//         cur1->next = cur2;
//         cur1 = cur2->next;
//         cur2 = temp;
//     }
//     if (cur1 == nullptr)
//     {
//         cur1 = cur2;
//     }
// }

void linked_list::add_list(linked_list *linked2)
{

    node *cur = head;
    node *cur2 = linked2->head;
    while (cur != nullptr && cur2 != nullptr)
    {

        cur->data = cur->data + cur2->data;
        if (cur->data >= 10)
        {

            if (cur->next != nullptr)
            {
                cur->data -= 10;
                cur->next->data += 1;
            }
            else
            {

                cur->data -= 10;
                cur2->data += 1;
            }
        }

        cur = cur->next;
        cur2 = cur2->next;
    }

    if (cur->next == nullptr)
        cur->next = cur2;
}

// void linked_list::remove_all_repeted()
// {
//     int arr[length];
//     for (int i = 0; i < length; i++)
//         arr[i] = 0;

//     node *cur = head->next;
//     node *prev = head;

//     while (cur != nullptr)
//     {
//         if (prev->data == cur->data)
//         {
//             if (cur->next->next != nullptr)
//             {

//                 while (prev->data == cur->data)
//                 {
//                     node *temp2 = cur;
//                     cur = cur->next;
//                     delete temp2;
//                 }
//                 node *temp = prev;
//                 prev = cur;
//                 delete temp;
//                 cur = prev->next;
//             }
//             else
//             {
//                 node *temp = cur;
//                 cur = cur->next;
//                 delete temp;
//                 delete cur;
//                 cur = nullptr;
//             }
//         }

//         else
//         {

//             prev = cur;
//             cur = cur->next;
//         }
//     }
// }

void linked_list::remove_all_repeted()
{
    node *cur = head->next;
    node *prev = head;

    while (cur != nullptr)
    {
        if (prev->data == cur->data)
        {
            if (cur->next != nullptr && cur->next->next != nullptr)
            {
                while (prev->data == cur->data)
                {
                    node *temp2 = cur;
                    cur = cur->next;
                    delete temp2;
                }
                node *temp = prev;
                prev = cur;
                delete temp;
                cur = prev->next;
            }
            else
            {
                node *temp = cur;
                cur = cur->next;
                delete temp;
                prev->next = cur;
            }
        }

        else
        {
            prev = cur;
            cur = cur->next;
        }
    }

    // // Delete any remaining duplicates at the end of the list
    // if (prev->data == cur->data)
    // {
    //     node *temp = prev;
    //     prev = cur;
    //     delete temp;
    //     delete cur;
    //     prev->next = nullptr;
    // }
}
