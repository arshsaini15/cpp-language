/*
Find all the duplicates subsets in an array.
Approach: Sort the array so that all the duplicates come together.
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> subsetDuplicate(vector<int> arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> outer;
    outer.push_back({});

    int start = 0;
    int end = 0;
    for(int i=0; i<arr.size(); i++) {

        start = 0;

        // If curr and previous elements are same, s = e + 1
        if(i > 0 && arr[i] == arr[i-1]) {
            start = end+1;
        }

        end = outer.size()-1;
        int n = outer.size();

        for(int j=start; j<n; j++) {
            vector<int> internal = outer[j];
            internal.push_back(arr[i]);
            outer.push_back(internal);
        }
    } return outer;
}

int main() {
    vector<int> arr = {1,2,2};
    vector<vector<int>> res = subsetDuplicate(arr);
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            cout << res[i][j];
        } cout << endl;
    }

    return 0;
}