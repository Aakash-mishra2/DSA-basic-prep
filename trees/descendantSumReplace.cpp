#include <bits/stdc++.h>
using namespace std;

class node
{
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
    friend void levelOrderPrint(node *);
    friend node *buildTree();
    friend int replaceWithSum(node *);
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

void levelOrderPrint(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        if (temp == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return;
}
// Todo: Replace with descendant Sum leaving leaf nodes intact
int replaceWithSum(node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }
    // leaf node
    if (root->left == NULL and root->right == NULL)
    {
        return root->data;
    }
    // recursive case
    int LS = replaceWithSum(root->left);
    int RS = replaceWithSum(root->right);

    int temp = root->data;
    root->data = LS + RS;
    return root->data + temp;
}
int main()
{
    freopen("treeinput.txt", "r", stdin);
    node *root = buildTree();
    levelOrderPrint(root);
    cout << endl;
    replaceWithSum(root);
    levelOrderPrint(root);
    return 0;
}