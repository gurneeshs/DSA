
/*
    The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 
    https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
    
    
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

class Solution {
  private:
    pair<int,int> fastDiameter(Node* root){
        // first -> diameter, second -> height
        if(root==NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = fastDiameter(root->left);
        pair<int,int> right = fastDiameter(root->right);
        
        int op1 = left.first;
        int op2= right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.first = max(op1, max(op2,op3));
        ans.second = 1 + max(left.second, right.second);
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        return fastDiameter(root).first;
    }
};