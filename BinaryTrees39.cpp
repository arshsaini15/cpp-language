// BST from preorder. I -> (Using inorder traversal)

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

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root, vector<int> &v){
    if(root == NULL){
        return;
    }

    v.push_back(root->data);
    preorder(root->left,v);
    preorder(root->right,v);
}

Node* toBST(Node* root, vector<int> v, Node* newnode){
    if(root == NULL){
        return NULL;
    }
    newnode = new Node(root->data);

    newnode->left = toBST(root->left,v,newnode);
    newnode->right = toBST(root->right,v,newnode);

    return newnode;
}

int main(){

    Node* root = new Node(20);
    root->left = new Node(10);
    root->left->left = new Node(5);
    root->left->right = new Node(13);
    root->right = new Node(35);
    root->right->left = new Node(24);

    vector<int> v;
    preorder(root,v);

    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            swap(v[i],v[j]);
        }
    }
    Node* newnode;
    Node* ans = toBST(root,v,newnode);

    inorder(ans);

    return 0;
}