// Sum of all nodes of Binary Trees (Using Recursion).

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

int SumOfNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return SumOfNodes(root->left) + SumOfNodes(root->right) + root->data;
}

int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    cout<<SumOfNodes(root);

    return 0;
}