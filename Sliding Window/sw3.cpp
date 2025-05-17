// Longest Substring With K Unique Character (Variable Sized).

#include<iostream>
#include<unordered_map>
using namespace std;

int LongestSubstring(string s, int k) {
    int i=0, j=0, maxLen=0;
    unordered_map<char, int> mp;
    while(j < s.length()) {
        char c = s[j];
        mp[c]++;
        if(mp.size() > k) {
            while(mp.size() > k) {
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
        } else if(mp.size() == k) {
            maxLen = max(maxLen, j-i+1);
        }
        j++;
    }
    return maxLen;
}

int main() {
    int k = 3;
    string s = "aabacebebebe";
    cout << LongestSubstring(s, k);
}