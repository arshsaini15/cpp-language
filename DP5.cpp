// Minimum Cost Climbing Stairs (Tabulation).

#include<iostream>
#include<vector>
using namespace std;

int MinCost(vector<int> &cost, int n){
    
    vector<int> dp(n+1);

    // base case
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i=2; i<n; i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);
}

int main(){

    vector<int> cost = {10,15,20};
    int n = cost.size();

    cout << MinCost(cost, n);

    return 0;
}