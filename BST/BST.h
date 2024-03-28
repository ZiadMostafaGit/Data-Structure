#include <iostream>

using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int val);
};

class BST
{

private:
    Node *root;

public:
    BST(int val);
    bool isEmpty();
    Node *addRecursive(Node *current, int value);
    void postOrderPrint(Node *current);
    Node *getroot();
    int getMax(Node *current);
    int newgetmax(Node *current);
    int getmin(Node *current);
    int getHeight(Node *root);
    int countAllNodes(Node *current);
    int countLeafNodes(Node *current);
    bool searchTree(Node *current, int val);
    bool isPerfect(Node *current);
    void preOrderPrint(Node *current);
    void inOrderPrint(Node *current);
    int Get_Diametar(Node *current);
    int Get_Hight_for_diametar(Node *current, int &diametar);
    void Level_by_Level_iterative();
    void Level_by_Level_recursive(Node *cur);
    void Printlevel(int level, Node *cur);
};
