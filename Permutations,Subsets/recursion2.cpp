// Add all the subsets of an array in vector (ArrayList).

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> subset(vector<int> arr) {
    vector<vector<int>> outer;
    outer.push_back({});

    for(int num : arr) {
        int n = outer.size();
        for(int j=0; j<n; j++) {
            vector<int> internal = outer[j];
            internal.push_back(num);
            outer.push_back(internal);
        }
    } return outer;
}

int main() {
    vector<int> arr = {1,2,3};
    vector<vector<int>> res = subset(arr);

    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            cout << res[i][j];
        } cout << endl;
    }

    return 0;
}