#include<iostream>
#include<string>
using namespace std;
int main(){

    string s;
    getline(cin,s);
    int count=0;

    for(int i=0;i<s.size();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            if(s[i]=='e'){
                if(s[i+2]=='g'||s[i-2]=='g'||s[i+2]=='G'||s[i-2]=='G'){
                    count++;
                    cout<<count<<endl;
                }
            }
        }
    }

    return 0;
}