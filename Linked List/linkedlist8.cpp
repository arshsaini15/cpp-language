// Reversing K nodes at a same time.

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

node* reverse(node* &head,int k){
    node* prevptr = NULL;
    node* currptr = head; 
    node* nxtptr;
    int count = 0;
    while(currptr != NULL && count<k){
        nxtptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nxtptr;
        count++;
    }
    if(head != NULL){
        head->next = reverse(nxtptr,k);
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
    insertathead(head,40);
    insertathead(head,50);
    insertathead(head,60);
    // display(head);
    int k = 2;
    node* newhead = reverse(head,k);
    display(newhead);
    
    return 0;
}