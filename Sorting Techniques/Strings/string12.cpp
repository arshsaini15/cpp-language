#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s="abcd";
    // to uppercase
    transform(s.begin(),s.end(),s.begin(),::toupper);
    cout<<s<<endl;

    // to lowercase
    transform(s.begin(),s.end(),s.begin(),::tolower);
    cout<<s<<endl;

    return 0;
}