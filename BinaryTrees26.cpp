// Binary Search Tree searching.

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

Node* searchinBST(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(root->data > key){
        return searchinBST(root->left,key);
    }
    return searchinBST(root->right,key);
}

int main(){

    Node* root = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(1);

    root->right = new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(4);

    if(searchinBST(root,5) == NULL){
        cout<<"don't exist";
    }
    else{
        cout<<"exists";
    }

    return 0;
}