#include <iostream>
using namespace std;
void printArray(int arr[], int n){
    for (int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
int main(){
    int zero[15] = {0};
    printArray(zero, 15);
    int arry[5] = {1};
    int size = sizeof(arry)/sizeof(int);
    printArray(arry, size);
    cout<<size;
    return 0;
}