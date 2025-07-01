// Combination Sum II (Duplicates Not Allowerd).

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> res;

void solve(vector<int>& arr, vector<int>& curr, int k, int i) {
    if (k == 0) {
        res.push_back(curr);
        return;
    }

    if (i >= arr.size() || k < 0) return;

    // ✅ take
    curr.push_back(arr[i]);
    solve(arr, curr, k - arr[i], i + 1);
    curr.pop_back();

    // ✅ not take (skip duplicates)
    int next = i + 1;
    while(next < arr.size() && arr[next] == arr[i]) next++;
    solve(arr, curr, k, next);
}

int main() {
    vector<int> arr = {1, 8, 4, 2, 9, 5, 7, 6, 1, 2};
    int k = 11;

    sort(arr.begin(), arr.end());

    vector<int> curr;
    solve(arr, curr, k, 0);

    for (auto& comb : res) {
        for (int n : comb) cout << n << " ";
        cout << endl;
    }

    return 0;
}