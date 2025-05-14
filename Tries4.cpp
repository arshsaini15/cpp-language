#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0;  i < 26; i++){
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

    bool searchUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            return true;
        }

        // assuming all words are in CAPS.
        int index = word[0] - 'A';
        TrieNode* child;

        // present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // absent
            return false;
        }
        return searchUtil(child,word.substr(1));
    }

    bool searchword(string word){
        return searchUtil(root,word);
    }

    void removeUtil(TrieNode* root, string word){
        if(searchword(word)){
            TrieNode* curr = root;
            for(int i = 0; i < word.length(); i++){
                int index = word[i] - 'A';
                curr = root->children[index];
            }
            curr->isTerminal = false;
        }
    }

    void removeword(string word){
        removeUtil(root,word);
    }

    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // assuming each character in CAPS.
        char ch = word[0];
        int index = ch - 'A';

        TrieNode* child;

        // present
        if(root->children[index] != NULL){
            child = root->children[index];
        }

        // absent
        else{
            child = new TrieNode(ch);
            root->children[index] = child;
        }
        

        // RECURSION
        insertUtil(child,word.substr(1));
    }

    void insertword(string word){
        insertUtil(root,word);
    }
};

int main(){

    Trie* t = new Trie();
    t->insertword("ABCD");
    t->insertword("DO");

    t->removeword("DO");

    return 0;
}