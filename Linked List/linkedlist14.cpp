// Append last k nodes to the start of linked list.

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

void insertatHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if(head != NULL){
        head->prev = n;
    }
    head = n;
}

void insertatTail(node* head, int val){
    node* n = new node(val);
    if(head == NULL){
        insertatHead(head,val);
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    temp->prev = temp;
}

int length(node* head){
    int l=0;
    node* temp = head;
    while(temp != NULL){
        l++;
        temp = temp->next;
    }
    return l;
}

node* k_append(node* head,int k){
    node* newHead;
    node* newTail;
    node* tail = head;
    
    int l=length(head);
    k=k%l;
    int count = 1;
    while(tail->next != NULL){
        if(count == l-k){
            newTail = tail;
        }
        if(count == l-k+1){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;
     
    return newHead; 
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
    insertatHead(head,1);
    insertatTail(head,2);
    insertatTail(head,3);
    insertatTail(head,4);
    insertatTail(head,5);
    insertatTail(head,6);
    
    node* newHead = k_append(head,3);
    display(newHead);

    return 0;
}