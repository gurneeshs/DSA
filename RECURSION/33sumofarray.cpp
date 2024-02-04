#include <iostream>
using namespace std;
int Sum(int arr[], int siz){
    if(siz==0){
        return 0;
    }
    int sum = arr[0] + Sum(arr+1, siz-1);
    return sum;

}
int main(){
    int arr[10] = {10,20,60,100,80};
    cout<<"Sum is "<<Sum(arr,5);
    return 0;

}