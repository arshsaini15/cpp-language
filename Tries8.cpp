// Implementing Phone Directory (practice).

#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
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

    vector<vector<string> > getSuggestions(string s){
        
        TrieNode* prev = root;
        vector<vector<string> > output;

        string prefix = "";

        for(int i=0; i<s.size(); i++){
            char lastch = s[i];

            prefix.push_back(lastch);
            TrieNode* curr = prev->children[lastch - 'a'];

            if(curr == NULL){
                break;
            }

            vector<string> temp;
            printSuggestions(curr,temp,prefix);
            
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
    s.push_back("columbia");
    s.push_back("country");

    string a = "cou";

    vector<vector<string> > suggestions = PhoneDirectory(s,a);

    for (int i = 0; i < suggestions.size(); i++) {
        for (int j = 0; j < suggestions[i].size(); j++) {
            cout << suggestions[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}