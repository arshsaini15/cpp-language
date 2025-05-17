// Sort Linked List.

#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int data){
        val = data;
        next = NULL;
    }
};

class Solution{
public:

    ListNode* getMiddle(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        if (left == NULL) return right;
        if (right == NULL) return left;

        ListNode* result = NULL;

        if(left->val <= right->val){
            result = left;
            result->next = merge(left->next, right);
        }
        else{
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    ListNode* sortList(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* middle = getMiddle(head);
        ListNode* nextOfMiddle = middle->next;

        middle->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(nextOfMiddle);

        return merge(left, right);
    }
};

int main(){

    Solution sol;
    ListNode* head = new ListNode(4);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    
    ListNode* newhead = sol.sortList(head);
    
    ListNode* temp = newhead;
    while(temp != NULL){
        cout << temp->val << "->";
        temp = temp->next; 
    }cout << "NULL";
    
    return 0;
}