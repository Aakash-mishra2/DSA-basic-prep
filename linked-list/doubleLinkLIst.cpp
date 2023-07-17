#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *nextNode;
    Node *prevNode;
    Node(T val)
    {
        this->data = val;
        nextNode = NULL;
        prevNode = NULL;
    }
};
template <typename T>
void insertNewNode(Node<T> *&head, T data)
{
    Node<T> *temp = new Node<T>(data);
    temp->nextNode = head;
    head->prevNode = temp;
    head = temp;
}
template <typename T>
void printDLL(Node<T> *root)
{
    cout << endl
         << "Previous "
         << "\t"
         << "Data"
         << "\t"
         << "Next Node" << endl;
    while (root->nextNode != NULL)
    {
        cout << root->prevNode << "\t" << root->data << "\t" << root->nextNode << endl;
        root = root->nextNode;
    }
    cout << root->prevNode << "\t" << root->data << "\tNULL" << endl;
}
template <typename T>
void insertNodeAfter(Node<T> *&root, T midValue, T newVal)
{
    Node<T> *head = root;
    while ((head->data != midValue) and (head->nextNode != NULL))
    {
        head = head->nextNode;
    }
    Node<T> *temp = new Node<T>(newVal);
    temp->nextNode = head->nextNode;
    temp->prevNode = head;
    head->nextNode = temp;
}
int main()
{
    Node<int> *root = new Node<int>(44);
    insertNewNode<int>(root, 342);
    insertNewNode<int>(root, 34);
    insertNewNode<int>(root, 8990);
    insertNewNode<int>(root, 23);
    insertNewNode<int>(root, 234);
    printDLL<int>(root);
    insertNodeAfter<int>(root, 8990, 000);
    printDLL<int>(root);
    return 0;
}