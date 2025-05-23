// Left View Of A Binary Tree.

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

void LeftView(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n=q.size();
        for(int i=1;i<=n;i++){
            Node* temp = q.front();
            q.pop();

            if(i == 1){
                cout<<temp->data<<" ";
            }
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
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

    LeftView(root);

    return 0;

}