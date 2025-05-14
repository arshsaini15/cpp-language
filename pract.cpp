// Number of ways to climb stairs.

#include<iostream>
using namespace std;

int count(int steps, bool isTwo){
    if(steps < 0) return 0;
    if(steps == 0) return 1;

    int res = 0;
    res += count(steps-1,false);
    if(!isTwo) res += count(steps-2, true);

    return res;
}

int main(){

    int steps = 5;
    cout << count(steps, false);

    return 0;
}