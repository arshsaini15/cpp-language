#include<iostream>
#include<string>
using namespace std;
int main(){

    string s1,s2,s3,s4;
    getline(cin,s1);
    getline(cin,s2);
    getline(cin,s3);
    getline(cin,s4);


    for(int i=0;i<s1.size();i++){
        if((s1[i]==s2[i])&&(s2[i]==s3[i])&&(s3[i]==s4[i])){
            cout<<s1[i];
        }
    }
    
    return 0;
}