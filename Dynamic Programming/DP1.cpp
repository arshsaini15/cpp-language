// fibonacci series (top-down approach/ Memoization)

#include<iostream>
#include<vector>
using namespace std;

int fibo(int n, vector<int> &dp){
    if(n <= 1){
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
}

int main(){

    int n=5;
    vector<int> dp(n+1, -1);
    cout << fibo(n, dp);

    return 0;
}