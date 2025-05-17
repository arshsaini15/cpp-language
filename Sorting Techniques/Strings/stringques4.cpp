#include<iostream>
#include<string>
using namespace std;
int main(){

    string s;
    getline(cin,s);


    for(int i=s.size();i>0;i--){
     if((s[i]>='a' && s[i]<='z')|| (s[i]>='A'&&s[i]<='Z')){
            for(int j=i-1;j>=0;j--){
                if(s[i]<s[j]){
                    int temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
    }

    cout<<s<<endl;
   
    return 0;
}