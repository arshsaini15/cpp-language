#include<iostream>
#include<string>
using namespace std;

void checkpalin(string s1,string s2){
    for(int i=s1.size();i>=0;i--){
        if((s1[i]='a' && s1[i]<='z')||(s1[i]>='A' && s1[i]<='Z')){
            s1[i] = s1[i] +32;
        }
    }
    for(int i=0;i<s2.size();i++){
        if((s2[i]='a' && s2[i]<='z')||(s2[i]>='A' && s2[i]<='Z')){
            s2[i] = s2[i] +32;
        }
    }

    if(s1==s2){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return;
}

int main(){

    string s1,s2;
    getline(cin,s1);
    s2=s1;

    checkpalin(s1,s2);

    return 0;

}