// merge 2 sorted linked list using dummy node

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

node* merge(node* head1,node* head2){
    node* temp1 = head1;
    node* temp2 = head2;
    node* dummynode= new node(-1);
    node* temp3 = dummynode;

    while(temp1->next != NULL && temp2 != NULL){
        if(temp1->data >= temp2->data){
            temp3->next = temp1;
            temp1=temp1->next;
        }
        else{
            temp3->next = temp2;
            temp2=temp2->next;
        }
        temp3=temp3->next;
    }

    while(temp1!=NULL){
        temp3->next=temp1;
        temp1=temp1->next;
        temp3=temp3->next;
    }

    while(temp2!=NULL){
        temp3->next=temp2;
        temp2=temp2->next;
        temp3=temp3->next;
    }
    return dummynode->next; 
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

    node* newhead = merge(head1,head2);
    display(newhead);

    return 0;
}