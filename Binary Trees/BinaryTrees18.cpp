// Nodes At Distance K In Binary Tree.

/*
Steps:
1. Count Node's Subtree.
2. Count Ancestor's Subtree.
*/

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

// Case 1:
void PrintSubtreeNodes(Node* root, int k){
    if(root == NULL || k<0){
        return;
    }
    if(k == 0){
        cout<<root->data<<" ";
    }

    PrintSubtreeNodes(root->left,k-1);
    PrintSubtreeNodes(root->right,k-1);
}

// Case 2:
int NodesAtK(Node* root, Node* target, int k){
    if(root ==  NULL){
        return -1;
    }
    if(root == target){
        PrintSubtreeNodes(root,k);
        return 0;
    }

    int dl = NodesAtK(root->left,target,k);
    if(dl != -1){
        if(dl + 1 == k){
            cout<<root->data<<" ";
        }
        else{
            PrintSubtreeNodes(root->right,k-dl-2);
        }
        return 1+dl;
    }

    int dr = NodesAtK(root->right,target,k);
    if(dr != -1){
        if(dr + 1 == k){
            cout<<root->data<<" ";
        }
        else{
            PrintSubtreeNodes(root->left,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(5);
    root->left->left = new Node(6);
    root->left->left->right = new Node(7);
    root->left->left->right->left = new Node(8);
    root->left->left->right->right = new Node(9);
    root->right = new Node(2);
    root->right->left = new Node(3);
    root->right->right = new Node(4);

    NodesAtK(root,root->left,3);

    return 0;
} 