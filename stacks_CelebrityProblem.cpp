// Celebrity problem.

#include<iostream>
#include<stack>
using namespace std;

bool knows(int a, int b, int arr[3][3]){
    if(arr[a][b] == 1){
        return true;
    }
    else{
        return false;
    }
}

int Celebrity_Problem(int arr[3][3], int n){
    stack<int> st;

    // Step 1: push all elements in stack.
    for(int i=0;i<n;i++){
        st.push(i);
    }

    // Step 2: Get 2 elements and compare them.
    while(st.size() > 1){
        int A=st.top();
        st.pop();
        int B=st.top();
        st.pop();

        if(knows(A,B,arr)){
            st.push(B);
        }
        else{
            st.push(A);
        }   
    }

    int candidate = st.top();

    // Step 3: Single element in stack is potential Celebrity.
    // So verify it.
    bool rowcheck = false;
    int zerocount=0;

    for(int i=0;i<n;i++){
        if(arr[candidate][i] == 0){
            zerocount++;
        }
    }

    // all zeroes
    if(zerocount == n){
        rowcheck=true;
    }

    bool colcheck = false;
    int onecount=0;

    for(int i=0;i<n;i++){
        if(arr[i][candidate] == 1){
            onecount++;
        }
    }
    if(onecount == n-1){
        colcheck = true;
    }

    if(rowcheck == true && colcheck == true){
        return candidate;
    }
    else{
        return -1;
    }
}

int main(){

    int arr[3][3];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }

    cout<<Celebrity_Problem(arr,3);

    return 0;
}