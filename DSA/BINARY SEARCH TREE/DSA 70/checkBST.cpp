/*
Problem statement
Given a binary tree with N number of nodes, check if that input tree is Partial BST (Binary Search Tree) or not. If yes, return true, return false otherwise.

A binary search tree (BST) is said to be a Partial BST if it follows the following properties.

• The left subtree of a node contains only nodes with data less than and equal to the node’s data.
• The right subtree of a node contains only nodes with data greater than and equal to the node’s data.
• Both the left and right subtrees must also be partial binary search trees.
https://www.codingninjas.com/studio/problems/validate-bst_799483?leftPanelTab=0&leftPanelTabValue=PROBLEM

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

bool isBST(BinaryTreeNode *root, int min, int max){
    if(root==NULL){
        return true;
    }

    if(root->data>=min && root->data<=max){
        bool left = isBST(root->left,min,root->data);
        bool right = isBST(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }
}
bool validateBST(BinaryTreeNode *root) {
    // Write your code here
    return isBST(root,INT_MIN,INT_MAX);
}