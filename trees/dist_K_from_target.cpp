#include <bits/stdc++.h>
using namespace std;
void file_io()
{
    ios_base::sync_with_stdio;
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("treeinput.txt", "r", stdin);
    freopen("treeoutput.txt", "w", stdout);
#endif
}
class node
{
public:
    int data;
    node *left = nullptr;
    node *right = nullptr;
    node(int val) : data(val) {}
};

void nodesKBelow(node* head, int K, vector<int>& answer){
    if(head == nullptr){ return;}
    if( K == 0 ) answer.push_back(head->data);
    nodesKBelow(head->left, K-1, answer);
    nodesKBelow(head->right, K-1, answer);
    return;
}

int requiredNodes(node *root, node *target, int k, vector<int> &answer)
{
    if(root == nullptr){ return -1; }
    if(root == target){
        nodesKBelow(target, k, answer);
        return 0;
    }
    //find target in left and right subtree;
    int DL = requiredNodes(root->left, target, k, answer);
    if(DL != -1){ // found target in LeftST return 0 to parent node
        if(1 + DL == k){    answer.push_back(root->data);}
        else{   nodesKBelow(root->right, k-DL-2, answer); } //nodes in rightST
        return 1+DL;
    }
    int DR = requiredNodes(root->right, target, k, answer);
    if(DR != -1){   // found target in rightST returns 0 to parent node
        if(1 + DR == k) answer.push_back(root->data);
        else{ nodesKBelow(root->left, k-DR-2, answer); }//add nodes in leftST 
        return 1+DR;
    }
    return -1;
}
vector<int> nodesAtDistanceK(node *root, node *target, int k)
{
    vector<int> answer;
    requiredNodes(root, target, k, answer);
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    file_io();
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);
    root->left->right->right->left = new node(9);
    root->left->right->right->right = new node(10);

    node *target = root->left->right;

    int k = 2;
    auto ans = nodesAtDistanceK(root, target, k);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
