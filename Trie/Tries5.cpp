// Longest Common Prefix.

#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    int childcount;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<25; i++){
            children[i] = NULL;
        }
        isTerminal = false;
        childcount = 0;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    bool searchUtil(TrieNode* root, string word){

        if(word.length() == 0){
            return root->isTerminal;
        }

        char ch = word[0];
        int index = ch - 'A';

        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(child,word.substr(1));
    }

    bool searchword(string word){
        return searchUtil(root,word);
    }

    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        char ch = word[0];
        int index = ch - 'A';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(ch);
            root->childcount++;
            root->children[index] = child;
        }

        insertUtil(child,word.substr(1));
    }

    void insertword(string word){
        insertUtil(root,word);
    }

    string lcp(string str,string &ans){
        
        for(int i=0; i<str.length(); i++){
            char ch = str[i];

            if(root->childcount == 1){
                ans.push_back(ch);

                // move ahead.
                int index = ch - 'A';
                root = root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal){
                break;
            }
        }
        return ans;
    }
};

string longestCommonPrefix(vector<string> &arr,int n){
    
    Trie* t = new Trie();

    // insert all strings into Trie
    for(int i=0; i<n; i++){
        t->insertword(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first,ans);
    return ans;
}

int main(){

    vector<string> s;
    s.push_back("NIGHT");
    s.push_back("NILON");
    s.push_back("NINE");

    cout<<longestCommonPrefix(s,s.size());

    return 0;
}