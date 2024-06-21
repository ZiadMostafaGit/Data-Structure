#include <iostream>
#include "doubly_linked_list.h"
using namespace std;

dnode::dnode(int val)
{

    data = val;
    next = prev = nullptr;
}

doubl_list::doubl_list()
{

    head = tail = nullptr;
    lenght = 0;
}

void doubl_list::link(dnode *first, dnode *second)
{

    if (first)
        first->next = second;
    if (second)
        second->prev = first;
}
void doubl_list::insert_tail(int val)
{

    dnode *new_node = new dnode(val);

    if (!tail)
    {
        head = tail = new_node;
        lenght++;
    }
    else
    {
        link(tail, new_node);
        tail = new_node;
        lenght++;
    }
}

void doubl_list::insert_head(int val)
{

    dnode *new_node = new dnode(val);
    if (!head)
    {
        head = tail = new_node;

        lenght++;
    }
    else
    {
        link(new_node, head);
        head = new_node;
        lenght++;
    }
}

void doubl_list::insert_sorte(int val)
{
    // 1 2 5 22

    if (lenght == 0 || val < head->data)
        insert_head(val);

    else if (tail->data <= val)
        insert_tail(val);

    else if (val > head->data && val < tail->data)
    {

        dnode *prev = head;
        for (dnode *cur = head; cur; cur = cur->next)
        {
            if (val <= cur->data)
            {
                dnode *new_node = new dnode(val);
                prev->next = new_node;
                link(new_node, cur);
                new_node->prev = prev;
                lenght++;
                return;
            }
            prev = cur;
        }
    }
}

void doubl_list::printfornt()
{

    dnode *cur = head;
    while (cur)
    {

        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
    delete cur;
}

void doubl_list::printback()
{

    dnode *cur = tail;
    while (cur)
    {

        cout << cur->data << " ";
        cur = cur->prev;
    }
    cout << endl;
    delete cur;
}

void doubl_list::delete_head()
{

    if (head)
    {

        dnode *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
    else
    {
        cout << "the list is embty..!\n";
    }
}

void doubl_list::delete_tail()
{
    if (tail)
    {

        dnode *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    else
    {
        cout << "the list is embty..!\n";
    }
}

void doubl_list::delete_node(dnode *cur)
{

    link(cur->prev, cur->next);

    delete cur;
    return;
}

dnode *doubl_list::move(int val)
{
    val--;
    dnode *cur = head;
    while (val--)
        cur = cur->next;
    return cur;
}

void doubl_list::delete_node_with_key(int val)
{

    if (head->data == val)
        delete_head();
    else if (tail->data == val)
        delete_tail();
    else
    {

        for (dnode *cur = head; cur; cur = cur->next)
        {

            if (cur->data == val)
            {
                delete_node(cur);
                return;
            }
        }
        cout << "this val " << val << " is not in the list" << endl;
    }
}
//hello
