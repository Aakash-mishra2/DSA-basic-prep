#include <iostream>
#include<bits/stdc++.h>
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
    Node<T>* temp = new Node<T>(newVal);
    if(head == nullptr){ head = temp; return;}
    temp->next = head;
    head = temp;
}
template <typename T>
void printLinkedList(Node<T> *root)
{
    if(root == nullptr){ return;}
    while(root!= nullptr){
        cout<<root<<"\t"<<root->data<<"\t"<<root->next<<endl;
        root = root->next;
    }
}

template <typename T>
void insertAtEnd(Node<T> *&root, T lastValue)
{
    Node<T>* temp = new Node<T>(lastValue);
    if( root == nullptr){ 
        root = temp; 
        return;
    }
    auto head = root;
    while(head->next != nullptr){
        head = head->next;
    }
    head->next = temp;
}

template <typename T>
void insertAfter(Node<T> *&root, T midValue, T newValue)
{
    if(root == nullptr){ return; }
    Node<T>* temp = new Node<T>(newValue);
    Node<T>* head = root;
    while(head != nullptr and (head->data != midValue)){    head = head->next; }
    if(head == nullptr){ cout<<" Entered midvalue doesnot exist"<<endl; return; }
    temp -> next = head->next;
    head->next = temp;

}
int main()
{
    file_io();
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
