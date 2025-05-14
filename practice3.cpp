#include<iostream>
using namespace std;

int main(){
    int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int n = 3, m = 3;

    // 1 4 7 8 9 6 3 2 5

    int top = 0;
    int left = 0;
    int bottom = n-1;
    int right = m-1;

    int t=top;
    int l=left;
    int r=right;
    int b=bottom;

    while(top <= bottom && left <= right){
        while(t <= b){
            cout << arr[t][l] << " ";
            t++;
        }
        left++;
        l=left;
        t=top;

        while(l <= r){
            cout << arr[b][l] << " ";
            l++;
        }
        l = left;
        bottom--;
        b=bottom;

        while(b >= t){
            cout << arr[b][r] << " ";
            b--;
        }
        b=bottom;
        right--;
        r=right;

        while(r >= l){
            cout << arr[t][r] << " ";
            r--;
        }
        r=right;
        top++;
        t=top;
    }

    return 0;
}