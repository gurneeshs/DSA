/*
    Given a binary tree, find if it is height balanced or not. 
    A tree is height balanced if difference between heights of 
    left and right subtrees is not more than one for all nodes 
    of tree. 

    It can also be solved using pair<bool,int> concept
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
    private:
        int height(Node *root,int &flag){
            if(root==NULL){
                return 0;
            }
            int leftHeight = height(root->left,flag);
            int rightHeight = height(root->right,flag);

            if(leftHeight-rightHeight>1 || rightHeight-leftHeight>1){
                flag=1;
            }
            return 1+max(leftHeight,rightHeight);
        }
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool,int> isBalancedfast(Node *root){
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }

        pair<bool,int> left = isBalancedfast(root->left);
        pair<bool,int> right = isBalancedfast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = abs(left.second-right.second)<=1;

        pair<bool,int> ans;
        ans.second = 1 + max(left.second,right.second);

        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        int flag = 0;
        int h = height(root,flag);
        if(flag){
            return false;
        }
        else{
            return true;
        }
    }

};

