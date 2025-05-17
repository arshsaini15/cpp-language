// Isomorphic Strings.

#include<iostream>
#include<unordered_map>
using namespace std;

bool isIsomorphic(string s, string t){
    if(s.length() != t.length()) return false;

    unordered_map<char, char> m1;
    unordered_map<char, char> m2;

    for(int i=0; i<s.length(); i++){
        char c1 = s[i];
        char c2 = t[i];

        if(m1.count(c1)){
            if(m1[c1] != c2){
                return false;
            }
        }
        else{
            m1[c1] = c2;
        }
        
        if(m2.count(c2)){
            if(m2[c2] != c1){
                return false;
            }
        }
        else{
            m2[c2] = c1;
        }
    }
    return true;
}

int main(){

    string s = "foo";
    string t = "add";
    if(isIsomorphic(s,t)) cout << "Yes";
    else cout << "No";

    return 0;
}