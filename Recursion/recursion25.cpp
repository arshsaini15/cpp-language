// Reverse a string using recursion with 1 variable 

#include<iostream>
#include<string>
using namespace std;

void reverse(string &str , int i){

    int n = str.length();

    //base case
    if(i > n/2){
        return;
    }

    //processing
    swap(str[i] , str[n-i-1]);
    i++;

    //recursive call
    reverse(str,i);

}

int main(){

    string str;
    cin>>str;

    int i = 0;

    reverse(str,i);

    cout<<str;

    return 0;

}