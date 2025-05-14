// Build Tree From Preorder and Inorder.

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

int search(int inorder[], int s, int e, int curr){
    for(int i=0;i<=e;i++){
        if(curr == inorder[i]){
            return i;
            break;
        }
    }
    return -1;
}

void inorder_print(Node* root){
    if(root==NULL){
        return;
    }

    inorder_print(root->left);
    cout<<root->data<<" ";
    inorder_print(root->right);
}

Node* buildtree(int preorder[], int inorder[], int s, int e){
    static int idx = 0;
    if(s>e){
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);

    if(s == e){
        return node;
    }

    int pos = search(inorder,s,e,curr);
    node->left = buildtree(preorder, inorder, s, pos-1);
    node->right = buildtree(preorder, inorder, pos+1 ,e);

    return node;
}

int main(){

    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    // Build Tree
    Node* root = buildtree(preorder, inorder, 0, 4);
    inorder_print(root);

    return 0;
}