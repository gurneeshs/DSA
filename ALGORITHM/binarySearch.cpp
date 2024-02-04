#include <iostream>
using namespace std;

int binarySearch(int arr[],int size, int key){
    int start = 0;
    int end = size - 1;

    int mid  = start + ((end - start)/2);

    while (start<=end)
    {
        if(arr[mid]==key){
            return mid;
        }
        else if(key > arr[mid]){
            start = mid + 1;
        }
        else{
            end =mid - 1;
        }
        mid  = start + ((end - start)/2);

    }
    return -1;
    
}
int main(){
    int arr1[6] = {2,4,5,8,9,10};
    int arr2[5] = {1,3,5,8,9};

    cout<<"Index of 9 in arr1"<<binarySearch(arr1,6,9)<<endl;   
    cout<<"Index of 3 in arr2"<<binarySearch(arr2,5,3)<<endl;   
    return 0;
}

// *******************************************************************************
// 1. mid = (start + end)/2 fails if start = INT_MAX and end = INT_MAX
// 2. complexity : log(n)
// *******************************************************************************