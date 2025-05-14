// Implement a Phone Directory

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode* children[26];

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<25;i++){
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
        
        if(word.size() == 0){
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
        insertUtil(child,word.substr(1));
    }

    void insertword(string word){
        insertUtil(root,word);
    }

    void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix){
      
        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        for(char ch = 'a'; ch <= 'z'; ch++){

            TrieNode* next = curr->children[ch - 'a'];
            // present
            if(next != NULL){
                prefix.push_back(ch);
                printSuggestions(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string> > getSuggestions(string str){

        TrieNode* prev = root;
        vector<vector<string> > output;

        string prefix = "";
        for(int i=0; i<str.size(); i++){
            char lastch = str[i];

            prefix.push_back(lastch);

            // check for last ch
            TrieNode* curr = prev->children[lastch - 'a'];

            // if not found.
            if(curr == NULL){
                break;
            }

            // if found.
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string> > PhoneDirectory(vector<string> &ContactList, string &queryStr){

    Trie* t = new Trie();

    for(int i=0; i<ContactList.size(); i++){
        string str = ContactList[i];
        t->insertword(str);
    }

    return t->getSuggestions(queryStr);
}

int main(){

    vector<string> s;
    s.push_back("code");
    s.push_back("coding");
    s.push_back("coders");
    s.push_back("colony");
    s.push_back("curd");

    string queryStr = "cod";

    vector<vector<string> > suggestions = PhoneDirectory(s,queryStr);

    for (int i = 0; i < suggestions.size(); i++) {
        for (int j = 0; j < suggestions[i].size(); j++) {
            cout << suggestions[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}