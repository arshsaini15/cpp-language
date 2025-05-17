// Kth Smallest/Largest Element.

#include<iostream>
#include<queue>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = NULL;
    }
};

void Smallest(Node* root, int idx){
    if(root == NULL){
        return;
    }

    queue<int> q1;
    q1.push(root);

    while(!q.empty()){        
        Node* node = q1.front();
        
        if(node != NULL){
            if(node->left){
                q1.push(node->left->data);
            }
            if(node->right){
                q1.push(node->right->data);
            }
        }
    }
    queue<int> q2;
    while(!q1.empty()){
        q2.push(q1.front());
    }
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(10);
    root->right->left = new Node(6);

    Smallest(root, 2);

    return 0;
}