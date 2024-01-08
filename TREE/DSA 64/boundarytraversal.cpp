/*
    https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
private:
    void LeftTraversal(Node* root, vector<int> &ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            LeftTraversal(root->left,ans);
        }
        else{
            LeftTraversal(root->right,ans);
        }
    }
    void LeafTraversal(Node* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        LeafTraversal(root->left,ans);
        LeafTraversal(root->right,ans);
    }
    void RightTraversal(Node* root, vector<int> &ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        if(root->right){
            RightTraversal(root->right,ans);
        }
        else{
            RightTraversal(root->left,ans);
        }
        ans.push_back(root->data);

    }

public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        
        // Left Part
        LeftTraversal(root->left,ans);
        
        // Leaf Part
        LeafTraversal(root->left,ans);
        LeafTraversal(root->right,ans);
        
        // Right Part
        RightTraversal(root->right,ans);
        return ans;
    }
};