/*
    Given a Binary Tree, return Left view of it. 
    Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. 
    The task is to complete the function leftView(), which accepts root of the tree as argument
    https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
    
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
vector<int> leftView(Node *root)
{
   // Your code here
       
       vector<int> ans;
       // map<vertical_distance,data>
       map<int,int> m;
       // queue<Node,hd> q;
       queue<pair<Node*,int> > q;
       
       if(root==NULL){
           return ans;
       }
       
       q.push(make_pair(root,0));
       
       while(!q.empty()){
           pair<Node*, int> temp = q.front();
           q.pop();
           
           Node* frontNode = temp.first;
           int vd = temp.second;
           if(m.find(vd)==m.end()){
                m[vd] = frontNode->data;
           }
           
           if(frontNode->left){
               q.push(make_pair(frontNode->left,vd+1));
           }
           if(frontNode->right){
               q.push(make_pair(frontNode->right,vd+1));
           }
       }
       for(auto i:m){
           ans.push_back(i.second);
       }
       return ans;
}
