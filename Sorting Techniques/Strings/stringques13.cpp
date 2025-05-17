#include<iostream>
#include<string>
using namespace std;
int main(){

    string s;
    getline(cin,s);
    int count = 1;
    int s1=0;
    int s2=s1+1;

    for(int i=s1;i<s.size();i++){
        for(int j=s2;j<s.size();j++){
            if(s[s1]!=s[s2]){
                s1=s2;
                s2=s1+1;
                count=count+1;
                }
            else{
                break;
            }
        }
    }
    cout<<count;

    return 0;
}