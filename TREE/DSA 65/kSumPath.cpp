/*
    Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
    A path may start from any node and end at any node in the downward direction.
    https://www.geeksforgeeks.org/problems/k-sum-paths/1

*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution{
    void solve(Node* root, int k, int &count, vector<int> path){
        if(root==NULL){
            return;
        }
        // pushing node data in path
        path.push_back(root->data);
        
        // left call
        solve(root->left,k,count,path);
        // right call
        solve(root->right,k,count,path);
        
        int siz = path.size();
        int sum = 0;
        for(int i=siz-1;i>=0;i--){//checking sum
            sum+=path[i];
            if(sum==k){
                count++;
            }
        }
        path.pop_back();
    }
  public:
    int sumK(Node *root,int k)
    {
        // code here 
        int count = 0;
        vector<int> path;
        solve(root,k,count,path);
        
        return count;
    }
};
