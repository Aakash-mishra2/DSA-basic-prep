#include <iostream>
#include <queue>
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
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
// helper function: height of tree
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1, h2);
}
// bool checkHeightBalanced(node *root){
//         checkHeightBalanced(root->left);
//         checkHeightBalanced(root->right);
//     if (abs(height(root->left) - height(root->right)) == 1)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// try tree diameter similarly with it.
pair<int, bool> isHeightBalanced(node *root)
{
}

node *buildTree()
{
}
// INPUT: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
void levelOrderPrint(node *root)
{
}

int main()
{
    freopen("treeinput.txt", "r", stdin);
    node *root = buildTree();
    levelOrderPrint(root);
    if (isHeightBalanced(root).second == true)
    {
        cout << endl
             << " Tree is height balanced. " << endl;
    }
    else
    {
        cout << endl
             << " Tree is not height balanced. " << endl;
    }
    return 0;
}