#include <bits/stdc++.h>
using namespace std;
class node
{
};

void nodesK_LevelsBelow(node *target, int K)
{
}

int printNodesAtDistanceK(node *root, node *target, int k)
{
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