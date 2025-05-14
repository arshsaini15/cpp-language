// Convert Binary Tree into BST.

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

void inorder(Node* root,vector<int> &v){
    if(root == NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

Node* ConvertToBST(Node* &temp, vector<int> &v, int s, int e){

    if(s>e){
        return NULL;
    }
    
    int mid = (s+e)/2;
    temp = new Node(v[mid]);

    temp->left = ConvertToBST(temp->left, v, s, mid - 1);
    temp->right = ConvertToBST(temp->right, v, mid + 1, e);

    return temp;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left = new Node(5);
    root->right->left->left = new Node(7);

    vector<int>v;
    inorder(root,v);

    cout<<endl;

    sort(v.begin(),v.end());
    Node* temp = NULL;
    ConvertToBST(temp,v,0,v.size()-2);

    inorder(temp,v);

    return 0; 
}