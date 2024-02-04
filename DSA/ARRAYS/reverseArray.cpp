#include <iostream>
using namespace std;

void printArray(int arr[],int n){
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]";
    cout<<endl;
}

int reverseArray(int arr[],int n){
    int start = 0;
    int end = n-1;
    int temp = 0;

    while(start<=end){
        temp = arr[start];
        arr[start]= arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    return 0;
}

int main()
{
    int size;
    cout<<"Enter Size of Array:";
    cin>>size;
    cout<<"Enter Array Elements:";
    int num[100];

    for (int i=0;i<size;i++){
        cin>>num[i];
    }
    printArray(num,size);
    reverseArray(num,size);
    printArray(num,size);

}