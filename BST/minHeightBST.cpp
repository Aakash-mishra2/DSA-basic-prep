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
Node *minHeightBST(int arr[], int s, int e, Node *root)
{
    if (s > e)
    {
        return nullptr;
    }
    else
    {
        int mid = s + (e - s) / 2;
        root = new Node(arr[mid]);
        root->left = minHeightBST(arr, s, mid - 1, root->left);
        root->right = minHeightBST(arr, mid + 1, e, root->right);
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
int main()
{
    file_i_o();
    Node *root = nullptr;
    int arr[] = {7, 5, 6, 3, 4, 2, 1, 8};
    sort(arr, arr + 8);
    root = minHeightBST(arr, 0, 7, root);
    printBST(root);
    return 0;
}
