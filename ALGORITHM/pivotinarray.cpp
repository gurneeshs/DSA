/*
    Pivot is the element which is minimum in array. It can be maximum
    (but we solve using minimum).

    Sorted Array = [1,2,3,7,9]
    Sorted + Rotated Array = [7,9,1,2,3]
*/
#include <iostream>
using namespace std;

int getPivot(int arr[], int n){
    int s =0, e = n-1;
    int mid = s + ((e-s)/2);
    while (s<e){
        if(arr[mid]>=arr[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + ((e-s)/2);
    }
    return s;
}

int main(){
    int arr[5] = {7,9,1,2,3};
    cout<<"Pivot is "<<getPivot(arr,5);
    return 0;
}