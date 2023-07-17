#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *next;

public:
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
    cout << root->data << " "
         << "NULL" << endl;
}

template <typename T>
void insertAtEnd(Node<T> *&root, T lastValue)
{
    Node<T> *temp = root;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node<T> *lastNode = new Node<T>(lastValue);
    temp->next = lastNode;
}

template <typename T>
void insertAfter(Node<T> *&root, T midValue, T newValue)
{
    Node<T> *temp = root;
    while ((temp->next != NULL) and (temp->data != midValue))
    {
        temp = temp->next;
    }
    Node<T> *midNode = new Node<T>(newValue);
    midNode->next = temp->next;
    temp->next = midNode;
}
int main()
{
    Node<int> *root = new Node<int>(6);
    cout << root->data << " " << root->next << endl;
    root->next = new Node<int>(9);
    root->next->next = new Node<int>(10);
    cout << " NEW LINKED LIST ------" << endl;
    printLinkedList<int>(root);
    cout << " Insert 78 at starting ----------" << endl;
    insertAtBeginning(root, 78);
    printLinkedList<int>(root);
    cout << " Insert 4 at Ending -------" << endl;
    insertAtEnd(root, 4);
    printLinkedList<int>(root);
    cout << " Insert 456 after 9 ----------" << endl;
    insertAfter(root, 9, 456);
    printLinkedList<int>(root);

    return 0;
}