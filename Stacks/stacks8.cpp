// Infix To Prefx

/*

Basic Rules to convert:

1. If operand: print.

2. If "(": push to stack.

3. If ")": pop from stack and print until "(" is found.

4. if operator: pop from stack and print until an 
    operator with less precedance is found.

*/

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixto_prefix(string s){
    
    stack<char> st;
    string res;

    reverse(s.begin(),s.end());
 
    for(int i=0;i<s.length();i++){
        
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z'){
            res+=s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            while(!st.empty() && st.top()!=')'){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>=prec(s[i])){
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
    reverse(res.begin(),res.end());
    return res;
}

int main(){

    string s ="(a-b/c)*(a/k-l)";
    cout<<infixto_prefix(s);

    return 0;
}