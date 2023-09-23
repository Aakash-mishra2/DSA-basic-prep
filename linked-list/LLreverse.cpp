#include <iostream>
using namespace std;
void file_io(){
    ios_base::sync_with_stdio;
    cout.tie(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../MORE_miscc/input.txt", "r", stdin);
        freopen("../MORE_miscc/output.txt", "w", stdout);
    #endif
    }
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
    cout << root << "\t" << root->data << "\t "
         << "NULL" << endl;
}

template <typename T>
Node<T> *reverseList(Node<T> *head)
{
    if(head->next == nullptr ){
        return head;
    }
    Node<T>* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{
    file_io();
    Node<int> *root = new Node<int>(3);
    cout << "--NEW LINKED LIST-----" << endl;
    insertAtBeginning<int>(root, 78);
    insertAtBeginning<int>(root, 9);
    insertAtBeginning<int>(root, 34);
    insertAtBeginning<int>(root, 45);
    printLinkedList<int>(root);
    cout << " -- REVERSED LINKED LIST ------" << endl;
    root = reverseList<int>(root);
    printLinkedList<int>(root);
    return 0;
}
