#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    unordered_map<string, int> m;
    m["abc"] = 1;
    m["arsh"] = 2;

    cout << m.at("abc") << endl;
    cout << m["abc"] << endl;
    cout << m.count("arsh") << endl;

    return 0;
}