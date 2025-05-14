#include<iostream>
#include<unordered_set>
using namespace std;

bool getNextNumber(int n){
    if(n == 1) return true;
    if(n > 1 && n < 10) return false;

    int output = 0;
    while(n > 0){
        int digit = n % 10;
        output += digit * digit;
        n = n / 10;
    }

    return getNextNumber(output);
}

bool isHappy(int n){
    // unordered_set<int> visit;
    // while(visit.find(n) == visit.end()){
    //     visit.insert(n);
    //     n = getNextNumber(n);

    if(n > 1 && n < 10) return false;

    if(getNextNumber(n)) return true;
    // }
    return false;
}


int main(){
    int n = 21;
    cout << isHappy(n);

    return 0;
}