#include<iostream>
#include<string>
using namespace std;

int main(){
    
    string largest = "";
    string num;
    cin>>num;

    for(char i = '9';i>='0';i--){

        string a(3,i);
        size_t found;

        found = num.find(a);

        if(found != string::npos){
            largest = max(largest,a);
        }
    }

    cout<<largest;

    return 0;
}