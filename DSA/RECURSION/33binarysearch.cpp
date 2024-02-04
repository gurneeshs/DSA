/*
Implement Binary Search Using Binary Tree
*/

#include <iostream>
using namespace std;
void binarySearch(int arr[], int start, int end, int key){
    if(start>end){
        cout<<"Element not found";
        return;
    }
    int mid = start + ((end-start)/2);
    if(arr[mid]==key){
        cout<<"Element Found at "<<mid;
        return;
    }

    else if(arr[mid]<key){
        binarySearch(arr,mid+1,end,key);
    }
    else{
        binarySearch(arr,start,mid-1,key);
    }
}
int main(){
    int arr[10] = {2,4,6,10,14,16};
    binarySearch(arr,0,5,106);
    return 0;
}