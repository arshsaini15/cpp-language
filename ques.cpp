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

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void Find_Node(Node* &root, int k){
    
    if(root == NULL){
        return;
    }

    if(root->data == k){
        Node* temp = root;
        if(root->left){
            delete root;
            root->left = root->left->left;
        }
        else if(root->right){
            delete root->right;
            root->right = root->right->right;
        }
    }

    Find_Node(root->left,k);
    Find_Node(root->right,k);
}

Node* dlt(Node* &root, int k){
    if(root == NULL){
        return NULL;
    }

    Find_Node(root, k);
    return root;
}

int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    inorder(root);
    cout<<endl;
    dlt(root,2);
    inorder(root);

    return 0;
}