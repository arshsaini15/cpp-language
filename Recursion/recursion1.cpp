// sum using recursion

#include<iostream>
using namespace std;

int sum (int n){

    if(n==0){
        return 0;
    }

    int prevsum = sum(n-1); // recursion
    return n + prevsum;

}

int main(){

    int n;
    cin>>n;

    cout<<sum(n);
    return 0; 
}