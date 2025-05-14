#include<iostream>
#include<string>
using namespace std;

    int scan(string s){
        for(int i=0;i<s.size();i++){

            if(i==0){
                if(s[i]>='a' && s[i]<='z'){
                    s[i] -= 32;
                }
            }

            else if(s[i]==' '){
                if(s[i+1]>='a' && s[i+1]<='z'){
                s[i+1] -= 32;
                }
        }

    }
        
        cout<<s<<endl;
        return 0;
    }

int main(){

    string s;
    getline(cin,s);
    scan(s);

  

    return 0;
}