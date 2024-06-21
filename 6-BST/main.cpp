#include <iostream>
#include "BST.cpp"
using namespace std;

int main()
{
    BST bt(10);
    Node *current = bt.getroot();
    int arr[20] = {10, 5, 15, 3, 7, 12, 18, 2, 4, 6, 8, 11, 13, 16, 19, 1, 9, 14, 17, 20};
    for (int c : arr)
    {

        bt.addRecursive(current, c);
    }

    bt.inOrderPrint(current);
    cout << endl;
    int max = bt.newgetmax(current);
    cout << max << endl;
    // cout << bt.Get_Diametar(current) << endl;
    // bt.Level_by_Level_iterative();

    // cout << "Postorder Traversal: ";
    // bt.postOrderPrint(current);
    // cout << endl;

    // cout << "Max Value: " << bt.getMax(current) << endl;
    // cout << "Tree Height: " << bt.getHeight(current) << endl;
    // cout << "Total Nodes: " << bt.countAllNodes(current) << endl;
    // cout << "Leaf Nodes: " << bt.countLeafNodes(current) << endl;

    // cout << "Search for 12: " << (bt.searchTree(current, 12) ? "Found" : "Not Found") << endl;
    // cout << "Is Perfect Binary Tree: " << (bt.isPerfect(current) ? "Yes" : "No") << endl;

    // cout << "Preorder Traversal: ";
    // bt.preOrderPrint(current);
    // cout << endl;

    // cout << "Inorder Traversal: ";
    // bt.inOrderPrint(current);
    // cout << endl;
    //    system("pause");
}
