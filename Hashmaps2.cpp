// Maximum Frequency Number.

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int MaximumFrequencyNumber(string s){
    unordered_map<int,int> count;
    int maxFreq = 0;
    int maxAns = 0;

    for(int i=0;i<s.size();i++){
        count[s[i]]++;
        maxFreq = max(maxFreq,count[s[i]]);
    }

    for(int i=0;i<s.size();i++){
        if(maxFreq == count[s[i]]){
            maxAns = s[i];
            break;
        }
    }
    return maxFreq;
}

int main(){
    
    string s="1234112";
    cout<<MaximumFrequencyNumber(s);

    return 0;
}