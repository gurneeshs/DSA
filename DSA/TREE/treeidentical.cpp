/*
    Given two binary trees, the task is to find if both of them are identical or not.
    Note: You need to return true or false, the printing is done by the driver code.
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


class Solution
{
    public:

    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==NULL && r2==NULL){
            return true;
        }
        if((r1==NULL && r2!=NULL)||(r1!=NULL && r2==NULL)){
            return false;
        }
        
        bool left = isIdentical(r1->left,r2->left);
        bool right = isIdentical(r1->right,r2->right);
        
        bool val = r1->data==r2->data;
        
        if(left && right && val){
            return true;
        }
        else{
            return false;
        }
    }
};