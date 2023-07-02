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
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
class HDpair
{
public:
    int height;
    int diameter;
};
// diameter is largest distance between any two nodes of a tree. like in circle diameter is distance between two farthest points.
HDpair treeDiameter(node *root)
{
    HDpair p, left, right;
    if (root == NULL)
    {
        p.height = 0;
        p.diameter = 0;
        return p;
    }
    left = treeDiameter(root->left);
    right = treeDiameter(root->right);
    p.height = max(left.height, right.height) + 1;

    // mase1: incase diameter passes through the root
    int D1 = left.height + right.height;

    // case2: diameter lies completely inside left subtree
    int D2 = left.diameter;

    // case3: diameter lies completely inside right subtree
    int D3 = right.diameter;
    p.diameter = max(D1, max(D2, D3));
    return p;
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
int main()
{
    freopen("treeinput.txt", "r", stdin);
    node *root = buildTree();
    auto ans = treeDiameter(root);
    levelOrderPrint(root);
    cout << endl
         << "Optimized Diameter = " << ans.diameter;
    return 0;
}