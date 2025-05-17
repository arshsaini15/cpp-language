// Searching in Trie.

#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data=ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

void insert(TrieNode* &root, string word){
    
    TrieNode* curr = root;

    for(int i=0; i<word.length(); i++){
        char ch = word[i];
        int index = ch - 'A';

        if(curr->children[index] == NULL){
            curr->children[index] = new TrieNode(ch);
        }
        curr = curr->children[index];
    }
    curr->isTerminal = true;
}

bool search(TrieNode* root, string word){

    TrieNode* curr = root;

    for(int i=0; i< word.length(); i++){
        char ch = word[i];
        int index = ch - 'A';

        if(curr->children[index] == NULL){
            return false;
        }
        curr = curr->children[index];
    }
    return curr->isTerminal;
}

int main(){

    TrieNode* root = new TrieNode('\0');
    insert(root,"ARSH");
    cout<<search(root,"AR");

    return 0;
}