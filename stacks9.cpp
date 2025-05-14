// Balanced Paranthesis.

#include<iostream>
#include<stack>
using namespace std;

bool balanced_paranthesis(string s){
    stack<char> st;
    bool ans=true;

    for(int i=0;i<s.length();i++){
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.top()=='('){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(s[i]==']'){
            if(st.top()=='['){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(s[i]=='}'){
            if(st.top()=='{'){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
    }

    if(!st.empty()){
        return false;
    }

    return ans;
}


int main(){

    string s="{a*(b-[x+b]-a)+z}";
    
    if(balanced_paranthesis(s)){
        cout<<"Valid String";
    }
    else{
        cout<<"Invalid String";
    }

    return 0;
}