// Diameter Of A Binary Tree.

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

int CalcHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    return max(CalcHeight(root->left),CalcHeight(root->right)) + 1;
}

int DiameterOfTree(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftside = CalcHeight(root->left);
    int rightside = CalcHeight(root->right);

    int currDiameter = leftside + rightside;

    int leftDiameter = DiameterOfTree(root->left);
    int rightDiameter = DiameterOfTree(root->right);

    return max(currDiameter, max(leftDiameter,rightDiameter));

}

int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);

    root->right = new Node(5);
    root->right->right = new Node(6);

    cout<<DiameterOfTree(root);

    return 0;
}