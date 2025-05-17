// k-largest (Also solve using vector)

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

void inorder(Node* root,queue<int> &q){
    if(root == NULL){
        return;
    }
    inorder(root->left,q);
    cout<<root->data<<" ";
    q.push(root->data);
    inorder(root->right,q);
}

int main(){

    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);

    int key;
    cout<<"Enter Key : ";
    cin>>key;

    queue<int> q;
    inorder(root,q);
    cout<<endl;

    while(!q.empty()){
        if(q.size() == key){
            cout<<q.front();
        }
        q.pop();
    }

    return 0;
}