/*
    Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
    If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

    https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
    
*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
    void solve(Node* root, int sum, int &maxSum, int len, int &maxLen){
        if(root==NULL){
            if(len>maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len==maxLen){
                maxSum = max(sum,maxSum);
            }
            return;
        }
            sum = sum + root->data;
            
            solve(root->left,sum,maxSum,len+1,maxLen);
            solve(root->right,sum,maxSum,len+1,maxLen);

    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int sum = 0;
        int len = 0;
        int maxLen = 0;
        int maxSum = INT32_MIN;
        
        solve(root,sum,maxSum,len,maxLen);
        return maxSum;
    }
};
