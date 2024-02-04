/*
You are given a binary search tree of integers with N nodes. You are also given references to two nodes 'P' and 'Q' from this BST.

Your task is to find the lowest common ancestor(LCA) of these two given nodes.

The lowest common ancestor for two nodes P and Q is defined as the lowest node that has both P and Q as descendants (where we allow a node to be a descendant of itself)

A binary search tree (BST) is a binary tree data structure which has the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.
https://www.codingninjas.com/studio/problems/lca-in-a-bst_981280?leftPanelTab=0&leftPanelTabValue=PROBLEM&customSource=studio_nav

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


TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    if(root==NULL){
        return NULL;
    }

    if((P->data<root->data && Q->data>root->data) ||(P->data<root->data && Q->data>root->data)){
        return root;        
    }
    if(P->data==root->data || Q->data==root->data){
        return root;
    }

    if(P->data<root->data && Q->data<root->data){
        return LCAinaBST(root->left,P,Q);
    }
    else if (P->data>root->data && Q->data>root->data){
        return LCAinaBST(root->right,P,Q);
    }
}