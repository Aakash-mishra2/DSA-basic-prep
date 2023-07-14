#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

public:
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void nodesK_LevelsBelow(node *target, int K)
{

    if (K == 0)
    {
        cout << target->data << " ";
        return;
    }

    nodesK_LevelsBelow(target->left, K - 1);
    nodesK_LevelsBelow(target->right, K - 1);
    return;
}

int printNodesAtDistanceK(node *root, node *target, int k)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }
    // react the target node
    if (root == target)
    {
        nodesK_LevelsBelow(target, k);
        return 0;
    }
    // other case
    int DL = printNodesAtDistanceK(root->left, target, k - 1);
    if (DL != -1)
    {
        // 2 cases
        // print the current node
        if (1 + DL == k)
        {
            cout << root->data << " ";
        }
        // or print somenodes in the rightsubtree
        else
        {
            nodesK_LevelsBelow(root->right, k - DL - 2);
        }
        return 1 + DL;
    }

    int DR = printNodesAtDistanceK(root->right, target, k - 1);
    if (DR != -1)
    {
        if (1 + DR == k)
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