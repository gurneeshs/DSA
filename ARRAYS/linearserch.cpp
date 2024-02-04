#include <iostream>
using namespace std;
bool linearSearch(int arr[], int n, int element){
    bool ret = false;
    for (int i = 0;i<n;i++){
        if(arr[i]==element){
            ret = true;
            break;
        }
    }
    return ret;
}
int main(){
    int size,element;
    cout<<"Enter Size of Array:";
    cin>>size;
    cout<<"Enter Array Elements:";
    int num[100];
    for (int i=0;i<size;i++){
        cin>>num[i];
    }
    cout<<"Enter Element to Search";
    cin>>element;
    if(linearSearch(num,size,element)){
        cout<<"Element is present in array";
    }
    else{
        cout<<"Element is not preset in array";
    }
    return 0;
}