// Balanced Height In A Balanced Tree.

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

int height(Node* root){

    if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh,rh) + 1;
}

bool is_balanced(Node* root){

    if(root == NULL){
        return true;
    }

    if(is_balanced(root->left) == false){
        return false;
    }
    if(is_balanced(root->right) == false){
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh - rh) <= 1){
        return true;
    }
    return false;
}

int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(5); 

    if(is_balanced(root)){
        cout<<"Balanced Tree";
    }
    else{
        cout<<"Unbalanced Tree";
    }

    return 0;
}