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
    if(root == nullptr){ return 0;}
    int hR = heightOfTree(root->right);
    int hl = heightOfTree(root->left);
    return max(hR, hl) + 1;
}

bool isHeightBalanced(node *root)
{

    bool lbal = true, rbal = true; int hL = 0, hR= 0;
    
    if(root->left){
    lbal = isHeightBalanced(root->left);
    hL = heightOfTree(root->left);
    }
    if(root->right){
    rbal = isHeightBalanced(root->right);
    hR = heightOfTree(root->right);
    }
    int diff = abs(hL - hR);
    return diff <= 1 and lbal and rbal;
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
    root->right->left = new node(8);
    root->right->left->left = new node(9);
    root->right->left->right = new node(10);
    // remove last 2 lines = balanced else not
    node *target = root->left->right;

    if (isHeightBalanced(root))
        cout << "height balanced";
    else
        cout << "not height balanced.";
    cout<<" \n height is "<<heightOfTree(root);
    return 0;
}
