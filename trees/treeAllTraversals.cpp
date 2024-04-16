// Binary Tree in C++

#include <stdlib.h>

#include <iostream>

using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

// New node creation
struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = nullptr;
  node->right = nullptr;
  return (node);
}

// Traverse Preorder
void traversePreOrder(struct node *temp) {
 if( temp == nullptr){
     return;
 }
 cout<<temp->data<<" ";
 traversePreOrder(temp->left);
 traversePreOrder(temp->right);
}

// Traverse Inorder
void traverseInOrder(struct node *temp) {
    if( temp == nullptr){
     return;
 }
 traversePreOrder(temp->left);
 cout<<temp->data<<" ";
 traversePreOrder(temp->right);
}

// Traverse Postorder
void traversePostOrder(struct node *temp) {

if( temp == nullptr){
     return;
 }
 traversePreOrder(temp->left);
 traversePreOrder(temp->right);
 cout<<temp->data<<" ";

}

int main() {
  struct node *root = newNode(2);
  root->left = newNode(5);
  root->right = newNode(1);
  root->left->left = newNode(4);

  cout << "preorder traversal: ";
  traversePreOrder(root);
  cout << "\nInorder traversal: ";
  traverseInOrder(root);
  cout << "\nPostorder traversal: ";
  traversePostOrder(root);
}
