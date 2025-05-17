#include<iostream>
#include<string>
using namespace std;

    void reverse(string str){

    }





int main(){

    string str;
    getline(cin,str);

    //using reverse
    reverse(str.begin(),str.end());
    cout<<str<<endl;

    cout<<endl;

    //reversing using functions
    for(int i=str.size();i>0;i--){
        cout<<str[i];
    }


    return 0;
}