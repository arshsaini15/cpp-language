//replace all zeros with five;



#include<iostream>
using namespace std;

int reverse(int n){
    int sum = 0;
    while(n>0){
        int digit = n%10;
        sum = (sum * 10) + digit;
        n = n/10;
    }
    return sum;
}

int changing_Zero(int n){

    if(n==0){
        return 5;
    }

    int sum = 0;
    while(n>0){

        int digit  = n%10;
        if(digit == 0){
            digit = 5;
        }
        sum = (sum * 10) + digit;
        n = n/10;
    }
    return reverse(sum);
}

int main(){

    int n;
    cin>>n;

    cout<<changing_Zero(n);

    return 0;
}