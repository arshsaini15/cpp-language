// Insertion in Trie.

#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

void insert(TrieNode* &root, string word) {
    
    TrieNode* curr = root;

    for(int i = 0; i < word.length(); i++){
        char ch = word[i];
        int index = tolower(ch) - 'a';

        if(curr->children[index] == NULL){
            curr->children[index] = new TrieNode(ch);
        }
        curr = curr->children[index];
    }
    curr->isTerminal = true;
}

int main(){

    TrieNode* root = new TrieNode('\0');

    insert(root,"CAT");
    return 0;
}