/*
    Build Min Heap
*/
#include <iostream>
#include <vector>
using namespace std;


void heapify(vector<int> &arr, int small){
    int i = small;
    int n = arr.size();

    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && arr[l]<=arr[small]){
        small = l;
    }
    if(r<n && arr[r]<=arr[small]){
        small = r;
    }

    if(small!=i){
        swap(arr[i],arr[small]);
        heapify(arr,small);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int N = arr.size();
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, i);

    return arr;
}
