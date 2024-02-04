/*
    You have been given a Binary Tree of 'N' nodes, where the nodes have integer values. 
    Your task is to return the size of the largest subtree of the binary tree which is also a BST.
    https://www.codingninjas.com/studio/problems/largest-bst-subtree_893103?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
*/

#include <iostream> 
using namespace std;

class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode* root, int &ans){
    // base case
    if(root==NULL){
        return {INT32_MIN,INT32_MAX,true,0};
    }

    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data,right.maxi);
    currNode.mini = min(root->data,left.mini);

    if(left.isBST && right.isBST && (root->data>left.maxi && root->data<right.mini)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }
    if(currNode.isBST){
        ans = max(ans, currNode.size);
    }
    return currNode;
}
int largestBST(TreeNode * root){
    // Write your code here.

    int maxSize = 0;
    info temp = solve(root,maxSize);
    return maxSize;
}