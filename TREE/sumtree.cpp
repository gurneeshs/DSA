/*
    Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, 
    its value is equal to the sum of its left subtree's value and its right subtree's value. 
    Else return false.
    An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. 
    A leaf node is also considered a Sum Tree.
*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    pair<bool,int> isSumTreeFast(Node *root){
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        if(root->left==NULL && root->right==NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        /*
        if(root->left!=NULL && root->right==NULL){
            pair<bool,int> p;
            p.first = root->data==root->left->data;
            p.second = root->data;
        }
        
        if(root->left==NULL && root->right!=NULL){
            pair<bool,int> p;
            p.first = root->data==root->right->data;
            p.second = root->data;
        }*/
        
        pair<bool,int> left = isSumTreeFast(root->left);
        pair<bool,int> right = isSumTreeFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool currVal = (left.second+right.second)==root->data;
        
        pair<bool,int> ans;
        ans.second = left.second+right.second;
        
        if(leftAns && rightAns && currVal){
            ans.first = true;
            ans.second = 2*root->data;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }
};