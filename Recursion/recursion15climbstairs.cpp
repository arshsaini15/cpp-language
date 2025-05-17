// climb stairs question ~love babbar using recursion

#include<iostream>
using namespace std;

int n_stairs_ques(int n){

//base case
    
if(n<0){
    return 0;
}

if(n==0){
    return 1;
}

//recursive call

return n_stairs_ques(n-1) + n_stairs_ques(n-2);

}


int main(){

    int n;
    cin>>n;
 
    cout<<n_stairs_ques(n);

    return 0;
}