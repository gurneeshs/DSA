#include <iostream>
using namespace std;

int getMax(int num[], int n){
    int max = INT32_MIN;

    for (int i=0;i<n;i++){
        if(num[i]>max){
            max = num[i];
        }
    }
    return max;
}
int getMin(int num[], int n){
    int min = INT32_MAX;

    for (int i=0;i<n;i++){
        if(num[i]<min){
            min = num[i];
        }
    }
    return min;
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

    cout<<"Maximum Value:"<<getMax(num, size)<<endl;
    cout<<"Minimum Value:"<<getMin(num, size)<<endl;
    return 0;
}