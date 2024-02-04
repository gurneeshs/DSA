/*
    https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
    Given an array arr[] and an integer K where K is smaller than size of array, 
    the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

    Note :-  l and r denotes the starting and ending index of the array.
*/
#include <iostream>
#include <queue>
using namespace std;

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> pq;
        
        // STEP 1
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        
        for(int i=k;i<=r;i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        // STEP 3
        int ans = pq.top();
        return ans;
    }
};