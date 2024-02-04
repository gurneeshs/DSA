/*
    https://www.codingninjas.com/studio/problems/longest-common-prefix_2090383?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
    You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest common 
    prefix among all these strings. If there is no common prefix, you have to return an empty string.

    A prefix of a string can be defined as a substring obtained after removing some or all characters 
    from the end of the string.
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
        void lcp(string first, string &ans){
            for(int i=0;i<first.length();i++){
                char ch = first[i];
                if(root->childCount==1){
                    ans.push_back(ch);
                    int index = ch-'a';
                    root = root->children[index];
                }
                else{
                    break;
                }
                if(root->isTerminal){
                    break;
                }
            }
        }
};
string longestCommonPrefix(vector<string> &arr, int n)
{
    // APPROACH 1:
    /*
    string ans;
    // for traversing all characters of first string
    for(int i=0;i<arr[0].size();i++){
        bool match = true;
        char ch = arr[0][i];

        // for remaining string
        for(int j=1;j<n;j++){
            if(arr[j].size()<i || ch!=arr[j][i]){
                match = false;
                break;
            }
        }
        if(!match){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;*/

    // APPROACH 2:
    Trie *t = new Trie();
    for(int i=0;i<n;i++){
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans;
    t->lcp(first, ans);
    return ans;
}


