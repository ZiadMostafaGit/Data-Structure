#include <iostream>
using namespace std;

class dnode
{

public:
    int data;
    dnode *next;
    dnode *prev;

public:
    dnode(int val);
};

class doubl_list
{

private:
    dnode *head;
    dnode *tail;
    int lenght;

public:
    doubl_list();
    void link(dnode *first, dnode *second);
    void insert_tail(int val);
    void insert_head(int val);
    void insert_sorte(int val);
    void printfornt();
    void printback();
    void delete_head();
    void delete_tail();
    void delete_node(dnode *cur);
    dnode *move(int val);

    void delete_node_with_key(int val);
};