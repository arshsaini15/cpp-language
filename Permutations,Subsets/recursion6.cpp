// Combination Sum (Repetition Allowed)

#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> arr, vector<int> curr, int k, int i) {
    if(k == 0) {
        for(int n : curr) cout << n << " ";
        cout << endl;
        return;
    }

    if(i == arr.size() || k < 0) return;

    // take
    curr.push_back(arr[i]);
    solve(arr, curr, k-arr[i], i);
    curr.pop_back();

    // not take
    solve(arr, curr, k, i+1);
}

int main() {
    vector<int> arr = {1,5,4,2,9,11,2};
    int k = 11;
    
    solve(arr, {}, k, 0);
    
    return 0;
}
