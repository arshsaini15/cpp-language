// insertion at head and tail

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
    
void insertatTail(node* head, int val){
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

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(node* head, int key){
    node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){

    node* head = NULL;

    insertatTail(head,1);
    insertatTail(head,2);
    insertatTail(head,3);
    display(head);

    insertatHead(head,4);
    display(head);

    cout<<search(head,5);

    return 0;
}