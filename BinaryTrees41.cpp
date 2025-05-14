// Merge Two BST'z.

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

void inorder(Node* root, vector<int> &v){
    if(root == NULL){
        return;
    }

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

vector<int> Merge(vector<int> v1, vector<int> v2){
    if(v1.size() == 0){
        return v1;
    }
    if(v2.size() == 0){
        return v2;
    }
    
    vector<int> v3;
    int i = 0, j = 0;

    while(i < v1.size() && j < v2.size()) {
        if(v1[i] < v2[j]) {
            v3.push_back(v1[i]);
            i++;
        } 
        else{
            v3.push_back(v2[j]);
            j++;
        }
    }

    while(i < v1.size()) {
        v3.push_back(v1[i]);
        i++;
    }

    while(j < v2.size()) {
        v3.push_back(v2[j]);
        j++;
    }

    return v3;
}

Node* toBST(vector<int> v, Node* &root, int s, int e){
    if(s>e){
        return NULL;
    }
    
    int mid = (s+e)/2;
    root = new Node(v[mid]); 

    root->left  = toBST(v,root->left,s,mid-1);
    root->right = toBST(v,root->right,mid+1,e);

    return root;
}

int main(){

    Node* root1 = new Node(20);
    root1->left = new Node(10);
    root1->left->left = new Node(5);
    root1->left->right = new Node(13);
    root1->right = new Node(35);
    root1->right->left = new Node(24);

    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->left->left = new Node(1);
    root2->left->right = new Node(3);
    root2->right = new Node(5);

    vector<int> v1,v2;

    inorder(root1,v1);
    inorder(root2,v2);

    vector<int> v = Merge(v1,v2);

    Node* root3 = NULL;
    toBST(v,root3,0,v.size()-2);

    return 0;
}