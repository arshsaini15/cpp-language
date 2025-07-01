// Print all the unique permutations.

#include<iostream>
#include<vector>
using namespace std;

void backtrack(vector<vector<int>> &res, vector<int> nums, vector<bool> &vis, vector<int> &curr) {
    if(curr.size() == nums.size()) {
        res.push_back(curr);
        return;
    }

    for(int i=0; i<nums.size(); i++) {
        if(vis[i]) continue;
        if(i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) continue;

        vis[i] = true;
        curr.push_back(nums[i]);

        backtrack(res, nums, vis, curr);

        curr.pop_back();
        vis[i] = false;
    }
}

int main() {

    vector<int> nums = {1,1,2};
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    vector<bool> vis(nums.size(), false);
    vector<int> curr;

    backtrack(res, nums, vis, curr);
    
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res.size(); j++) {
            cout << res[i][j];
        } cout << endl;
    }

    return 0;
}
