#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1="abc"; 
    s1.clear();
    if(s1.empty()){
        cout<<"is empty";
    }
    return 0;
}