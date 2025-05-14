// Flatten a BST.

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

void inorder(Node* root, vector<Node*> &v){
    if(root == NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}

Node* FlattenBST(Node* root){

    vector<Node*> v;
    inorder(root,v);
    int n = v.size();

    Node* newRoot = new Node(v[0]->data);
    Node* curr = newRoot;

    for(int i=0;i<n;i++){
        Node* temp = new Node(v[i]->data);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

int main(){

    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);

    FlattenBST(root);

    return 0;
}