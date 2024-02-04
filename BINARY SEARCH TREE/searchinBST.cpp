
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};
Node* insertInBST(Node* root, int dat){
    // base case
    if(root==NULL){
        root = new Node(dat);
        return root;
    }

    if(dat > root->data){
        // Insert in right
        root->right = insertInBST(root->right,dat);
    }
    else{
        // Insert in left
        root->left = insertInBST(root->left,dat);
    }
    return root;
}

void takeInput(Node* &root){
    int d;
    cout<<"Enter the Data: ";
    cin>>d;

    while(d!=-1){

        root = insertInBST(root,d);
        cout<<"Enter the Data: ";
        cin>>d;

    }
}

void inorder(Node *root){
    // Left Root Right
    // base case
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool searchInBST(Node* root,int val){
    if(root->data==val){
        return true;
    }

    if(val>root->data){
        return searchInBST(root->right,val);
    }
    else{
        return searchInBST(root->left,val);
    }
    return false;
}
int main(){
    Node *root = NULL;
    takeInput(root);

    inorder(root);
    return 0;
}