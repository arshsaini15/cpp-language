// merge using recursion

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
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}

void insertattail(node* head,int val){
    node* n = new node(val);
    if(head == NULL){
        insertathead(head,val);
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    } 
    temp->next=n;
    n->prev=temp;
}

node* merge_recursive(node* head1,node* head2){
   
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
   
    node* result;
    if(head1->data < head2->data){
        result = head1;
        result->next = merge_recursive(head1->next,head2);
    }
    else{
        result=head2;
        result->next = merge_recursive(head1,head2->next);
    }
    return result;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}

int main(){
    node* head1=NULL;
    node* head2=NULL;

    int arr1[4]={1,2,3,4};
    for(int i=0;i<4;i++){
        insertathead(head1,arr1[i]);
    }

    int arr2[3]={5,6,7};
    for(int i=0;i<3;i++){
        insertattail(head2,arr2[i]);
    }

    display(head1);
    display(head2);

    node* newhead = merge_recursive(head1,head2);
    display(newhead);

    return 0;
}