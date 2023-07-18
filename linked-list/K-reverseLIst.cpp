#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val) : data(val), next(nullptr) {}
};

node *Kreverse(int K, node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    node *prev = nullptr;
    node *current = root;
    node *temp;
    int cnt = 1;

    while ((current != nullptr) and (cnt <= K))
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
        cnt++;
    }
    if (current != nullptr)
    {
        root->next = Kreverse(K, current);
    }
    return prev;
}

void insertAtBeginning(node *&root, int val)
{
    node *temp = new node(val);
    temp->next = root;
    root = temp;
}
void printLinkedList(node *root)
{
    cout << endl
         << "Current Node \t Data \t Previous Node" << endl;
    while (root->next != nullptr)
    {
        cout << root << "\t" << root->data << "\t" << root->next << endl;
        root = root->next;
    }
    cout << root << "\t" << root->data << "\t"
         << "NULL" << endl;
}
int main()
{
    node *root = new node(1);
    cout << " ------- NEW LINKED LIST -----" << endl;
    insertAtBeginning(root, 2);
    insertAtBeginning(root, 3);
    insertAtBeginning(root, 4);
    insertAtBeginning(root, 5);
    insertAtBeginning(root, 6);
    insertAtBeginning(root, 7);
    insertAtBeginning(root, 8);
    printLinkedList(root);
    root = Kreverse(3, root);
    printLinkedList(root);
    return 0;
}