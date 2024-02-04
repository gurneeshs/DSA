/*
    Given a Binary Tree, print the diagonal traversal of the binary tree.
    Consider lines of slope -1 passing between nodes. 
    Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
    If the diagonal element are present in two different subtress then left subtree diagonal 
    element should be taken first and then right subtree. 

    https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};
vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   if(root==NULL){
       return ans;
   }
   
   queue<Node*> curr, next;
   curr.push(root);
   
   while(!curr.empty()){
       Node* temp = curr.front();
       curr.pop();
       
       ans.push_back(temp->data);
       
       if(temp->left){
           next.push(temp->left);
       }
       if(temp->right){
           curr.push(temp->right);
       }
       
       if(curr.empty() && !next.empty()){
           curr.push(next.front());
           next.pop();
       }
   }
   return ans;
}