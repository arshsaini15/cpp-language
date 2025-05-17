// BST from preorder. II -> (in single approach)

#include<iostream>
#include<vector>
#include<climits>
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

Node* toBST(vector<int> v, int &index, int min, int maxm){
    if(index >= v.size()){
        return NULL;
    }
    if(v[index] < min || v[index] > maxm){
        return NULL;
    }

    Node* root = new Node(v[index++]);
    root->left = toBST(v,index,min,root->data);
    root->right = toBST(v,index,root->data,maxm);

    return root;
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

    int index = 0;
    Node* ans = toBST(v,index,INT_MIN,INT_MAX);

    inorder(ans);

    return 0;
}