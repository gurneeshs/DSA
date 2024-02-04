/*
    Given a binary tree, print the bottom view from left to right.
    A node is included in bottom view if it can be seen when we look at the tree from bottom.
    https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
    
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        vector<int> ans;
        // map<horizontal_distance,data>
        map<int,int> m;
        // queue<Node,hd> q;
        queue<pair<Node*, int> > q;
        
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            m[hd] = frontNode->data;
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, hd+1));
            }
        }
        
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
        
    }
};