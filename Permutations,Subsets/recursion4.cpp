// print all the permutations of given array.

#include<iostream>
#include<vector>
using namespace std;

void permute(vector<int> arr, vector<int> curr) {
    if(arr.empty()) {
        for(int i=0; i<curr.size(); i++) {
            cout << curr[i];
        } cout << endl;
        return;
    }

    int num = arr[0];
    vector<int> rest(arr.begin()+1, arr.end());

    for(int i=0; i<=curr.size(); i++) {
        vector<int> first (curr.begin(), curr.begin()+i );
        vector<int> second (curr.begin()+i, curr.end());

        first.push_back(num);

        vector<int> mixed = first;
        mixed.insert(mixed.end(), second.begin(), second.end());
    
        permute(rest, mixed);
    }
}

int main() {
    vector<int> arr = {1,2,3};
    permute(arr, {});

    return 0;
}