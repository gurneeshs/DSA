#include <iostream>
using namespace std;
int sumArray(int arr[], int n){
    int sum = 0;
    for (int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int main(){
    int size;
    cout<<"Enter Size of Array:";
    cin>>size;
    cout<<"Enter Array Elements:";
    int num[100];
    for (int i=0;i<size;i++){
        cin>>num[i];
    }

    cout<<"Sum of elements of array is:"<<sumArray(num,size);
    return 0;
}