// Reverse a linked list using recursion.

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertathead(node* &head, int val){
    node *n = new node(val);
    n->next = head;
    head = n;
}

node* recursive_reverse(node* &head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    node* newhead = recursive_reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


int main(){

    node* head = NULL;
    insertathead(head,10);
    insertathead(head,20);
    insertathead(head,30);
    display(head);
    node* newhead = recursive_reverse(head);
    display(newhead);
    
    return 0;
}