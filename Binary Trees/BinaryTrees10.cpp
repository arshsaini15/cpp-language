// Height Of A Binary Tree

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

int HeightOfTree(Node* root){

    if(root == NULL){
        return 0;
    }

    int leftheight = HeightOfTree(root->left);
    int rightheight = HeightOfTree(root->right);

    return max(leftheight,rightheight) + 1;
}

int main(){
    
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->right = new Node(6);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);

    cout<<HeightOfTree(root);

    return 0;
}