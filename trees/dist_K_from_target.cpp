#include <bits/stdc++.h>
using namespace std;
void file_io()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("treeinput.txt", "r", stdin);
    freopen("treeoutput.txt", "w", stdout);
#endif
}
class node
{
public:
    int data;
    node *left = nullptr;
    node *right = nullptr;
    node(int val) : data(val) {}
};

void nodesK_LevelsBelow(node *target, int k)
{
    if (k == 0)
    {
        cout << target->data << " ";
    }
    if (target->left)
        nodesK_LevelsBelow(target->left, k - 1);
    if (target->right)
        nodesK_LevelsBelow(target->right, k - 1);
    return;
}

int printNodesAtDistanceK(node *root, node *target, int k)
{
    if (root == nullptr)
    {
        return -1;
    }
    if (root == target)
    {
        nodesK_LevelsBelow(root, k);
        return 0;
    }
    int DL = printNodesAtDistanceK(root->left, target, k);
    if (DL != -1)
    {
        if (DL + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            nodesK_LevelsBelow(root->right, k - DL - 2);
        }
        return 1 + DL;
    }
    int DR = printNodesAtDistanceK(root->right, target, k);
    if (DR != -1)
    {
        if (DR + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            nodesK_LevelsBelow(root->left, k - DR - 2);
        }
        return 1 + DR;
    }
    return -1;
}

int main()
{
    file_io();
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);
    root->left->right->right->left = new node(9);
    root->left->right->right->right = new node(10);

    node *target = root->left->right;

    int k = 2;
    cout << printNodesAtDistanceK(root, target, k);
    return 0;
}
