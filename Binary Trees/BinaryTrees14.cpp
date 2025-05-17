// Right View Of A Binary Tree. 

#include<iostream>
#include<queue>
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

void RightView(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n=q.size();
        Node* curr = NULL;

        for(int i=0;i<n;i++){
            curr = q.front();
            q.pop();
            if(i == n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
}

int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);

    root->right = new Node(3);
    root->right->right = new Node(6);

    root->right->left = new Node(5);
    root->right->left->left = new Node(7);

    RightView(root);

    return 0;
}