#include <bits/stdc++.h>
using namespace std;

class node
{
};

node *buildTree()
{
}

void levelOrderPrint(node *root)
{
}
// Todo: Replace with descendant Sum leaving leaf nodes intact
int replaceWithSum(node *root)
{
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