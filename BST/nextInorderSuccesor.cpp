// inorder successor one way to inorder traversal, store in array then easy.
// above take O(N);
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
        right = nullptr;
        left = nullptr;
    }
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
// next inOrderSuccesor
//  giving exact target node as data can be same in multiple nodes;
Node *inOrderSuccessor(Node *target, Node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (target->right != nullptr)
    {
        Node *temp = target->right;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp;
    }
    Node *temp = root;
    Node *succ = nullptr;
    while (temp != nullptr)
    {
        if (temp->val > target->val)
        {
            succ = temp;
            temp = temp->left;
        }
        else if (temp->val < target->val)
        {
            temp = temp->right;
        }
        else
        {
            break;
        }
    }
    return succ;
}

int main()
{
    file_i_o();
    Node *root = nullptr;
    vector<int> arr = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int i = 0; i < arr.size(); i++)
    {
        root = addNode(root, arr[i]);
    }
    printBST(root);
    cout << endl;
    Node *t1 = root->left->right->right;
    Node *t2 = root->right;
    cout << "In order successor of 7 is " << inOrderSuccessor(t1, root)->val << endl;
    cout << "In order successor of 10 is " << inOrderSuccessor(t2, root)->val << endl;
    return 0;
}
