// Flatten A Binary Tree.

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* next;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void Flatten_BinaryTree(Node* root){
    
    if(root == NULL || root->left == NULL || root->right == NULL){
        return;
    }

    if(root->left != NULL){
        Flatten_BinaryTree(root->left);
        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* tail = root->right;
        while(tail->right != NULL){
            tail = tail->right;
        }

        tail->right = temp;
    }
    Flatten_BinaryTree(root->right);
}

int main(){

    Node* root = new Node(4);
    root->left = new Node(9);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    Flatten_BinaryTree(root);
    inorder(root);

    return 0;
}