// Build Tree from postorder and inorder. 

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

int search(int inorder[], int s, int e, int curr){
    for(int i=s;i<=e;i++){
        if(curr == inorder[i]){
            return i;
            break;
        }
    }
    return -1;
}

void inorder_print(Node* root){
    if(root == NULL){
        return;
    }
    inorder_print(root->left);
    cout<<root->data<<" ";
    inorder_print(root->right);
}

Node* buildTree(int postorder[], int inorder[], int s, int e){
    static int idx = 4;
    if(s>e){
        return NULL;
    }
    int curr = postorder[idx];
    idx--;
    Node* node = new Node(curr);

    if(s==e){
        return node;
    }

    int pos = search(inorder,s,e,curr);
    node->right = buildTree(postorder, inorder, pos+1, e);
    node->left = buildTree(postorder, inorder, s, pos-1);

    return node;
}

int main(){
    
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};

    Node* root = buildTree(postorder, inorder,0,4);
    inorder_print(root);

    return 0;
}