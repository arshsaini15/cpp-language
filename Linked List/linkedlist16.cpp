// Intersection of 2 linked lists

#include<iostream>
using namespace std;

class node{
    public:
    int  data;
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
    if(head != NULL){
        head->prev = n;
    }
    head = n;
}

void insertattail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        insertathead(head,val);
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;
    temp->prev = temp;
}

void intersect(node* &head1, node* &head2, int pos){
    node* temp1 = head1;
    int count=1;
    while(count<pos){
        temp1=temp1->next;
        count++;
    }
    /*  or~
    pos--;
    while(pos--){
        temp1=temp1->next;
    }*/    
    node* temp2=head2;
    while(temp2->next != NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

int length(node*head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        l++;
    }return l;
}

int intersection(node* head1,node* head2){
    int l1=length(head1);
    int l2=length(head2);

    int diff=0;
    node* ptr1;
    node* ptr2;

    if(l1>l2){
        diff=l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        diff=l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while(diff){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        diff--;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1 == ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

int main(){
    node* head1 = NULL;
    node* head2 = NULL;
    insertattail(head1,1);
    insertattail(head1,2);
    insertattail(head1,3);
    insertattail(head1,4);
    insertattail(head1,5);
    insertattail(head1,6);
    insertattail(head2,9);
    insertattail(head2,10);
    
    intersect(head1,head2,3);
    display(head1);
    display(head2);
    cout<<intersection(head1,head2)<<endl;

    return 0;
}