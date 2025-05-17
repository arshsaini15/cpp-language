#include<iostream>
using namespace std;

class Trienode{
    public:
    char data;
    Trienode* children[26];
    bool isTerminal;

    Trienode(char ch){
        data = ch;
        for(int i=0; i<25; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    Trienode* root;

    Trie(){
        root = new Trienode('\0');
    }

    void insertUtil(Trienode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        Trienode* child;

        // present 
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new Trienode(word[0]);
            root->children[index] = child;
        }
        insertUtil(root, word.substr(1));
    }

    void insertword(string word){
        insertUtil(root, word);
    }

    bool searchUtil(Trienode* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        Trienode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(root, word.substr(1));
    }

    bool searchword(string word){
        return searchUtil(root, word);
    }
};

int main(){

    Trie* t = new Trie();
    t->insertword("ABCD");
    cout << t->searchword("F");

    return 0;
}