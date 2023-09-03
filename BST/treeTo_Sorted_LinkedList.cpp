#include <bits/stdc++.h>
using namespace std;
void file_i_o()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
class Node
{
public:
    int val;
    Node *right;
    Node *left;
    Node(int d)
    {
        val = d;
        right = left = nullptr;
    }
    // Node *head;
    // node *tail;
};
Node *addNode(Node *root, int newVal)
{
    if (root == nullptr)
    {
        return new Node(newVal);
    }
    else if (root->val < newVal)
    {
        root->right = addNode(root->right, newVal);
    }
    else
    {
        root->left = addNode(root->left, newVal);
    }
    return root;
}
void printBST(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    printBST(root->left);
    cout << root->val << " ";
    printBST(root->right);
}
// Node *treeToLL(Node *root)
// {
//     if (root->left == nullptr and root->right == nullptr)
//     {
//         root->head = root;
//         root->tail = root;
//         return root;
//     }
//     Node *Lchild = treeToLL(root->left);
//     Lchild->tail = root;
//     Node *Rchile = treeToLL(root->right);
//     root->tail = Rchile->head;
//     return Lchild->head;
// }
// PK SIR
class LinkedList
{
public:
    Node *head;
    Node *tail;
};
LinkedList tree2LL(Node *root)
{
    LinkedList l;
    if (root == nullptr)
    {
        l.head = l.tail = nullptr;
        return l;
    }
    // 4 cases;
    if (root->left and root->right)
    {
        LinkedList rightL = tree2LL(root->right);
        LinkedList leftL = tree2LL(root->left);
        root->right = rightL.head;
        leftL.tail->right = root;
        l.head = leftL.head;
        l.tail = rightL.tail;
    }
    else if (root->left == nullptr and root->right == nullptr)
    {
        l.head = root;
        l.tail = root;
    }
    else if (root->left == nullptr and root->right != nullptr)
    {
        LinkedList rightL = tree2LL(root->right);
        root->right = rightL.head;
        l.head = root;
        l.tail = rightL.tail;
    }
    else
    {
        LinkedList leftL = tree2LL(root->left);
        leftL.tail->right = root;
        l.head = leftL.head;
        l.tail = root;
    }
    return l;
}
int main()
{
    file_i_o();
    Node *root = nullptr;
    int arr[] = {2, 8, 3, 14, 23, 6, 7, 16};
    for (int i = 0; i < 8; i++)
    {
        root = addNode(root, arr[i]);
    }
    printBST(root);
    cout << endl;
    LinkedList ans = tree2LL(root);
    Node *temp = ans.head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->right;
    }
    return 0;
}
