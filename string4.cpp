#include<iostream>
#include<string>
using namespace std;
int main(){

    string s1="fam";
    string s2="ily";

    cout<<s1[2]<<endl; // indexing in strings is same as arrays

    string abc="abcdefghijklmnopqrstuvwxyz";
    abc.clear(); // destroyes the material inside the strings

    cout<<abc;

    string s3="abc";
    string s4="xyz";
    cout<<s4.compare(s3)<<endl; // compares size os strings

    s3.clear();

    if(s3.empty()){
        cout<<"string is empty";
    }
  

    return 0;
}