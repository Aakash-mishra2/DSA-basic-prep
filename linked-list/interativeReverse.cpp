#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    int data;
    Node *next;
    Node(T val)
    {
        this->data = val;
        this->next = NULL;
    }
};

template <typename T>
void insertAtBeginning(Node<T> *&head, T newVal)
{
    Node<T> *temp = new Node<T>(newVal);
    temp->next = head;
    head = temp;
}
template <typename T>
void printLinkedList(Node<T> *root)
{
    cout << "Current Node \t Data \t Next Node " << endl;
    while (root->next != NULL)
    {
        cout << root << "\t " << root->data << "\t " << root->next << " " << endl;
        root = root->next;
    }
    cout << root << "\t" << root->data << "\t "
         << "NULL" << endl;
}

template <typename T>
void reverseList(Node<T> *&head)
{
    Node<T> *temp;
    Node<T> *current = head;
    Node<T> *prev = NULL;

    while (current->next != NULL)
    {
        temp = current->next; // store next
        current->next = prev; // update the current
        prev = current;
        current = temp;
    }
    head = prev;
    return;
}

int main()
{
    Node<int> *root = new Node<int>(3);
    cout << "--NEW LINKED LIST-----" << endl;
    insertAtBeginning<int>(root, 78);
    insertAtBeginning<int>(root, 9);
    insertAtBeginning<int>(root, 34);
    insertAtBeginning<int>(root, 45);
    printLinkedList<int>(root);
    cout << " -- REVERSED LINKED LIST ------" << endl;
    reverseList<int>(root);
    printLinkedList<int>(root);
    return 0;
}