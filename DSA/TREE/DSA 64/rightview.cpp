/*
    Given a Binary Tree, find Right view of it. 
    Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.
    https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1

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
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       
       vector<int> ans;
       // map<vertical_distance,data>
       map<int,int> m;
       // queue<Node,hd> q;
       queue<pair<Node*,int> > q;
       
       if(root==NULL){
           return ans;
       }
       
       q.push(make_pair(root,0));
       
       while(!q.empty()){
           pair<Node*, int> temp = q.front();
           q.pop();
           
           Node* frontNode = temp.first;
           int vd = temp.second;
           
           m[vd] = frontNode->data;
           
           if(frontNode->left){
               q.push(make_pair(frontNode->left,vd+1));
           }
           if(frontNode->right){
               q.push(make_pair(frontNode->right,vd+1));
           }
       }
       for(auto i:m){
           ans.push_back(i.second);
       }
       return ans;
    }
};

