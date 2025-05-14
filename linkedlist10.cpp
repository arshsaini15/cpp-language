// remove a cycle in floyd's algo.

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

void insertatTail(node* &head,int val){
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

void makecycle(node* head, int pos){
    node* temp = head;
    node* startnode;

    int count = 1;
    while(temp->next != NULL){
        if(count == pos){
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    if(temp->next == NULL){
        temp->next = startnode;
    }
    // temp->next = startnode;
}

void remove_cycle(node* head) {
    node* fast = head;
    node *slow = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    } while(slow != fast);

    fast = head;
    while(slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

bool floyds_algo(node* &head) {
    node* fast = head;
    node* slow = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            return true;
        }
    }
    return false;
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
    insertatTail(head,1);
    insertatTail(head,2);
    insertatTail(head,3);
    insertatTail(head,4);
    insertatTail(head,5);
    insertatTail(head,6);

    makecycle(head,3);
    cout<<floyds_algo(head)<<endl;
    remove_cycle(head);
    cout<<floyds_algo(head)<<endl;
    display(head);

    return 0;
}