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

node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *n = new node(d);

    n->left = buildTree();
    n->right = buildTree();
    return n;
}
// descendants and non-descandants both at distance k from target node.
void printAtLevelK(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
    return;
}

int distance_K_from_target(node *root, node *target, int K)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }

    // reach the target node look at all descendants of target.
    if (root == target)
    {
        printAtLevelK(target, K);
        return 0;
    }

    // other
    //  search in nondescendants of target K. in left subtree
    int DL = distance_K_from_target(root->left, target, K);
    if (DL != -1)
    {
        // 2 CASES   //Print the current node
        if (DL + 1 == K)
        {
            cout << root->data;
        }
        else
        {
            printAtLevelK(root->right, K - 2 - DL);
        }
        return 1 + DL;
    }
    int DR = distance_K_from_target(root->right, target, K);
    if (DR != -1)
    {
        if (DR + 1 == K)
        {
            cout << root->right;
        }
        else
        {
            printAtLevelK(root->left, K - 2 - DR);
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
    cout << distance_K_from_target(root, target, k);
    return 0;
}