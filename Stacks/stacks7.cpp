// Convert Infix To Postfix

/*

Basic Rules to convert:

1. if operand: print.

2. if "(": push to stack.

3. if ")": pop from stack and print until "(" is found.

4. if operator: pop from stack and print until an 
    operator with less precedence is found.

    Precedence of (^) is max then ("*","/") then ("+","-").

*/

#include<iostream>
#include<stack>
using namespace std;

int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixto_postfix(string s){

    stack<char> st;
    string res;

    for(int i=0;i<s.length();i++){
        
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z'){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(st.top()=='('){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;   
}

int main(){

    cout<<infixto_postfix("(a-b/c)*(a/k-l)");

    return 0;
}