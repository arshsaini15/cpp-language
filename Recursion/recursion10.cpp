// factorial using recursion

#include<iostream>
using namespace std;

int factorial(int n){


    //base case
    if(n==0){
        return 1;
    }

    int s = factorial(n-1);
    int b = n*s;

    return b;

}



int main(){

    int n;
    cin>>n;

    int ans = factorial(n);
    
    cout<<ans;

    return 0;
}