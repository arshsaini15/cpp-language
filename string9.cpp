#include<iostream>
#include<string>
using namespace std;
int main(){

    string s1 = "123";
    int x = stoi(s1);
    cout<<x+2<<endl;
    

    int y = 123;
    cout<<to_string(y) + "2" <<endl; // here 2 is appended in string
    
    return 0;
}