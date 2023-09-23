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
    Node(T val) : data(val), next(nullptr) {}
};
template <typename T>
void insertAtBeginning(Node<T> *&root, int newVal)
{
    Node<T> *head = new Node<T>(newVal);
    if (root == nullptr)
    {
        root = head;
    }
    else
    {
        head->next = root;
        root = head;
    }
}
template <typename t>
void printLinkedList(Node<t> *root)
{
    Node<t> *head = root;
    cout << "Current \t Data \t NextNode" << endl;
    while (head->next != nullptr)
    {
        cout << head << "\t" << head->data << "\t" << head->next << endl;
        head = head->next;
    }
    cout << head << "\t" << head->data << "\t" << head->next << endl;
}
//in C++ *binds to the declarator not the type specifier. 
//declarations are based on type of expressions not objects;
template <typename T>
void reverseList(Node<T> *&root)
{
    if(root == nullptr){ return; }
    Node<T> *temp = nullptr, *current = root, *prev = nullptr;
    while(current!= nullptr){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    root = prev;
    return;
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
    reverseList<int>(root);
    printLinkedList<int>(root);
    return 0;
}
