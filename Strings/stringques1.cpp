#include<iostream>
#include<string>
using namespace std;
int main(){

    string str;
    getline(cin,str);
    

    for(int i=0;i<str.size();i++){

        if(str[i]=='z'){
            str[i]='a';
        }

        else if(str[i]=='Z'){
            str[i]='A';
        }

        else if(str[i]>='a' && str[i]<='y'){
            str[i]=str[i] + 1;  
        }
         
        else if(str[i]>='A' && str[i]<='Y'){
            str[i]=str[i] + 1;
            }  
        cout<<str[i];
    }

    return 0;
}