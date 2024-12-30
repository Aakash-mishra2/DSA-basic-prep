#include <bits/stdc++.h>
using namespace std;

/*
If we simply use the "kth node from the bottom" phrasing, it can be ambiguous because multiple nodes might exist at the same level in a binary tree. However, in the context of a Binary Search Tree (BST), the "kth node from the bottom" can be interpreted as the kth smallest or kth largest node (or its reverse, depending on traversal).
 */

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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void findKthFromBottom(TreeNode *root, int &k, int &result)
{
    if (!root || k <= 0)
        return;

    // Traverse the right subtree first (for reverse in-order)
    findKthFromBottom(root->right, k, result);

    // Decrement k (count down)
    k--;
    if (k == 0)
    {
        result = root->val; // Found the kth node
        return;
    }

    // Traverse the left subtree
    findKthFromBottom(root->left, k, result);
}

int kthFromBottom(TreeNode *root, int k)
{
    int result = -1; // Placeholder for result
    findKthFromBottom(root, k, result);
    return result; // Returns -1 if k is out of bounds
}

int main()
{
    file_i_o();
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    int k = 3; // Find the 3rd node from the bottom
    int result = kthFromBottom(root, k);

    if (result != -1)
    {
        cout << "The " << k << "rd node from the bottom is: " << result << endl;
    }
    else
    {
        cout << "The tree has fewer than " << k << " nodes." << endl;
    }

    return 0;
}
