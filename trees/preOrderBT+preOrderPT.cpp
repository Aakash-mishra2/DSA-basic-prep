#include<bits/stdc++.h>
using namespace std;
void file_i_o(){
	ios_base::sync_with_stdio;
	cout.tie(0); cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}
class Node{
public:
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(int val): data(val){}
};
Node* preOrderBuildTree(){
	int d; cin>>d;
	if(d==-1) return nullptr;
	Node* temp = new Node(d);
	temp->left = preOrderBuildTree();
	temp->right = preOrderBuildTree();
	return temp;
}
void preOrderPrintTree(Node* root){
	if(root==nullptr){ return;}
	else{
		cout<<root->data;
		preOrderPrintTree(root->left);
		preOrderPrintTree(root->right);
	}
}
int main(){
	file_i_o();
	Node* root = preOrderBuildTree();
	preOrderPrintTree(root);
	return 0;
}