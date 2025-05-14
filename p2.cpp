#include<iostream>
#include<queue>
using namespace std;

struct Node {
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);

    cout << endl;
}

int heightOfTree(Node* root) {
    if(root == NULL) return 0;

    return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
}

void leftView(Node* root) {
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();
        for(int i=1; i<=n; i++) {
            Node* curr = q.front();
            q.pop();

            if(i == 1) {
                cout << curr->val << " ";
            }
            if(curr->left != NULL) {
                q.push(curr->left);
            }
            if(curr->right != NULL) {
                q.push(curr->right);
            }
        }
    }
}

bool areIdentical(Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL || root2 == NULL) return false;

    return (root1->val == root2->val) &&
        areIdentical(root1->left, root2->left) &&
        areIdentical(root1->right, root2->right);
}

void mirrorTree(Node* root) {
    if(root == NULL) return;

    mirrorTree(root->left);
    mirrorTree(root->right);

    swap(root->left, root->right);
}

bool isSymmetrical(Node* LEFT, Node* RIGHT) {
    if(LEFT == NULL && RIGHT == NULL) return true;
    if(LEFT == NULL || RIGHT == NULL || LEFT->val != RIGHT->val) return false;

    return isSymmetrical(LEFT->left, RIGHT->right) &&
            isSymmetrical(LEFT->right, RIGHT->left);
}

int Diameter(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int lHeight = heightOfTree(root->left);
    int rHeight = heightOfTree(root->right);

    int lDiameter = Diameter(root->left);
    int rDiameter = Diameter(root->right);

    return max({lHeight + rHeight, lDiameter, rDiameter});
}

int main() {

    Node* root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(4);
    root->left->left = new Node(11);
    root->left->right = new Node(12);
    
    Node* root1 = new Node(5);
    root1->left = new Node(6);
    root1->right = new Node(4);
    root1->left->left = new Node(11);
    root1->left->right = new Node(12);

    // inorder(root);
    // cout << heightOfTree(root);
    // leftView(root);
    // cout << areIdentical(root, root1);
    // mirrorTree(root);
    // cout << isSymmetrical(root->left, root->right);
    // cout << Diameter(root);

    return 0;
}