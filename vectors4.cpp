#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool canArrange(vector<int>& arr, int k){
        vector<pair<int,int>> v;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int count = 0;

        // for(int i=0; i<n-1; i++){
        //     pair<int, int> p;
        //     for(int j=n; j>=0; j--){
        //         if(arr[i] + arr[j] == k){
        //             p = make_pair(arr[i], arr[j]);
        //             break;
        //         }
        //     }
        //     v.push_back(p);
        // }

        for(int i=0; i<n; i++){
            int left = i;
            int right = n-1;
            int sum = 0;
            pair<int, int> p(0,0);

            while(left < right){
                sum = arr[left] + arr[right];

                if(sum % k == 0){
                    p = make_pair(arr[left], arr[right]);
                    left++;
                    right--;
                    break;
                }

                else if(sum < k){
                    left++;
                } else {
                    right--;
                }
            }
            if(!(p.first == 0) || !(p.second == 0)){
                if(find(v.begin(), v.end(), p) == v.end()){
                    v.push_back(p);
                    count++;
                }
            }
        }
        return count >= n / 2;
    }
};

int main(){

    vector<int> v1 = {1,2,3,4,5,6};
    Solution sol;
    cout << sol.canArrange(v1, 10);

    return 0;
}