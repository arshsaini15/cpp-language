// Reverse a linked list.

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

node* reverse(node* &head){
    node* prevptr = NULL;
    node* currptr = head; 
    node* nxtptr;
    while(currptr != NULL){
        nxtptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nxtptr;
    }
    return prevptr;
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
    node* newhead = reverse(head);
    display(newhead);
    
    return 0;
}