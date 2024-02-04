/*
    https://www.codingninjas.com/studio/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

    You are given a list/array of strings which denotes the contacts that exist in your phone directory. 
    The search query on a string ‘str’ which is a query string displays all the contacts which are present 
    in the given directory with the prefix as ‘str’. One special property of the search function is that 
    when a user searches for a contact from the contact list then suggestions (contacts with prefix as the 
    string entered so for) are shown after the user enters each character.
*/

#include <iostream>
#include <vector>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
            childCount = 0;
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

            int index = word[0] - 'a';
            TrieNode* child;

            // char already present
            if(root->children[index]!=NULL){
                child= root->children[index];
            }
            else{
                child = new TrieNode(word[0]);
                root->childCount++;
                root->children[index] = child;
            }

            insertUtil(child, word.substr(1));
        }
        void insertWord(string word){
            insertUtil(root,word);
        }
        void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix){
            if(curr->isTerminal){
                temp.push_back(prefix);
            }
            for(char ch='a';ch<='z';ch++){
                TrieNode* next = curr->children[ch-'a'];
                if(next!=NULL){
                    prefix.push_back(ch);
                    printSuggestions(next, temp, prefix);
                    prefix.pop_back();
                }
            }
        }
        vector<vector<string>> getSuggestions(string str){
            TrieNode* prev = root;
            vector<vector<string>> output;
            string prefix = "";

            for(int i=0;i<str.length();i++){
                char lastch = str[i];
                prefix.push_back(lastch);

                TrieNode* curr = prev->children[lastch-'a'];

                if(curr==NULL){
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
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    // 1. CREATION OF TRIE
    Trie* t = new Trie();

    for(int i=0;i<contactList.size();i++){
        string str = contactList[i];
        t->insertWord(str);
    }

    return t->getSuggestions(queryStr);
}