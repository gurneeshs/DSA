// #include <iostream>
// using namespace std;

// struct Node{
//     int data;
//     Node* left;
//     Node* right;
// };

// class Solution
// {
//     public:
//     void preOrderTraversal(Node* root, Node* &list){
//         if(root==NULL){
//             return;
//         }
//         list->right = root;
//         list = list->right;
//         list->left=NULL;
//         preOrderTraversal(root->left,list);
//         preOrderTraversal(root->right,list);
//     }
//     void flatten(Node *root)
//     {
//         //code her
//         Node* list;
//         Node* head = list;
//         preOrderTraversal(root,list);
//         root = head->right;
//         root->left=NULL;
//     }
// };


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
class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        if(root==NULL){
            return;
        }
        Node *curr, *pred;
        curr = root;
        while(curr!=NULL){
            if(curr->left==NULL){
                curr = curr->right;
            }
            else{
                pred = curr->left;
                while(pred->right!=NULL){
                    pred = pred->right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left=NULL;
            }
        }
    }
};
int main(){
    Node *root;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 -1 10 -1 -1
    
    buildFromLevelOrder(root);
    Solution s;
    s.flatten(root);
    Node* temp = root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    return 0;
}