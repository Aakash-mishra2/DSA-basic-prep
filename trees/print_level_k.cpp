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

int main()
{
    freopen("treeinput.txt", "r", stdin);
    node *root = buildTree();
    int K = 2;
    printAtLevelK(root, K);
    return 0;
}