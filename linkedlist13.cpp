// deletion in linked list ...!

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

void insertat_head(node* &head, int val){
    node* n = new node(val);
    n->next = head;

    if(head != NULL){
        head->prev = n;
    } 
    head = n;
}

void insertat_tail(node* &head, int val){
    
    node* n = new node(val);
    if(head == NULL){
        insertat_head(head,val);
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    temp->prev = temp;
}

void deleteat_Head(node* &head){
    
    node* todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}

void deletion(node* head, int key){
    node* temp = head;
    int count = 1;
    while(temp != NULL && count < key){
        temp = temp->next;
        count++;
    }
    
    node* todelete = temp;
    
    if(count == key){ 
        temp->prev->next = temp->next;
        if(temp->next != NULL){
            temp->next->prev = temp->prev;
        }
    }
    delete todelete;
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
    insertat_tail(head,2);
    insertat_tail(head,3);
    insertat_head(head,1);
    insertat_head(head,4);
    insertat_head(head,5);
    deletion(head,2);
    display(head);

    return 0;
}