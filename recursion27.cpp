// Check Palindrome Using Recursion but with only one pointer (i)

#include<iostream>
#include<string>
using namespace std;

bool CheckPalindrome(string &str,int i){

    int n = str.length();

    //base case
    if(i > n - 1){
        return true ;
    }

    if(str[i] != str[n-i-1]){
        return false;
    }

    //recursive call
    else{
        return CheckPalindrome(str,i+1);
    }

}


int main(){

    string str;
    cin>>str;

    bool ispalindrome = CheckPalindrome(str,0);

    if(ispalindrome){
        cout<<"Palindrome";
    }
    
    else{
        cout<<"Not";
    }

    return 0;

}