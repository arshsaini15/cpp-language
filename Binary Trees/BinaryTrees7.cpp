// Sum of all the nodes in a Binary Tree (Without Recursion).

#include<iostream>
#include<queue>
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

int SumOfNodes(Node* root){
    
    int sum = root->data;

    if(root == NULL){
        return -1;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        if(node != NULL){
            if(node->left != NULL){
                q.push(node->left);
                sum += node->left->data;
            }
            if(node->right != NULL){
                q.push(node->right);
                sum += node->right->data;
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
    return sum;
}

int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<SumOfNodes(root);

    return 0;
}