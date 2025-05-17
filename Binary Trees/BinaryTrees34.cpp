// Prodecessor and Successor in BST.

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

void inorder(Node* root, vector<int> &v){
    if(root == NULL){
        return;
    }

    inorder(root->left,v);
    cout<<root->data<<" ";
    v.push_back(root->data);
    inorder(root->right,v);
}

int main(){

    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);

    int key;
    cout<<"Enter key : ";
    cin>>key;

    vector<int>v;
    inorder(root,v);
    cout<<endl;

    for(int i=0;i<v.size();i++){
        if(v[i] == key){
            cout<<v[i-1]<<" "<<v[i+1];
        }
    }
    
    return 0;
}