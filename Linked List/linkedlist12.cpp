// doubly Linked List ...!!!

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertat_Head(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    
    if(head != NULL){
        head->prev = n;
    }
    head = n;
}

void insertat_Tail(node* &head,int val){
    
    if(head == NULL){
        insertat_Head(head,val);
        return;
    }

    node* n = new node(val);
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    temp->prev = temp;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main(){

    node* head = NULL;
    insertat_Tail(head,10);
    insertat_Tail(head,20);
    insertat_Tail(head,30);
    insertat_Tail(head,40);
    display(head);
  
    return 0;
}