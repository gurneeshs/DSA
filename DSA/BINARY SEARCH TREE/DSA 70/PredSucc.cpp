/*
Problem statement
You have been given a binary search tree of integers with ‘N’ nodes. You are also given 'KEY' which represents data of a node of this tree.


Your task is to return the predecessor and successor of the given node in the BST.
https://www.codingninjas.com/studio/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&leftPanelTabValue=PROBLEM

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

pair<int, int> predecessorSuccessor(TreeNode *root, int key){
    int pred = -1;
    int succ = -1;

    TreeNode* temp = root;
    while(temp && temp->data != key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }

    if(temp){
        // predecessor
        TreeNode* leftTree = temp->left;
        while(leftTree){
            pred = leftTree->data;
            leftTree = leftTree->right;
        }

        // successor
        TreeNode* rightTree = temp->right;
        while(rightTree){
            succ = rightTree->data;
            rightTree = rightTree->left;
        }
    }

    return {pred, succ};
}