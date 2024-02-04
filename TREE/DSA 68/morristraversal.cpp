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

void morrisTraversal(Node* root){
    if(root==NULL){
        return;
    }
    Node* curr, *pre;

    curr = root;

    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            pre = curr->left;
            while(pre->right!=NULL && pre->right!=curr){
                pre = pre->right;
            }
            if(pre->right==NULL){
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right=NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}
void morrisTraversalPre(Node* root){
    if(root==NULL){
        return;
    }
    Node* curr, *pre;

    curr = root;

    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            cout<<curr->data<<" ";
            pre = curr->left;
            while(pre->right!=NULL && pre->right!=curr){
                pre = pre->right;
            }
            if(pre->right==NULL){
                pre->right = curr->right;
                curr = curr->left;
            }
            else{
                pre->right=NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}

void buildFromLevelOrder(Node* &root){
    queue<Node*> q;
    
    cout<<"Enter data for root node"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<<temp->data<<endl;
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
    // 1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 -1 10 -1 -1
    
    buildFromLevelOrder(root);
    morrisTraversalPre(root);
    return 0;

}
