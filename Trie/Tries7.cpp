// Reverse a word.

#include<iostream>
using namespace std;

class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertword(string word){
        insertUtil(root, word);
    }

    void reversewordUtil(TrieNode* root, string s, string &ans){
        if(s.length() == 0){
            return;
        }

        TrieNode* child;
        int index = s[0] - 'a';

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        reversewordUtil(child, s.substr(1), ans);
        ans.push_back(child->data);
    }

    string reverseword(string s){
        string ans = "";
        reversewordUtil(root, s, ans);
        return ans;
    }
};

int main() {
    Trie* t = new Trie();
    string s = "abcd";
    t->insertword(s);
    
    string result = t->reverseword(s);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    delete t;

    return 0;
}