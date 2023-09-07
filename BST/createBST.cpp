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
};
Node *addNode(Node *root, int newVal)
{
    if(root==nullptr){ return new Node(newVal); }
    if(newVal > root->val){
        root->right= addNode(root->right, newVal);
    }
    else { root->left = addNode(root->left, newVal); }
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
    return 0;
}
