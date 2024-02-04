/*
    https://www.geeksforgeeks.org/convert-bst-min-heap/
*/

#include <iostream>
#include <vector>
#include <queue>
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

void inorderTraversal(Node* root, vector<int> &arr){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left,arr);
    arr.push_back(root->data);
    inorderTraversal(root->right,arr);
}

void bstToHeap(Node* &root, vector<int> arr, int &index){
    if(root==NULL){
        return;
    }
    root->data = arr[index];
    index++;

    bstToHeap(root->left, arr, index);
    bstToHeap(root->right,arr,index);
}

Node* ConvertToHeap(Node* root){
    if(root==NULL){
        return NULL;
    }

    vector<int> arr;
    int index = 0;
    inorderTraversal(root,arr);
    bstToHeap(root,arr,index);

    return root;
}

int main(){
    Node* root;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    root = ConvertToHeap(root);

    levelOrderTraversal(root);
    return 0;
}


