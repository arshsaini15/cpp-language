// Print Vertical Order of a Bianry Tree.

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void Get_verticalordeR(Node* root, int hdis, map<int,vector<int> > &m){
    if(root == NULL){
        return;
    }
    m[hdis].push_back(root->data);
    Get_verticalordeR(root->left,hdis-1,m);
    Get_verticalordeR(root->right,hdis+1,m);
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

    Get_verticalordeR(root, hdis, m);

    // Iterate through the map to print vertical order
    for (auto it = m.begin(); it != m.end(); ++it) {
        for (int i = 0; i < (it->second).size(); ++i) {
            cout << (it->second)[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
