// Merge Two Binary Trees.

#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* mergeTwoTrees(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return NULL;
    }

    int val = (root1 ? root1->data : 0) + (root2 ? root2->data : 0);
    Node* root = new Node(val);

    root->left = mergeTwoTrees(root1 ? root1->left : NULL, root2 ? root2->left : NULL);
    root->right = mergeTwoTrees(root1 ? root1->right : NULL, root2 ? root2->right : NULL);

    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){

    Node* root1 = new Node(5);
    root1->left = new Node(1);
    root1->right = new Node(2);
    root1->left->left = new Node(3);

    Node* root2 = new Node(9);
    root2->left = new Node(1);
    root2->right = new Node(2);
    root2->left->left = new Node(6);
    root2->left->right = new Node(2);

    Node* root = mergeTwoTrees(root1, root2);
    inorder(root);

    return 0;
}