#include<iostream>
using namespace std;

int main(){

    int k = 7;
    int n = 2;
    int sum = 0;

    while(sum <= k){
        sum += n;
    }

    cout << sum;

    return 0;
}