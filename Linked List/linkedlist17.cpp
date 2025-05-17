// Merge 2 sorted linked list

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

void insertathead(node* &head,int val){
    node* n = new node(val);
    n->next = head;
    if(head!=NULL){
        head->prev = n;
    }
    head = n;
}

int length(node* head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        l++;
    }return l;
}

void merge(node* head1, node*head2){
    node* temp1 = head1;
    node* temp2 = head2;

    int l1 = length(head1);
    int l2 = length(head2);
    
    if(l1>l2){
        while(temp2->next != NULL){
        temp2=temp2->next;
        }
        temp2->next=temp1;
    }
    else{
        while(temp1->next != NULL){
        temp1=temp1->next;
        }
        temp1->next=temp2;
    }
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){

    node* head1 = NULL;
    insertathead(head1,3);
    insertathead(head1,2);
    insertathead(head1,1);
    display(head1);

    node* head2 = NULL;
    insertathead(head2,6);
    insertathead(head2,5);
    insertathead(head2,4);
    display(head2);

    merge(head1,head2);
    display(head1);

    return 0;
}