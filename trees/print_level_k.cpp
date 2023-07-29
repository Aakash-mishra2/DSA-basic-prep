#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(int val): data(val){}
};

Node* buildTree(){
	int d; cin>>d;
	if(d==-1){ return nullptr;}
	Node* temp = new Node(d);
	temp->left = buildTree();
	temp->right = buildTree();
	return temp;
}

void printAtLevelK(Node* head, int K){
	if( K == 0){
		cout<<head->data<<" ";
	}
	if(head->left) printAtLevelK(head->left, K-1);
	if(head->right) printAtLevelK(head->right, K-1);
	return;
}

void file_i_o(){
	ios::sync_with_stdio;
	cout.tie(0); cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	#endif
}
//Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1 <value of K>
int main(){
	file_i_o();
	Node* root = buildTree();
	int K; cin>>K;
	printAtLevelK(root, K); 
	return 0;
}
