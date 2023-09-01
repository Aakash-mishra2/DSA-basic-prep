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
    node *left;
    node *right;
    int inc = 0;
    int exc = 0;

public:
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *maxSubsetSum(node *root)
{
    if (root == NULL)
    {
        return new node(0);
    }
    auto L = maxSubsetSum(root->left);
    auto R = maxSubsetSum(root->right);

    root->inc = root->data + L->exc + R->exc;
    root->exc = max(L->inc, L->exc) + max(R->inc, R->exc);
    return root;
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

    maxSubsetSum(root);

    cout << max(root->inc, root->exc) << endl;

    return 0;
}
