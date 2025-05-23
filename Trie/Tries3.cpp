// Insertion,Searching in Trie (Using recursion).

#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data=ch;
        for(int i=0; i<25; i++){
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

        // assumption,word will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        // present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // RECURSIONc
        insertUtil(child, word.substr(1));
    }

    void insertword(string word){
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            return root->isTerminal;
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
};

int main(){

    Trie* t = new Trie();

    t->insertword("ABCD");
    cout<<t->searchword("ABC") << endl;
    cout<<t->searchword("XYZ");

    return 0;
}