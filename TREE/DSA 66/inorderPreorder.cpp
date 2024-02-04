/*
    Given Inorder and Preorder of traversal
    You have to construct tree from it
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
    int findPos(int in[], int element, int st, int end){
        for(int i=st;i<=end;i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n){
        if (index>=n || inorderStart>inorderEnd){
            return NULL;
        }
        int element = pre[index++];
        // index++;
        int pos = findPos(in,element,inorderStart,inorderEnd);
        Node* temp = new Node(element);
        
        temp->left = solve(in,pre,index,inorderStart,pos-1,n);
        temp->right = solve(in,pre,index,pos+1,inorderEnd,n);
        return temp;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int index = 0;
        Node* ans = solve(in,pre,index,0,n-1,n);
        return ans;
    }
};