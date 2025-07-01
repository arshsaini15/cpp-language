/*  Letter Combination of a Phone Number

    Approach: Take first character from first string and rest from others, then take second character from first string and rest from others ...
*/

#include<iostream>
#include<vector>
using namespace std;

vector<string> res;
void helper(vector<string> &mapped, int index, string curr) {
    if(index == mapped.size()) {
        res.push_back(curr);
        return;
    }

    for(char ch : mapped[index]) {
        helper(mapped, index + 1, curr + ch);
    }
}

vector<string> letterCombinations(string digits) {
    if(digits.empty()) return res;

    vector<string> digits_num = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> mapped;

    for(char ch : digits) {
        int digit = ch - '0';
        if(digit > 1) mapped.push_back(digits_num[digit]);
    }

    helper(mapped, 0, "");
    return res;
}

int main() {
    string digits = "23";
    vector<string> result = letterCombinations(digits);

    for(string s : result) {
        cout << s << endl;
    }

    return 0;
}