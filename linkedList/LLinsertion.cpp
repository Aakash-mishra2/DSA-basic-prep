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
// ostream& operator<<(ostream& os, Node*& head){
// 	os<<"Current Node\tData\tNextNode"<<endl;
// 	while(head->next != nullptr){
// 		os<<head<<"\t"<<head->data<<"\t"<<head->next<<endl;
// 		head = head->next;
// 	}
// 	os<<head<<"\t"<<head->data<<"\t"<<head->next<<endl;
// 	return os;
// }
void printLinkedList( Node* head){
	cout<<"Current \tData\t Next"<<endl;
	while(head->next != nullptr){
		cout<<head<<"\t"<<head->data<<"\t"<<head->next<<endl;
		head = head->next;
	}
	cout<<head<<"\t"<<head->data<<"\tNULL"<<endl;
}
void insertAtEnd(Node* iterator,int newVal){
	Node* temp = new Node(newVal);
	while(iterator->next != nullptr){ iterator=iterator->next;}
	iterator->next=temp;
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
	insertAtEnd(root, 555);
	insertAtEnd(root, 4343);
	printLinkedList(root);
	return 0;
}