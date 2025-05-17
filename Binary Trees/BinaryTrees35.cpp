// LCA in BST (Applicable for Binary Search Trees).

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


Node* LCA(Node* root, Node* n1, Node* n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data < n1->data && root->data < n2->data){
        return LCA(root->right,n1,n2);
    }
    if(root->data > n1->data && root->data > n2->data){
        return LCA(root->left,n1,n2);
    }
    return root;
}

int main(){

    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);  
    root->right->right = new Node(7);

    cout<<LCA(root,root->right,root->right->right)->data;

    return 0;
}
/*
       4
      /  \
     2    5
    / \
   1   3
*/