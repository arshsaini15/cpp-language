#include<iostream>
using namespace std;
    
int clearbit(int n,int pos){
    int mask = 1<<pos;
    mask = ~mask;
    return (n & mask);
}

int main(){
cout<<clearbit(5,2);
return 0;
}