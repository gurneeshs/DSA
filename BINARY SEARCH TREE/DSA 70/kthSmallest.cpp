/*

Problem statement
Given a binary search tree and an integer ‘K’. Your task is to find the ‘K-th’ smallest element in the given BST( binary search tree).

BST ( binary search tree) -


If all the smallest nodes on the left side and all the greater nodes on the right side of the node current node.
https://www.codingninjas.com/studio/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0&leftPanelTabValue=PROBLEM

*/
#include <iostream>
using namespace std;
class BinaryTreeNode 
    {
    public : 
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

int solve(BinaryTreeNode* root, int &i,int k){
    if(root==NULL){
        return -1;
    }

    int left = solve(root->left,i,k);
    if(left!=-1){
        return left;
    }
    
    i++;
    if(i==k){
        return root->data;
    }

    return solve(root->right,i,k);
}
int kthSmallest(BinaryTreeNode* root, int k) {
    // Write your code here.
    int i = 0;
    int ans = solve(root,i,k);
    return ans;
}
