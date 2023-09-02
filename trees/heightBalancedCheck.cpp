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
    node(int val) : data(val)
    {
        left = nullptr;
        right = nullptr;
    }
};
int heightOfTree(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int height = 0, leftH = 0, rightH = 0;
    if (root->left != nullptr)
        leftH = heightOfTree(root->left);
    if (root->right != nullptr)
        rightH = heightOfTree(root->right);
    height = 1 + max(leftH, rightH);
    return height;
}

bool isHeightBalanced(node *root)
{
    if (root == nullptr)
    {
        return true;
    }
    int HL = 0, HR = 0;
    bool lBal = true, rBal = true;
    if (root->left)
    {
        lBal = isHeightBalanced(root->left);
        HL = heightOfTree(root->left);
    }
    if (root->right)
    {
        rBal = isHeightBalanced(root->right);
        HR = heightOfTree(root->right);
    }

    int diff = abs(HL - HR);
    if (diff <= 1 and lBal and rBal)
        return true;
    return false;
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
    // remove last 2 lines = balanced else not
    node *target = root->left->right;

    if (isHeightBalanced(root))
        cout << "height balanced";
    else
        cout << "not height balanced.";
    return 0;
}
