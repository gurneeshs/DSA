/*
    You have been given a Binary Search Tree and a target value. You need to find out whether 
    there exists a pair of node values in the BST, such that their sum is equal to the target value.

    A binary search tree (BST), also called an ordered or sorted binary tree, is a rooted binary tree 
    whose internal nodes each store a value greater than all the values keys in the node's left subtree 
    and less than those in its right subtree.

    Follow Up:
    Can you solve this in O(N) time, and O(H) space complexity?

    https://www.codingninjas.com/studio/problems/two-sum-in-a-bst_1062631?leftPanelTab=0&leftPanelTabValue=PROBLEM
*/

#include <iostream>
#include <vector>
using namespace std;

template <typename T> class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};
void inorder(BinaryTreeNode<int>* root, vector<int> &arr){
    if(root==NULL){
        return;
    }

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> arr;
    inorder(root,arr);
    int i=0, j = arr.size()-1;

    while(i<j){
        if(arr[i]+arr[j]==target){
            return true;
        }
        else if(arr[i]+arr[j]<target){
            i++;
        }
        else{
            j--;
        }
    }
    return false;

}