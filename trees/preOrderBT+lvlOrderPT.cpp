#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(int val): data(val){}
};

Node* preOrderbuildTree(){
	int d; cin>>d; 
	if(d==-1){ return nullptr; }
	Node* temp = new Node(d);
	temp->left = preOrderbuildTree();
	temp->right = preOrderbuildTree();
	return temp;
}
void file_i_o(){
	ios_base::sync_with_stdio;
	cout.tie(0); cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}
void levelOrderPrint(Node* root){
	queue<Node*> q;
	q.push(root);
	q.push(nullptr);
	while(!q.empty()){
	Node* temp = q.front();	
	if(temp== nullptr){ cout<<endl; q.pop();
		if(!q.empty())	q.push(nullptr); 
	}
		else{ q.pop(); cout<<temp->data<<" ";
		if(temp->left)	q.push(temp->left);
		if(temp->right)	q.push(temp->right);
			}
		}
	return;
}
int main(){
	file_i_o();
	Node* root = preOrderbuildTree();
	levelOrderPrint(root);
	return 0;
}		
