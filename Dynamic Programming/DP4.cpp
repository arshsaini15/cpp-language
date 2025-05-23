// Minimum Cost Climbing Stairs (Memoization).

#include<iostream>
#include<vector>
using namespace std;

int MinCost(vector<int> &cost, int n, vector<int> &dp){
    // base case
    if(n == 0){
        return cost[0];
    }
    if(n == 1){
        return cost[1];
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = cost[n] + min(MinCost(cost, n-1, dp), MinCost(cost, n-2, dp));
    return dp[n];
}

int main(){

    vector<int> cost = {10,15,20};
    int n = cost.size();
    vector<int> dp(n+1, -1);

    int ans = min(MinCost(cost, n-1, dp), MinCost(cost, n-2, dp));
    cout << ans;

    return 0;
}