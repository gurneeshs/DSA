/*
    https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1
    Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
    Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
bool isCBT(struct Node* root, int index, int count){
    if(root==NULL){
        return true;
    }
    if(index >= count){
        return false;
    }
    
    bool left = isCBT(root->left,2*index+1,count);
    bool right = isCBT(root->right,2*index+2,count);
    return (left && right);
}


bool isMaxHeap(struct Node* root){
    // if(root==NULL){
    //     return true;
    // }
    // leaf node
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    if(root->right==NULL){
        return (root->data > root->left->data);
    }
    
    else{
        bool leftAns = isMaxHeap(root->left);
        bool rightAns = isMaxHeap(root->right);
        bool curr = (root->data > root->left->data && root->data > root->right->data);
        
        return (leftAns && rightAns && curr);
    }
}

int countNode(struct Node* root){
    if(root==NULL){
        return 0;
    }
    
    int ans = 1 + countNode(root->left) + countNode(root->right);
    return ans;
}
class Solution {
  public:
    bool isHeap(struct Node* tree) {
        // code here
        int count = countNode(tree);
        int index = 0;
        
        if(isCBT(tree,index,count) && isMaxHeap(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};