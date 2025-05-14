// k-smallest element - (inorder traversal).
// Also solve using vector

#include<iostream>
#include<queue>
#include<stack>
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

void inorder(Node* root, stack<int> &st){
    if(root == NULL){
        return;
    }
    inorder(root->left,st);
    cout<<root->data<<" ";
    st.push(root->data);
    inorder(root->right,st);
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

    stack<int> st;
    int key;
    cout<<"Enter Key : ";
    cin>>key;

    inorder(root,st);

    cout<<endl;

    while(!st.empty()){
        if(st.size() == key){
            cout<<st.top();
        }
        if(st.size() < key){
            cout<<"Key is greater than size of Tree";
            break;
        }
        st.pop();
    }

    return 0;
}