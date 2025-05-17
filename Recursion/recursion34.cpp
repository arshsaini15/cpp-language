// subsequences of a string using recursion

#include<iostream>
#include<string>
using namespace std;

void substr(string str, int n, int index,int ans){

    //base case
    if(index >= n){
        
    }

    // exclude
    substr(str,n,index+1,ans);

    // include
    char element = str[index];
    
    substr(str,n,index+1,ans);
}


int main(){

    string str;
    int len = str.length();
    int index = 0;
    int ans;

    substr(str,len,index,ans);

    return 0;
}