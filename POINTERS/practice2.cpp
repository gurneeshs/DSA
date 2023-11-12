#include <iostream>
using namespace std;

int main(){

    int arr[5] = {11,22,31,40,55};
    cout<<"arr: "<<arr<<endl;
    cout<<"&arr: "<<&arr<<endl;
    cout<<"arr+1: "<<arr+1<<endl;
    cout<<"&arr[1]: "<<&arr[1]<<endl;
    cout<<"*(arr): "<<*arr<<endl;
    cout<<"*(arr+1): "<<*(arr+1)<<endl;
    cout<<"*arr+1: "<<*arr+1<<endl;


    return 0;
}