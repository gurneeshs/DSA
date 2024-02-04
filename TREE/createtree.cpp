/*
    Create a binary tree
*/

#include <iostream>
#include <queue>
#include <stack>
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

Node* buildTree(Node* root){
    cout<<"Enter data:"<<endl;
    int data;
    cin>>data;

    root = new Node(data);
    if(data==-1){
        return NULL;
    }

    cout<<"Enter data for left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp==NULL){
            // Level completed
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
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

    // Using iteration
    // stack<Node*> s;
    // Node* temp = root;

    // while(!s.empty() || temp!=NULL){
    //     while(temp!=NULL){
    //         s.push(temp);
    //         temp = temp->left;
    //     }
    //     temp = s.top();
    //     s.pop();
    //     cout<<temp->data<<" ";

    //     temp = temp->right;
    // }
}

void preorder(Node *root){
    // Root left Right
    
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void preorderIteration(Node* root){
    // Using iteration
    stack<Node*> s;
    Node* temp = root;
    s.push(temp);
    while(!s.empty()){
        temp = s.top();
        s.pop();
        cout<<temp->data<<" ";

        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }
}
void postorder(Node *root){
    //left Right Root
    
    if(root==NULL){
        return;
    }
 
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void postorderIteration(Node *root){
    stack<Node*> s;
    Node *temp = root;

    while(temp!=NULL || !s.empty()){
        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
        cout<<temp->data<<" ";
        temp = s.top();
        s.pop();
    }
}
void buildFromLevelOrder(Node* &root){
    queue<Node*> q;
    
    cout<<"Enter data for root Node"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left Node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right Node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }

    }

}

int main(){
    Node *root;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    // levelOrderTraversal(root);

    // inorder(root);cout<<endl;
    // preorder(root);cout<<endl;
    // postorder(root);cout<<endl;

    // buildFromLevelOrder(root);
    // levelOrderTraversal(root);
    // inorder(root);
    preorderIteration(root);
    return 0;
}