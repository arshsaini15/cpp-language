// Maximum Path Sum : Maximum possible sum of a path in a binary tree, starting and ending at any node.

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int maxpathsumUtil(Node *root, int &ans){
    if(root == NULL){
        return 0;
    }

    int leftsum = maxpathsumUtil(root->left, ans);
    int rightsum = maxpathsumUtil(root->right, ans);

    int nodemax = max(max(root->data, root->data + leftsum + rightsum),
                      max(root->data + leftsum, root->data + rightsum));

    ans = max(ans, nodemax);

    int singlePathSum = max(root->data, max(root->data + leftsum, root->data + rightsum));

    return singlePathSum;
}

int MSP(Node *root){
    int ans = INT_MIN;
    maxpathsumUtil(root, ans);
    return ans;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(-12);
    root->left->left = new Node(4);

    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(-6);

    cout << MSP(root);

    return 0;
}