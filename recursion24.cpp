// Reverse a string using recursion with 2 variables

#include<iostream>
#include<string>
using namespace std;

void reverse(string &str,int i,int j){
    //base case
    if(i>j){
        return; 
    }

    //processing
    swap(str[i],str[j]);
    i++;
    j--;

    //recursive call
    reverse(str,i,j);

}


int main(){

    string str;
    getline(cin,str);

    /*reverse(str.begin(),str.end());
    cout<<str;*/

    reverse(str,0,str.length()-1);
    cout<<str;

    return 0;
}