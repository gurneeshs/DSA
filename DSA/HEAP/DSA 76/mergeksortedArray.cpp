/*
    https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
    You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). 
    You need to merge all the given arrays/list such that the output array/list should be sorted in 
    ascending order.
*/
#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        int i;
        int j;
    Node(int val, int row, int col){
        data = val;
        i = row;
        j = col;
    }
};
class Compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Write your code here. 
    // STEP 1: CREATE MINHEAP
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    vector<int> ans;

    // STEP 2: PUSH FIRST ELEMENTS OF ALL ARRAYS INTO HEAP
    for(int i=0;i<k;i++){
        Node* tmp = new Node(arr[i][0], i , 0);
        minHeap.push(tmp);
    }

    // STEP 3:
    while(minHeap.size()>=1){

        Node* tmp  = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();

        int i = tmp->i;
        int j = tmp->j;

        if(j+1 < arr[i].size()){
            Node* next = new Node(arr[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }
    return ans;
}
