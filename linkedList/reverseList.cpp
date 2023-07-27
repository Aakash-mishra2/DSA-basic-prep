#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int data) : data(data), next(nullptr){}
};
void file_i_o(){
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("../bsearch/input.txt", "r", stdin);
	freopen("../bsearch/output.txt", "w", stdout);
	#endif
}
void insertAtBeginning(Node*& head, int newVal){
	Node* temp = new Node(newVal);
	temp->next = head;
	head = temp;
}
void printLinkedList( Node* head){
	cout<<"Current \tData\t Next"<<endl;
	while(head->next != nullptr){
		cout<<head<<"\t"<<head->data<<"\t"<<head->next<<endl;
		head = head->next;
	}
	cout<<head<<"\t"<<head->data<<"\tNULL"<<endl;
}
Node* reverseListREC(Node*& root){
	if( root->next == nullptr or root==nullptr){
		return root;
	}
	Node* Sroot = reverseListREC(root->next);
	root->next->next = root;
	root->next = nullptr;
	return Sroot;
}
Node* reverseListITR(Node*& root){
	Node* prev = nullptr;
	Node* current = root;
	Node* temp = nullptr;

}
int main(){
	file_i_o();
	Node* root = new Node(5);
	insertAtBeginning(root, 13);
	insertAtBeginning(root, 45);
	insertAtBeginning(root, 890);
	insertAtBeginning(root, 23);
	//cout<<root;
	printLinkedList(root);
	cout<<"REVERSED RECURSIVELY"<<endl;
	root = reverseListREC(root);
	printLinkedList(root);
	cout<<"REVERSED ITERATIVELY"<<endl;
	root = reverseListITR(root);
	printLinkedList(root);
	return 0;
}