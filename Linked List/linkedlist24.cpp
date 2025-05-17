#include<iostream>
#include<vector>
#include<algorithm>
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

class Solution{
public:

    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.empty()) return nullptr;

        ListNode* head = lists[0];
        ListNode* temp = head;

        for(int i = 1; i < lists.size(); i++){
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = lists[i];
        }

        vector<int> values;
        temp = head;
        while(temp != NULL){
            values.push_back(temp->val);
            temp = temp->next;
        }

        sort(values.begin(), values.end());

        temp = head;
        for(int val : values){
            temp->val = val;
            temp = temp->next;
        }

        return head;
    }

    void printlist(ListNode* head){
        if(head == NULL) return;
        
        ListNode* temp = head;
        while(temp != NULL){
            cout << temp->val << "->";
            temp = temp->next;
        }cout <<"NULL";
    }
};

int main(){

    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);

    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(9);

    ListNode* head3 = new ListNode(4);
    head3->next = new ListNode(5);
    head3->next->next = new ListNode(2);

    vector<ListNode*> lists = {head1, head2, head3};

    Solution sol;
    ListNode* head = sol.mergeKLists(lists);
    sol.printlist(head);

    return 0;
}
