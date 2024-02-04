/*
    https://www.codingninjas.com/studio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
    Given an array of integers, find the Kth largest sum subarray For example, given
    the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5], 
    which has a sum of 4.

    Please note that a subarray is the sequence of consecutive elements of the array.
*/
#include <iostream>
#include <queue>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here
	// STEP 1: BUILD MIN HEAP
	priority_queue<int, vector<int>, greater<int> > minHeap;
	int n = arr.size();

	for(int i = 0;i<n;i++){
		int sum = 0;
		for(int j=i;j<n;j++){
			sum += arr[j];
			if(minHeap.size()<k){
				minHeap.push(sum);
			}
			else{
				if(sum>minHeap.top()){
					minHeap.pop();
					minHeap.push(sum);
				}
			}
		}
	}
	return minHeap.top();
}