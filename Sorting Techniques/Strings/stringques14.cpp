#include<iostream>
#include<string>
using namespace std;
int main(){

    string s;
    getline(cin,s);

    for(int i=0;i<s.size();i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            sort(s.begin(),s.end());
            if(s[i]==s[i+1]){
            continue;
            }
            else {
            cout<<s[i];
            }
        }
    }
 
    return 0;

}