// Minimum Number of Coins.

#include<iostream>
#include<vector>
using namespace std;

int MinCoins(vector<int> coins, int target){
    if(target == 0){
        return 0;
    }
    if(target < 0){
        return INT_MAX;
    }

    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int ans = MinCoins(coins, target - coins[i]);
        if(ans != INT_MAX){
            mini = min(mini, 1+ans);
        }
    }
    return mini;
}

int SolveMem(vector<int> &coins, int target, vector<int> &dp){

    if(target == 0){
        return 0;
    }
    if(target < 0){
        return INT_MAX;
    }
    if(dp[target] != -1){
        return dp[target];
    }

    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int ans = SolveMem(coins, target - coins[i], dp);
        if(ans != INT_MAX){
            mini = min(mini, 1+ans);
        }
    }
    dp[target] = mini;

    return mini;
}

int SolveTab(vector<int> &coins, int target){
    vector<int> dp(target+1, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=target; i++){
        for(int j=0; j<coins.size(); j++){
            if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    if(dp[target] == INT_MAX){
        return -1;
    }
    return dp[target];
}

int main(){

    vector<int> coins = {1,2,5};
    int target = 11;

    int ans = MinCoins(coins, target);
    if(ans == INT_MAX){
        return -1;
    }
    else{
        cout << ans << endl;
    }

    // Solve using Memoization
    vector<int> dp(target+1, -1);
    int ans2 = SolveMem(coins, target, dp);

    if(ans2 == INT_MAX){
        return -1;
    }
    else{
        cout << ans2 << endl;
    }

    // Solve using Tabulation
    int ans3 = SolveTab(coins, target);
    if(ans3 == INT_MAX){
        return -1;
    }
    else{
        cout<<ans3;
    }

    return 0;
}