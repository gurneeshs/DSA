/*
    You have been given an array/list 'PREORDER' representing the preorder traversal of a BST with 'N' nodes.
    All the elements in the given array have distinct values.

    Your task is to construct a binary search tree that matches the given preorder traversal.

    https://www.codingninjas.com/studio/problems/preorder-traversal-to-bst_893111?leftPanelTab=0&leftPanelTabValue=PROBLEM

*/

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

void inorder(TreeNode<int>* root, vector<int> &arr){
    if(root==NULL){
        return;
    }

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
TreeNode<int>* solve(vector<int> arr,int s, int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    TreeNode<int>* temp = new TreeNode<int>(arr[mid]);

    temp->left = solve(arr,s,mid-1);
    temp->right = solve(arr,mid+1,e);
    return temp;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    if(root==NULL){
        return NULL;
    }
    vector<int> arr;
    inorder(root, arr);
    int e = arr.size()-1;
    TreeNode<int>* newRoot;
    newRoot = solve(arr,0,e);
    return newRoot;

}
