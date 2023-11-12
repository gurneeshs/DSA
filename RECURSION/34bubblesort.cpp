/*
Implement Bubble Sort using Recursion
*/
#include <iostream>
using namespace std;

// void swap(int& a, int& b){

//     int temp = a;
//     a = b;
//     b = temp;
// }

void BubbleSort(int *arr, int n){
    if(n==0 || n==1){
        return;
    }

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    BubbleSort(arr, n-1);
}
void PrintArray(int *arr, int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[5] = {1,0,45,2,9};
    cout<<"Before Sorting: ";
    PrintArray(arr, 5);

    BubbleSort(arr, 5);
    
    cout<<"After Sorting: ";
    PrintArray(arr, 5);
    return 0;
}