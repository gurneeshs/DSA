/*
    Given Inorder and Postorder of traversal
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

    int findPos(int in[], int element, int st, int end){
        for(int i=st;i<=end;i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n){
        if (index<0 || inorderStart>inorderEnd){
            return NULL;
        }
        int element = post[index--];
        // index++;
        int pos = findPos(in,element,inorderStart,inorderEnd);
        Node* temp = new Node(element);

        temp->right = solve(in,post,index,pos+1,inorderEnd,n);
        temp->left = solve(in,post,index,inorderStart,pos-1,n);
        return temp;
    }

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int index = n-1;
    Node* ans = solve(in,post,index,0,n-1,n);
    return ans;
}
