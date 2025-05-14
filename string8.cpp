#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1="abc";

    for(int i=0;i<s1.size();i++){
        cout<<s1[i]<<endl;
    }

    string s2="arshdeep";
    string s = s2.substr(2,7);
    cout<<s<<endl;

    return 0;
}