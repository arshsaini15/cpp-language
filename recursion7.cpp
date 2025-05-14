// print decending order using recursion

#include<iostream>
using namespace std;

void dec(int n){

    if(n==0){
        return;
    }

    else{
    cout<<n<<" ";
    dec(n-1);
}
}

int main(){

    int n;
    cin>>n;

    dec(n);
    
    return 0;
}