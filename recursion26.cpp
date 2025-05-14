// check palindrome using recursion

#include<iostream>
#include<string>
using namespace std;

bool CheckPalindrome(string &str,int i,int j){

    //base case
    if(i>j){
        return true;
    }

    if(str[i] != str[j]){
        return false;
    }

    //recursive call
    else{
        return CheckPalindrome(str,i+1,j-1);
    }

}


int main(){

    string str;
    cin>>str;

    int j = str.length() - 1;

    bool isPalindrome = CheckPalindrome(str,0,j);

    if(isPalindrome){
        cout<<"palindrome"<<endl;
    }
    else{
        cout<<"not";
    }

    return 0;

}