
#include <iostream>
using namespace std;

void heapify(int arr[], int N, int i)
{
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int l = 2 * i ;
 
    // right = 2*i + 2
    int r = 2 * i + 1;
 
    // If left child is larger than root
    if (l <= N && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest
    // so far
    if (r <= N && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(int arr[], int N)
{
 
    // Build heap (rearrange array)
    for (int i = N / 2 ; i >= 1; i--)
        heapify(arr, N, i);
 
    // One by one extract an element
    // from heap
    int i = N;
    while(i>=1) {
 
        // Move current root to end
        swap(arr[i], arr[1]);
        i--;
 
        // call max heapify on the reduced heap
        heapify(arr, i, 1);
    }
}
void printArray(int *arr, int siz){
    for(int i=1;i<=siz;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[8] = {-1,80,45,70,40,35,50,90};
    printArray(arr,7);
    heapSort(arr,7);
    printArray(arr,7);
    return 0;
}