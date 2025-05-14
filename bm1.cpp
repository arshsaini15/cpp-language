#include<iostream>
using namespace std;

int getbit(int n,int pos){
    return ((n&(1<<pos))!=0);
}
// here left shift operator means (1<<1) is equal to
//  1* pow(2,1)

int main(){

    cout<<getbit(5,2);
    return 0;
}