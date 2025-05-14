// Convert Sorted List to Binary Search Tree.

#include <iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = nullptr;
    }
};

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;

    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

ListNode* findMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != nullptr) {
        prev->next = nullptr; // Disconnect left half from middle
    }

    return slow; // Return the middle node
}

TreeNode* sortedListToBST(ListNode* head){
    if(head == nullptr){
        return nullptr;
    }
    if(head->next == nullptr){ 
        return new TreeNode(head->val);
    }

    ListNode* mid = findMiddle(head);
    TreeNode* root = new TreeNode(mid->val);

    root->left = sortedListToBST(head); // Left half
    root->right = sortedListToBST(mid->next); // Right half

    return root;
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){

    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);

    TreeNode* root = sortedListToBST(head);
    inorder(root);

    return 0;
}
