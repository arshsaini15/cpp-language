// First Negative Number In Every Window (Fixed Sized).

#include<iostream>
#include<list>
#include<vector>
using namespace std;

vector<int> firstNegative(vector<int> arr, int k) {
    int i=0, j=0;
    list<int> l;
    vector<int> res;
    while(j < arr.size()) {
        if(arr[j] < 0) l.push_back(arr[j]);

        if(j-i+1 == k) {
            if(!l.empty()) {
                res.push_back(l.front());
                if(arr[i] == l.front()) l.pop_front(); 
            } else {
                res.push_back(0);
            }
            i++; 
        }
        j++;
    }
    return res;
}

int main() {
    vector<int> arr = {1, 2, 3, -1, -9, 11, -3, -2};
    int k = 3;
    vector<int> res = firstNegative(arr, k);
    for(int num: res) {
        cout << num << " ";
    }

    return 0;
}