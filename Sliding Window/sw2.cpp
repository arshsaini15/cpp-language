// Largest SubArray Sum (Variable Sized).

#include<iostream>
#include<vector>
using namespace std;

int LongestSubarraySum(vector<int> arr, int target) {
    int i = 0, j = 0, sum = 0, maximum = 0;

    while(j < arr.size()) {
        sum += arr[j];

        // Shrink window until sum <= target
        while(sum > target && i <= j) {
            sum -= arr[i];
            i++;
        }

        // Check for valid window
        if(sum == target) {
            maximum = max(maximum, j - i + 1);
        }

        j++;
    }

    return maximum;
}

int main() {
    vector<int> arr = {4, 1, 1, 1, 2 ,3 ,5};
    int target = 5;
    cout << LongestSubarraySum(arr, target);
}