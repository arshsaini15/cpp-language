#include<iostream>
#include<string>
using namespace std;
int main(){

    string s;
    cin>>s;

    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            cout<<"zero"<<" ";
        }
        else if(s[i]=='1'){
            cout<<"one"<<" ";
        }
        else if(s[i]=='2'){
            cout<<"two"<<" ";
        }
        else if(s[i]=='3'){
            cout<<"three"<<" ";
        }
        else if(s[i]=='4'){
            cout<<"four"<<" ";
        }
        else if(s[i]=='5'){
            cout<<"five"<<" ";
        }
        else if(s[i]=='6'){
            cout<<"six"<<" ";
        }
        else if(s[i]=='7'){
            cout<<"seven"<<" ";
        }
        else if(s[i]=='8'){
            cout<<"eight"<<" ";
        }
        else if(s[i]=='9'){
            cout<<"nine"<<" ";
        }
    }

    return 0;
}