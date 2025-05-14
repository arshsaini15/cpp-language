// Rotate list (Singly linked list).

#include<iostream>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;

    ListNode(int val){
        data = val;
        next = NULL;
    }
};

class Solution {
    int length(ListNode* head){
        ListNode* temp = head;
        int l = 0;
        while(temp != NULL){
            temp = temp->next;
            l++;
        }
        return l;
    }

public:
    ListNode* rotateRight(ListNode* head, int k){
        if(!head || !head->next || k == 0) return head;

        int len = length(head);
        k = k % len;
        if(k == 0) return head;

        ListNode* temp = head;
        for(int i = 1; i < len - k; i++){
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;

        ListNode* curr = newHead;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = head;

        return newHead;
    }
};

int main(){

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    Solution sol;
    ListNode* newhead = sol.rotateRight(head, 2);
    ListNode* temp = newhead;

    while(temp != NULL){
        cout << temp->data <<"->";
        temp = temp->next;
    }cout << "NULL";

    return 0;
}