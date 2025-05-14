#include<iostream>
#include<string>
using namespace std;
int main(){


/*    string s1 = "a";
    s1[0]=s1[0]-32;
    cout<<s1<<endl; // here  it outputs A
    return 0;
*/



    string s1 = "arshdeep"; 
    //convert into uppercase
    for(int i=0;i<s1.size();i++){    
        if(s1[i] >= 'a' && s1[i] <= 'z'){
            s1[i] -= 32; 
        }
       
    }
    cout<<s1<<endl;

    // covert into lowercase
    for(int i=0;i<s1.size();i++){
        if(s1[i]>='A' && s1[i]<='Z'){
            s1[i]+=32;
            }
    }
    cout<<s1<<endl;

    return 0;
}