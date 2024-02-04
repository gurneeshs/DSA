/*
    Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.
*/
#include <iostream>
#include <vector>
#include <queue>
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


class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> result;
    	
    	if(root==NULL){
    	    return result;
    	}
    	
    	queue<Node*> q;
    	q.push(root);
    	Node* temp;
    	bool Left = true;//Left Turn or Right Turn
    	
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int> tempArr(size);
    	    
    	    for(int i=0;i<size;i++){
    	        temp = q.front();
    	        q.pop();

    	        int index = Left?i:size-i-1;
    	        tempArr[index] = temp->data;
    	        
    	        if(temp->left){
    	            q.push(temp->left);
    	        }
    	        if(temp->right){
    	            q.push(temp->right);
    	        }
    	    }
    	    Left = !Left; // Changing Direction
    	    for(auto i:tempArr){
    	        result.push_back(i);
    	    }
    	}
    	return result;
    }
    
};