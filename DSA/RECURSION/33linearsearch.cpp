#include <iostream>
using namespace std;

bool linearSearch(int arr[], int siz, int key){
    if(siz==0)
        return false;
    if(key == arr[0]){
        return true;
    }
    else{
        return linearSearch(arr+1, siz-1, key);
    }
}
int main(){
    int arr[5] = {2,5,8,3,9};
    int key = 81;
    bool ans = linearSearch(arr,5,key);
    cout<<"Element present:"<<ans;
    return 0;
}