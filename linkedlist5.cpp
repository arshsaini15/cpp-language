// delete at head and tail and deletion of any element in linked list

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

void insertatHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertattail(node* head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void delete_athead(node* &head){
    node* temp = head;
    head = head->next;
    delete temp;
}

void delete_attail(node* head){
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = NULL;
    delete todelete;
}

void deletion(node* head,int val){
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        delete_athead(head);
    }
    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
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
    insertatHead(head,20);
    insertatHead(head,10);
    insertattail(head,30);
    insertattail(head,40);
    insertattail(head,50);
    // delete_athead(head);
    // delete_attail(head);

    deletion(head,30);
    display(head);

    return 0;
}