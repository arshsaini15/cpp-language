#include<iostream>
#include<string>
using namespace std;
int main(){

    string s,s1;
    cin>>s;
    s1=s;

    for(int i=0;i<s.size()-1;i++){
        if(s[i]%2!=0 && s[i+1]%2!=0){
            s1.append(s[i]+"-");
        }
        cout<<s1<<endl;
    }
    return 0;
}