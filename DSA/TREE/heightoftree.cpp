/*
    Given a Binary Tree, You have to return the height of binary tree
    
*/
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        // base case 
        if(node==NULL){
            return 0;
        }
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        int ans = 1+max(leftHeight,rightHeight);
        return ans;
    }
};