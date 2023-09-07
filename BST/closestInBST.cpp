#include<bits/stdc++.h>
using namespace std;

void file_io(){
	ios_base::sync_with_stdio;
	cout.tie(0); cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt", "w", stdout);
	#endif
}
class node{
public:
	int data;
	node* right = nullptr;
	node* left = nullptr;
	node(int data): data(data){}
};
node* addNode(node* root, int val){
	if(root == nullptr){ return new node(val);}
	else if(root->data < val){
			root->right = addNode(root->right, val);
		}
	else
			root->left = addNode(root->left, val);
	return root;
}
void printBST(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}
int closest(int target, node*root){
	int closest, diff=INT_MAX;
	node* temp = root;
	while( temp !=  nullptr){
		int current = abs(temp->data - target);
		if( current == 0) return temp->data;
		else if( current < diff){
			closest = temp->data;
			diff = current;
		}
		if(temp->data < target){
			temp = temp->right;
		}
		else temp = temp->left;
	}
	return closest;
}
int main(){
	file_io();
	node* root = nullptr;
	vector<int> arr = { 12, 6, 1, 14, 7, 3, 11};
	for (int i = 0; i < arr.size(); i++)
    {
        root = addNode(root, arr[i]);
    }
     printBST(root);
	 cout << endl;
	 int key = 3;
    cout<<" Node closest to "<<key<<" is : "<<closest(key, root);
	return 0;
}
