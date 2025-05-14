// Convert BST to min-heap.

#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root, vector<int> &v){
    if(root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

Node* bstToMinheap(vector<int> v, int &index){
    if(index >= v.size()) return NULL;

    Node* newNode = new Node(v[index++]);
    newNode->left = bstToMinheap(v, index);
    newNode->right = bstToMinheap(v, index);

    return newNode;
}

void inorderPrint(Node* root){
    if(root == NULL) return;

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main(){

    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    vector<int> v;
    inorder(root, v);

    int index = 0;
    Node* newNode = bstToMinheap(v, index);
    inorderPrint(newNode);

    return 0;
}