#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;

    node(int x){
        val = x;
        next = NULL;
    }
};

int main(){

    node* n = new node(1); // contructor n is created.
    
    cout << n->val <<" " << n->next;

    // 0X0 in answer is address of NULL.

    return 0;
}