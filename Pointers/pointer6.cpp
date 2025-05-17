#include<iostream>
using namespace std;
void addup(int *a){
    a++;
}

int main(){
    int a=2;
   // int *aptr=&a;
    addup(&a);//address of a goes up
    cout<<a<<endl;
}