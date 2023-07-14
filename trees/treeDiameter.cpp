#include <bits/stdc++.h>
using namespace std;
class node
{
};

node *buildTree()
{
}
class HDpair
{
};
// diameter is largest distance between any two nodes of a tree. like in circle diameter is distance between two farthest points.
HDpair treeDiameter(node *root)
{
}
void levelOrderPrint(node *root)
{
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