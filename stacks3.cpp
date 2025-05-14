// Reverse a stack using another stack.

#include<iostream>
#include<stack>
using namespace std;

    void Reverse_stacks(stack<int> &st){
        stack<int> copy;

        while(!st.empty()){
            int topele=st.top();
            st.pop();
            copy.push(topele);
        }
        while(!copy.empty()){
            cout<<copy.top()<<" ";
            copy.pop();
        }
    }

    
int main(){

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    Reverse_stacks(st);

    return 0;
}