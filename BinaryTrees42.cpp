// Make a tree using array elements.

#include<iostream>
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

Node* insert(int arr[], int n, int i){
    if(i>=n || arr[i] == -1){
        return NULL;
    }

    Node* temp = new Node(arr[i]);
    temp->left = insert(arr, n, 2 * i + 1);
    temp->right = insert(arr, n, 2 * i + 2);
    return temp;
}

void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    cout<<root->data << " ";
    printTree(root->right);
}

int main() {

    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = insert(arr, n, 0);
    cout << "Inorder : "<<" ";
    printTree(root);
    cout << endl;

    return 0;
}