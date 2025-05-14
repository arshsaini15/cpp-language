// k-smallest element.

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

int Find_Ksmallest(queue<int>q, int k){
    int s = q.size();
    int n = k-s;
    int i = 0;

    while(!q.empty()){
        if(i<=n){
            q.pop();
            i++;
        }
    }
    return q.front();
}

int k_smallest(Node* root , queue<int> q, int k) {
    if(root ==  NULL){
        return  -1;
    }
    q.push(root->data);
    k_smallest(root->left,q,k);
    k_smallest(root->right,q,k);

    return Find_Ksmallest(q, k);
}

int main(){

    Node* root = new Node(5);
    root->left = new Node(4);
    root->left->left = new Node(2);
    root->left->left->right = new Node(3);

    root->right = new Node(8);
    root->right->right = new Node(10);
    root->right->left = new Node(6);
    root->right->left->right = new Node(7);

    queue<int>q;
    k_smallest(root,q,2);

    return 0;
}