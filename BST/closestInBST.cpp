// iterative app has better space com and O(1) comp.

int closestInBST(int target, Node *root, int &min = INT_MAX)
{

    int closest;
    int diff = INT_MAX;
    Node *temp = root;
    while (temp != NULL)
    {
        int current_diff = abs(temp->key - target);
        if (current_diff == 0)
        {
            return temp->key;
        }

        if (current_diff < diff)
        {
            diff = current_diff;
            closest = root->key;
        }
        if (temp->key < target)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return closest;
}
