
/*
    Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
    If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.
    https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
    
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};




class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        // Data Structures Required
        
        // map<horizontal_dist, map<level, vector<list>>>
        map<int,map<int,vector<int> > > nodes;
        // queue<pair<Node, pair<horizontal_dist,level>>>
        queue<pair<Node*, pair<int,int> > > q;
        vector<int> ans;
        
        if(root==NULL){
            return ans;
        }
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            // Queue First Element
            pair<Node*, pair<int,int> > temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            
            // Pushing Data into map
            nodes[hd][level].push_back(frontNode->data);
            
            // Level Order Traversal, left hd-1, right hd+1, level+1
            if(frontNode->left){
                q.push(make_pair(frontNode->left, make_pair(hd-1,level+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, make_pair(hd+1,level+1)));
            }
        }
        
        for(auto i:nodes){//nodes
            for(auto j:i.second){//Level
                for(auto k:j.second){//data
                    ans.push_back(k);
                }
            }
        }
        return ans;
        
    }
};
