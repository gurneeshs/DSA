#include <iostream>
using namespace std;

int main(){
    char arr[20];
    cout<<"Enter any name:";
    cin>>arr;
    arr[3] = '\0';
    cout<<arr;
    return 0;
}