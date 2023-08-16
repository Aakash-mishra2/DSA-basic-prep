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

public:
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void treeTraverse(node *tree, int d, map<int, vector<int>> &m)
{

    if (tree == NULL)
    {
        return;
    }
    m[d].push_back(tree->data);
    treeTraverse(tree->left, d - 1, m);
    treeTraverse(tree->right, d + 1, m);
}
void verticalOrderPrint(node *root)
{
    map<int, vector<int>> m;
    int d = 0;

    treeTraverse(root, d, m);

    for (auto p : m)
    {
        int key = p.first;
        vector<int> line = p.second;
        for (auto data : line)
        {
            cout << data << " ";
        }
        cout << endl;
    }
    return;
}

int main()
{
    file_io();
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);

    verticalOrderPrint(root);

    return 0;
}
