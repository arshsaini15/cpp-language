// Put even elements after odd elements in linked list

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void even_after_odd(node* &head){
    node* odd=head;
    node* even=head->next;
    node* evenstart=even;
    while(odd->next != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenstart;
    if(odd->next == NULL){
        even->next = NULL;
    }
}

void insertathead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

void insertattail(node* head,int val){
    node* n= new node(val);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}

int main(){
    node* head=NULL;
    insertathead(head,3);
    insertathead(head,2);
    insertathead(head,1);
    insertattail(head,4);
    insertattail(head,5);
    display(head);

    even_after_odd(head);
    display(head);

    return 0;
}