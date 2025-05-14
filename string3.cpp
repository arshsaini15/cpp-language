#include<iostream>
#include<string>
using namespace std;
int main(){


    string s1="fam";
    string s2="ily";

    s1.append(s2); // first method to add two strings
    cout<<s1<<endl;


    s1=s1+s2;// second method to add two strings
    cout<<s1<<endl;
    return 0;

}