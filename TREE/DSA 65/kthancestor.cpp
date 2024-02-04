/*
   Given a binary tree of size  N, a node, and a positive integer k., 
   Your task is to complete the function kthAncestor(), the function should 
   return the kth ancestor of the given node in the binary tree. If there 
   does not exist any such ancestor then return -1.
    https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

// void solve(Node* root, int k, int node, stack<Node*> s, int &ans){
//     if(root==NULL){
//         return;
//     }
//     s.push(root);
    
//     solve(root->left,k,node,s,ans);
//     solve(root->right,k,node,s,ans);
    
//     if(root->data==node){
//         for(int i =0;i<k;i++){
//             if(!s.empty()){
//                 s.pop();
//             }
//         }
//         if(!s.empty()){
//             Node* temp = s.top();
//             ans =temp->data;
//         }

//     }
// }
Node* solve(Node* root, int &k, int node){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    Node* left = solve(root->left,k,node);
    Node* right = solve(root->right,k,node);
    
    if(left!=NULL && right==NULL){
        if(k!=0){
            k--;
        }
        if(k<=0){
            // k = INT_MAX;//locking ans by making k very large
            return root;
        }
        return left;
    }
    if(left==NULL && right!=NULL){
        if(k!=0){
            k--;
        }
        if(k==0){
            // k = INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}    
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = solve(root,k,node);
    if(root->data==node || ans==NULL || k>0){
        return -1;
    }
    else{
        return ans->data;
        
    }
}
