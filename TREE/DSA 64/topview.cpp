/*
    Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree
    https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1


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
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        map<int,int> m;
        queue<pair<Node*,int> > q;
        
        if(root==NULL){
            return ans;
        }
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node* ,int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            if(m.find(hd)==m.end()){
                m[hd] = frontNode->data;
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
        
        
    }

};
