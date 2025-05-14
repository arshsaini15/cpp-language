#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;

    for(int i=0 ; i<s.size() ; i++){
        for(int j=i+1 ; j<s.size() ; j++){
            if(s[i]<s[j]){
                int temp = s[j];
                s[j]=s[i];
                s[i]=temp;
            }
        }
    }
     cout<<s<<" "<<endl;

    return 0;
}