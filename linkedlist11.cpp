// reording a linked list // still pending...

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

void insertathead(node* &head,int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

node* display(node* head){
    
    node* start = head;
    node* end = head;
    node* nxtptr;

    while(end->next != NULL){
        end = end->next;
    }
    while(start != NULL && end != NULL){
        nxtptr = start->next;
        end->next;
        start->next = end;
        start = start->next;

    }
    return start;
}

int main(){

    node* head = NULL;
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,3);
    insertathead(head,4);
    display(head);

    return 0;
}