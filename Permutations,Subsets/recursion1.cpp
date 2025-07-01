// print all subsets of a string.

#include<iostream>
#include<string>
using namespace std;

void subset(string s, string curr) {
    if(s.empty()) {
        cout << curr << endl;
        return;
    }

    // take
    subset(s.substr(1), curr + s[0]);

    // not take
    subset(s.substr(1), curr);
}

int main() {
    string s = "abc";
    subset(s, "");

    return 0;
}