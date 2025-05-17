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
    
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,3);

    display(head);

    return 0;
}