int heightOfTree(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int height = 0;
    if (root->left)
        int leftH = heightOfTree(root->left);
    if (root->right)
        int rightH = heightOfTree(root->right);
    height = 1 + max(leftH, rightH);
    return height;
}
