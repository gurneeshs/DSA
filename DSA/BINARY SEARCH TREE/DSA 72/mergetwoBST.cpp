/*
    You are given two binary search trees of integers having ‘N’ and ‘M’ nodes. 
    Return an array that contains elements of both BST in sorted order.
    https://www.codingninjas.com/studio/problems/h_920474?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

*/

#include <iostream>
#include <vector>
using namespace std;


class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };


TreeNode* BToDLL(TreeNode* root)
{
	TreeNode* curr = root;

	// Store head & tail of the linked list
	// created so far
	TreeNode *head = NULL, *tail = NULL;

	// Morris Traversal
	while (curr) {

		if (curr->left == NULL) {

			// If it is to be the first TreeNode
			// of the desired Linked list
			if (head == NULL) {
				head = curr;
				tail = curr;
			}
			else {

				// Append it to the tail of the
				// linked list we have created
				// so far & set it as new tail
				tail->right = curr;
				tail = tail->right;
			}

			curr = curr->right;
		}
		else {

			// Inorder predecessor
			TreeNode* pred = curr->left;
			while (pred->right != NULL
				&& pred->right != curr) {
				pred = pred->right;
			}

			if (pred->right == NULL) {
				pred->right = curr;
				curr = curr->left;
			}
			else {

				// Append it to the tail of
				// the linked list
				// we have created so far & set it
				// as new tail
				// Note we don't have to unlink
				// predecessor
				tail->right = curr;
				tail = tail->right;
				curr = curr->right;
			}
		}
	}
	return head;
}

TreeNode* mergeLinkedList(TreeNode *head1, TreeNode* head2){
    TreeNode* head;
    TreeNode* tail;

    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            if(head==NULL){
                head = head1;
                tail = head1;
                head1= head1->right;
            }
            else{
                tail->right=head1;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head==NULL){
                head = head2;
                tail = head2;
                head2= head2->right;
            }
            else{
                tail->right = head2;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1!=NULL){
        tail->right=head1;
        tail = head1;
        head1 = head1->right;
    }
    while(head2!=NULL){
        tail->right=head2;
        tail = head2;
        head2 = head2->right;
    }
    TreeNode* curr = head;
    TreeNode* prev = NULL;

    while(curr!=NULL){
        curr->left = prev;
        prev = curr;
        curr = curr->right;
    }
    return head;
}
int count(TreeNode* head){
    TreeNode* temp = head;
    int n = 0;
    while(temp!=NULL){
        n++;
        temp = temp->right;
    }
    return n;
}
TreeNode* sortedLLtoBST(TreeNode* &head, int n){
    // base case
    if(n<=0 || head==NULL){
        return NULL;
    }

    TreeNode* leftSubTree = sortedLLtoBST(head,n/2);
    TreeNode* root = head;
    root->left = leftSubTree;

    head = head->right;

    root->right = sortedLLtoBST(head,n-n/2-1);
    return root;

}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int> ans;
    // STEP 1: Convert into Linked List
    TreeNode* head1 = BToDLL(root1);
    TreeNode* head2 = BToDLL(root2);

    // STEP 2: Merge Two Linked List
    TreeNode* head = mergeLinkedList(head1, head2);

    // STEP 3: Convert to BST
    int n = count(head);
    TreeNode* root = sortedLLtoBST(head, n);

    TreeNode* temp = BToDLL(root);

    while(temp!=NULL){
        ans.push_back(temp->data);
        temp=temp->right;
    }
    return ans;
}