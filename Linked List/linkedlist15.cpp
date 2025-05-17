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

void insertathead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if(head!=NULL){
        head->prev = NULL;
    }
    head = n;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){

    node* head = NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insertathead(head,arr[i]);
    }
    display(head);

    return 0;
}