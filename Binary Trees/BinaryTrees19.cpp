// Ceil In A Binary Tree.

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

int Find_Ceil(Node* root, int key){
    
    if(root == NULL){
        return -1;
    }

    if(root->data == key){
        return root->data;
    }
    if(root->data < key){
        return Find_Ceil(root->right,key);
    }

    int ceil = Find_Ceil(root->left,key);

    return (ceil >= key) ? ceil : root->data;
}

int main(){

    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right->right = new Node(9);
    root->right = new Node(13);
    root->right->left = new Node(11);
    root->right->right = new Node(14);

    cout<<Find_Ceil(root,8);

    return 0;
}