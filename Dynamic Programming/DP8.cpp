// Minimum Number of Coins (Tabulation).

#include<iostream>
#include<vector>
using namespace std;

int MinCoins(vector<int> &coins, int target){
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
        cout<<ans;
    }

    return 0;
}