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

node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return nullptr;
    }
    node *temp = new node(d);
    temp->left = buildTree();
    temp->right = buildTree();
    return temp;
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
    HDpair answer;

    if (root == nullptr)
    {
        answer.height = 0;
        answer.diameter = 0;
        return answer;
    }
    HDpair right = treeDiameter(root->right);
    HDpair left = treeDiameter(root->left);

    answer.height = 1 + max(right.height, left.height);
    int D1 = right.height + left.height;
    int D2 = right.diameter;
    int D3 = left.diameter;

    answer.diameter = max(D1, max(D2, D3));
    return answer;
}
void levelOrderPrint(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        node *temp = q.front();
        if (temp == nullptr)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << temp->data << " ";
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return;
}
int main()
{
    file_io();
    node *root = buildTree();
    auto ans = treeDiameter(root);
    levelOrderPrint(root);
    cout << endl
         << "Optimized Diameter = " << ans.diameter;
    return 0;
}
