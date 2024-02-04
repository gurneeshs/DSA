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

int minVal(Node* root){
    Node* temp  = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp->data;
}

int maxVal(Node* root){
    if(root==NULL){
        return -1;
    }
    Node* temp  = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp->data;
}

Node* deletefromBST(Node* root, int val){
    if(root==NULL){
        return NULL;
    }
    if(root->data==val){
        // 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // 1 child
        if(root->left!=NULL && root->right==NULL){
            // left Child
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            // right Child
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini = minVal(root->right);
            root->data = mini;
            root->right = deletefromBST(root->right,mini);
            return root;
        }
    }
    else if(val>root->data){
        root->right = deletefromBST(root->right,val);
        return root;
    }
    else{
        root->left = deletefromBST(root->left,val);
        return root;
    }
}
int main(){
    Node *root = NULL;
    takeInput(root);

    inorder(root);
    cout<<endl;
    
    cout<<"Enter Data To delete";
    int d;
    cin>>d;
    deletefromBST(root,d);
    inorder(root);

    return 0;
}

