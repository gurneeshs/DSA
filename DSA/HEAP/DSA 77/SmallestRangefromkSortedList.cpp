/*
    https://www.codingninjas.com/studio/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
    You are given ‘K’ lists containing non-negative integers. Each list has a size ‘N’ and is sorted in non-decreasing order. You need to find the minimum length of a range such that at least one element of each list must be included in that range.

    For example :

    If we have 3 lists as [1, 10, 11], [2, 3, 20], [5, 6, 12] then the [1, 5] is the range that includes 1 from the first list, 2,3 from the second list, and 5 from the third list i.e, this range contains at least one element from each list.
*/
#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
        int data;
        int row;
        int col;

        Node(int data, int row, int col){
            this->data = data;
            this->row = row;
            this->col = col;
        }
};
class Compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};
int kSorted(vector<vector<int>> &arr, int k, int n) {
    // Write your code here.
    int mini = INT32_MAX;
    int maxi = INT32_MIN;
    priority_queue<Node*, vector<Node*>, Compare > minHeap;

    for(int i=0;i<k;i++){
        int el = arr[i][0];
        mini = min(mini,el);
        maxi = max(maxi,el);

        Node* tmp = new Node(el,i,0);
        minHeap.push(tmp);
    }

    int start = mini, end = maxi;

    while(!minHeap.empty()){

        Node* tmp = minHeap.top();
        minHeap.pop();

        mini = tmp->data;

        if(maxi-mini < end-start){
            start = mini;
            end = maxi;
        }

        if(tmp->col+1 < n){
            maxi = max(maxi, arr[tmp->row][tmp->col+1]);
            Node* next = new Node(arr[tmp->row][tmp->col+1],tmp->row,tmp->col+1);
            minHeap.push(next);
        }
        else{
            break;
        }
    }
    return (end-start+1);

}
