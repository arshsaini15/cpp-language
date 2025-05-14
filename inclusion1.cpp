#include<iostream>
using namespace std;

int gcd(int a,int b){
    
    int rem=1;

    while(rem!=0){
    rem=a%b; 
    a=b;
    b=rem;
    }
    return a;

}

int main(){

    int n1,n2;
    cin>>n1>>n2;

    cout<<gcd(n1,n2);
    return 0;
}