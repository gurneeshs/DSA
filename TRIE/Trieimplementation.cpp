/*
    Implement the logic of Trie
*/

#include <iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            this->data = ch;
            for(int i=0;i<26;i++){
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
            if(word.length()==0){
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            // char already present
            if(root->children[index]!=NULL){
                child= root->children[index];
            }
            else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            insertUtil(child, word.substr(1));
        }
        bool searchUtil(TrieNode* root, string word){
            // base case
            if(word.length()==0){
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            // char already present
            if(root->children[index]!=NULL){
                child= root->children[index];
            }
            else{
                return false;
            }
            return searchUtil(child, word.substr(1));            
        }
        void deleteUtil(TrieNode* root, string word){
            // base case
            if(word.length()==0){
                root->isTerminal = false;
                return;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            // char already present
            if(root->children[index]!=NULL){
                child= root->children[index];
                // child->isTerminal = false;
            }
            deleteUtil(child, word.substr(1));            
        }
        void insertWord(string word){
            insertUtil(root,word);
        }
        void deleteWord(string word){
            deleteUtil(root,word);
        }

        bool searchWord(string word){
            return searchUtil(root,word);
        }
};

int main(){
    Trie *t = new Trie();


    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    t->insertWord("TIS");

    cout<<"Present or not"<<t->searchWord("ARM");
    cout<<"Present or not"<<t->searchWord("ARM");

    return 0;
}