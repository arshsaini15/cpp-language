//  delete a Node in BST. 

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

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* minVal(Node* root){
    if(root == NULL){
        return NULL;
    }
    return minVal(root->left);
}

Node* delete_inBST(Node* root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->data > val){
        root->left = delete_inBST(root->left,val);
        return root;
    }
    else if(root->data < val){
        root->right = delete_inBST(root->right,val);
        return root;
    }
    else{
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
        }

        // 1 child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = delete_inBST(root->right,mini);
        }
    }
    return root;
}

int main(){

    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);
    root->right->right = new Node(6);

    inorder(root);
    cout<<endl;
    root = delete_inBST(root,5);
    inorder(root);

    return 0;
}