// First Way : Validate BST (Tell whether a BST is valid or not).

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool ValidateBST(Node* root){
    if(root == NULL){
        return true;
    }
     if(root->left != NULL && root->left->data >= root->data){
        return false;
    }
    if(root->right != NULL && root->right->data <= root->data){
        return false;
    }
    return ValidateBST(root->left) && ValidateBST(root->right);
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
        cout<<"Not Valid";
    }

    return 0;
}