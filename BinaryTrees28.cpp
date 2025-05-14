// Second Way(1) : Validate BST (Tell whether a BST is valid or not).

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

void inorder(Node* root ,vector<int> &v){
    if(root == NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

// int count(Node* root){
//     if(root == NULL){
//         return 0;
//     }
//     return count(root->left) + count(root->right) + 1;
// }

bool check(vector<int> v){
    for(int i=0;i<v.size()-1;i++){
        if(v[i]>v[i+1]){
            return false;
        }
    }
    return true;
}

int main(){

    Node* root = new Node(4);
    root->left = new Node(1);
    root->left->left = new Node(1);

    root->left->right = new Node(3);
    root->right = new Node(5);

    // int n = count(root);
    vector<int> v;
    inorder(root,v);

    if(check(v)){
        cout<<"Valid";
    }
    else{
        cout<<"Not Valid";
    }
    return 0;
}

/*
        4
       / \
      2   5
     / \
    1   3
*/