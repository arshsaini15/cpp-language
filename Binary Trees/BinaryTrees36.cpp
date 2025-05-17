// Two Sum in a BST.

#include<iostream>
#include<vector>
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

void inorder(Node* root, vector<int>&v){
    if(root ==  NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

void TwoSum(int target, vector<int> v){
    int sum,i=0,j=v.size()-1;

    while(i<j){
        sum = v[i] + v[j];
        if(sum == target){
            cout<<v[i]<<" "<<v[j];
            break;
        }
        if(sum > target){
            j--;
        }
        else{
            i++;
        }
    }
    if(sum != target){
        cout<<"No such elements";
    }
}

int main(){

    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);

    vector<int> v;
    inorder(root,v);

    int target;
    cout<<"Enter target : ";
    cin>>target;
    
    TwoSum(target,v);

    return 0;
}