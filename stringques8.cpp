#include<iostream>
#include<string>
using namespace std;
int main(){

    string s;
    getline(cin,s);
    
    int count=1;
     
    for(int i=s.size();i>=0;i++){
        if(s[i]==s[i-1]){
            count++;
        }
    }
    cout<<count;
    return 0;
}