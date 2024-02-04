/*
    https://www.codingninjas.com/studio/problems/merge-k-sorted-lists_992772?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
    Given 'k' sorted linked lists, each list is sorted in increasing order. You need to merge all these 
    lists into one single sorted list. You need to return the head of the final linked list.

*/


#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
class Compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};
Node* mergeKLists(vector<Node*> &arr){
    
    // STEP 1: CREATE MINHEAP
    priority_queue< Node*, vector<Node*>, Compare > minHeap;
    int siz = arr.size();
    Node* ans  = new Node(-404);
    Node* head = ans;

    // STEP 2: PUSH FIRST ELEMENTS OF ALL ARRAYS INTO HEAP
    for(int i=0;i<siz;i++){
        Node* tmp = arr[i];
        minHeap.push(tmp);
    }

    // STEP 3:
    while(minHeap.size()>=1){

        Node* tmp  = minHeap.top();
        minHeap.pop();
        ans->next = tmp;
        ans = tmp;

        if(tmp->next!=NULL){
            tmp = tmp->next;
            minHeap.push(tmp);
        }
    }
    head = head->next;
    return head;
}
