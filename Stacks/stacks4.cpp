// Reverse a stack without using another stack .

#include<iostream>
#include<stack>
using namespace std;

void insertat_bottom(stack<int> &st, int ele){
    
    // base case
    if(st.empty()){
        st.push(ele);
        return;
    }

    int topele=st.top();
    st.pop();
    insertat_bottom(st,ele);

    st.push(topele);
}

void reverse(stack<int> &st){

    // base case
    if(st.empty()){
        return;
    } 

    int ele=st.top();
    st.pop();

    reverse(st);
    insertat_bottom(st,ele);
}

int main(){
     
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverse(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;

    return 0;
}