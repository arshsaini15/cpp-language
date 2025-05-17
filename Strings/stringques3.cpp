#include<iostream>
#include<string>
using namespace std;
int main(){

    string s;
    getline(cin,s);
    int count = 0 ;

    for(int i=0;i<s.size();i++){
        int start =s[0];
        if(s[i]!=' ' && (s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')){
            count++;
          
            if(s[i]==' '){
                continue;
            }
        }
    }
    cout<<count;
    return 0;

}