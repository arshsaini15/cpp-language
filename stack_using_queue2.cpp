// Stacks using queues.
// Making pop costly.

#include<iostream>
#include<queue>
using namespace std;

class Stacks{
    queue<int> q1;
    queue<int> q2;

    public:
    void push(int x){
        q1.push(x);
    }

    void pop(){

        if(q1.empty()){
            cout<<"Stack Underflow"<<endl;
            return;
        }

        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();

        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }

    int top(){

        if(q1.empty()){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans=q1.front();
        q2.push(ans);

        queue<int> temp=q1;
        q1=q2;
        q2=temp;

        return ans;
    }

};

int main(){

    Stacks s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout<<s.top()<<endl;

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.top()<<endl;

    // cout<<s.top()<<endl;

    return 0;
}