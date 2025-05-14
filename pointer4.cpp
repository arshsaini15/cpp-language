#include<iostream>
using namespace std;
int main(){

    int a=10;
    int *p;
    p=&a;

    cout<<*p<<endl; // gives value of a
    cout<<p<<endl; // gives adress of a 

    int *q=&p; // pointer to pointer 

    cout<<*q<<endl; // gives adress of a
    cout<<**q<<endl; // gives value of a

    **q=20; // here we are modifying value of a 

    return 0;
}