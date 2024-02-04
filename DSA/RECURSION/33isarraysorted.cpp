/*
    Given an array of size n, you have to find whether the array is
    sorted or not using recursion.
*/

#include <iostream>
using namespace std;

bool isSorted(int arr[], int size){
    // base case
    if(size==0 || size==1)
        return true;

    if(arr[0]>arr[1])
        return false;
    else
        return isSorted(arr+1, size-1);

    // arr+1 is a pointer to next location of arr
}

int main(){

    int arr[5] = {1,2,3,4,5};

    if(isSorted(arr,5))
        cout<<"Array is  sorted";
    else
        cout<<"Array is not sorted";
    return 0;

}