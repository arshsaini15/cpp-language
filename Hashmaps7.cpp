// Print horizontal order of a Binary Tree.

#include<iostream>
#include<queue>
#include<map>
#include<unordered_map>
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

void Get_horizontalordeR(Node* root, int hdis,  map<int, vector<int> > &m){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node != NULL){
            m[hdis].push_back(node->data);
            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(10);
    root->right = new Node(3);
    root->right->left = new Node(133);
    root->left->left = new Node(11);
    root->right->right = new Node(23);

    map<int, vector<int> > m;
    int hdis = 0;

    Get_horizontalordeR(root, hdis, m);

    // Iterate through the map to print vertical order
    for (auto it = m.begin(); it != m.end(); ++it) {
        for (int i = 0; i < (it->second).size(); ++i) {
            cout << (it->second)[i] << " ";
        }
        cout << endl;
    }

    return 0;
}