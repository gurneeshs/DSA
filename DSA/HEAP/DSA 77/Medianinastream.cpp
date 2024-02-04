/*
    https://www.codingninjas.com/studio/problems/median-in-a-stream_975268?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
    Given that integers are read from a data stream. Y
    our task is to find the median of the elements read so far.

    Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.
*/

#include <iostream>
#include <queue>
using namespace std;
int signum(int a, int b){
	if(a==b){
		return 0;
	}
	else if(a>b){
		return 1;
	}
	else{
		return -1;
	}
}
void callMedian(int element, priority_queue<int> &maxHeap, priority_queue<int,vector<int>,greater<int> > &minHeap, int &median){
	switch(signum(maxHeap.size(),minHeap.size())){
		case 0:
			if(element>median){
				minHeap.push(element);
				median = minHeap.top();
			}
			else{
				maxHeap.push(element);
				median = maxHeap.top();
			}
			break;
		
		case 1:
			if(element>median){
				minHeap.push(element);
			}
			else{
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(element);
			}
			median = (minHeap.top()+maxHeap.top())/2;
			break;

		case -1:
			if(element>median){
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(element);
			}
			else{
				maxHeap.push(element);
			}
			median = (minHeap.top()+maxHeap.top())/2;
			break;
	}
}
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	// STEP 1: Create Vector, MinHeap, MaxHeap
	vector<int> ans;
	priority_queue<int> maxHeap;
	priority_queue<int,vector<int>,greater<int> > minHeap;
	int median = -1;
	for(int i=0;i<n;i++){
		callMedian(arr[i],maxHeap,minHeap,median);
		ans.push_back(median);
	}
	return ans;
}
