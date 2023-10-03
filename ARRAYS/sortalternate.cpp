#include <iostream>
using namespace std;

void swap(int arr[], int pos, int size){
    if(pos+1<size)
    {
        int temp = arr[pos];
        arr[pos] = arr[pos+1];
        arr[pos+1]=temp;
    }
}
void printArray(int arr[],int size){
    cout<<"[";
    for (int i = 0; i<size ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
}
int main(){
    int size;
    cout<<"Enter Size of Array:";
    cin>>size;
    cout<<"Enter Array Elements:";
    int num[100];

    for (int i=0;i<size;i++)
    {
        cin>>num[i];
    }
    printArray(num,size);
    for (int i = 0;i<size;i++){
        swap(num,i,size);
        i++;
    }
    printArray(num,size);

    return 0;
}