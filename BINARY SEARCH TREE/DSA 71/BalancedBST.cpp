/*
    You have been given a binary search tree of integers with ‘N’ nodes. 
    Your task is to convert it into a balanced BST with the minimum height possible.

    A binary search tree (BST) is a binary tree data structure that has the following properties.

    • The left subtree of a node contains only nodes with data less than the node’s data.
    • The right subtree of a node contains only nodes with data greater than the node’s data.
    • Both the left and right subtrees must also be binary search trees.
    
    A Balanced BST is defined as a BST, in which the height of two subtrees of 
    every node differs no more than 1.

    https://www.codingninjas.com/studio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0&leftPanelTabValue=PROBLEM
*/

#include <iostream>
#include <vector>
using namespace std;

template<typename T> class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int maxi, int &i){
    if(i>=preorder.size()){
        return NULL;
    }
    if(preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);

    root->left = solve(preorder,mini,root->data,i);
    root->right = solve(preorder,root->data,maxi,i);
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int i = 0;
    return  solve(preorder,INT32_MIN,INT32_MAX,i);
}