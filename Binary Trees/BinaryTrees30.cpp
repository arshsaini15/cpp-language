// Second Way(2) : Validate BST (Tell whether a BST is valid or not).

#include<iostream>
#include<vector>
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

bool isBST(Node* root, int min, int max){
    if(root == NULL){
        return true;
    }
    if(root->data >= min && root->data <= max){
        bool left = isBST(root->left,min,root->data);
        bool right = isBST(root->right,root->data,max);
        return left && right;
    }
    else
        return false;
}

bool ValidateBST(Node* root){
    return isBST(root,INT_MIN,INT_MAX);
}

int main(){

    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);

    root->left->right = new Node(3);
    root->right = new Node(5);

    if(ValidateBST(root)){
        cout<<"Valid";
    }
    else{
        cout<<"Not valid";
    }

    return 0;
}

/*
        4
       / \
      2   5
     / \
    1   3
*/