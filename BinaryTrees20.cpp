// Floor of a Binary

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

int FloorOfBinaryTree(Node* root, int key){
    
    if(root == NULL){
        return -1;
    }
    if(root->data == key){
        return root->data;
    }
    if(root->data > key){
        return FloorOfBinaryTree(root->left,key);
    }
    int floor = FloorOfBinaryTree(root->right,key);

    return (floor != -1 && floor <= key) ? floor : root->data;
}


int main(){

    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right = new Node(15);

    cout<<FloorOfBinaryTree(root,7);

    return 0;
}