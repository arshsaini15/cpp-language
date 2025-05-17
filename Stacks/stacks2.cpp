// Reverse a sentence using Stacks.

#include<iostream>
#include<stack>
using namespace std;

#define n 100

void ReverseSentence(string s){

    stack <string> st;
    for(int i=0;i<s.size();i++){
       
        string word="";
        while(s[i] !=' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop(); 
    }cout<<endl;
}

int main(){

    string s="Hey, how are you doing?";
    ReverseSentence(s);

    return 0;
}