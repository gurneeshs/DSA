/*
    https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
    Given two binary max heaps as arrays, merge the given heaps to form a new max heap.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    void heapify(vector<int> &arr, int siz ,int largest){
        int i = largest;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left<siz && arr[left]>arr[largest]){
            largest = left;
        }
        if(right<siz && arr[right]>arr[largest]){
            largest = right;
        }
        
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr,siz,largest);
        }
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
        
        // STEP 1: MERGE BOTH VECTORS
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        
        // STEP 2: BUILD HEAP
        int siz = ans.size();
        for(int i = (siz/2)-1;i>=0;i--){
            heapify(ans,siz,i);
        }
        return ans;
    }
};