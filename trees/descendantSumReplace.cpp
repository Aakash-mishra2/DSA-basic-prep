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
    node *left = nullptr;
    node *right = nullptr;
    node(int val) : data(val) {}
};

node *preOrderbuildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return nullptr;
    }
    node *temp = new node(d);
    temp->left = preOrderbuildTree();
    temp->right = preOrderbuildTree();
    return temp;
}
void levelOrderPrint(node *root)
{
    if (root == nullptr){
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
// Todo: Replace with descendant Sum leaving leaf nodes intact

int replaceWithSum(node *root)
{
    int leftST = 0, temp = 0, rightST=0;
    if(root->left) leftST = replaceWithSum(root->left);
    if(root->right) rightST = replaceWithSum(root->right);
    temp = root->data;
    root->data = leftST + rightST;
    return (temp + root->data);
}

//replace with descendant sum leaving leaf nodes intact
// int replaceWithSum(node *root)
// {
//     if(root == NULL) return 0;
//     if(root->left == NULL and root->right==NULL) return root->data;
    
//     //recursive case
//     int LS = replaceWithSum(root->left);
//     int RS = replaceWithSum(root->right);

//     int temp = root->data;
//     root->data = LS + RS; 
//     return root->data + temp;
// }
int main()
{
    file_io();
    node *root = preOrderbuildTree();
    levelOrderPrint(root);

    cout << endl;
    cout<<replaceWithSum(root)<<endl;
    //levelOrderPrint(root);
    return 0;
}
