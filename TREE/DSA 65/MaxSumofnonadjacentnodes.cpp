/*
    Given a binary tree with a value associated with each node, we need to choose a subset 
    of these nodes such that sum of chosen nodes is maximum under a constraint that no 
    two chosen node in subset should be directly connected that is, if we have taken a node 
    in our sum then we can’t take its any children or parents in consideration and vice versa.
    https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
class Solution{
    pair<int,int> solve(Node* root){
        // <int a , int b> a->sum including curr node, b-> sum excluding curr node
        if(root==NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> leftAns = solve(root->left);
        pair<int,int> rightAns = solve(root->right);
        
        pair<int,int> res;
        //Including root node
        res.first = root->data + leftAns.second + rightAns.second;
        // Excluding root node
        res.second = max(leftAns.first,leftAns.second) + max(rightAns.first,rightAns.second);
        return res;
    }
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }
};