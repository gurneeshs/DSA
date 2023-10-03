#include <iostream>
#include <array>
using namespace std;

int main(){
    // declaration
    array<int,5> arr = {2,9,7,8,1};

    // Traversal
    for (int itm:arr){
        cout<<itm<<" ";
    }
    cout<<endl;
    for (int i =0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // Methods
    cout<<"Size of Array:"<<arr.size()<<endl;
    cout<<"Item at 2 Position:"<<arr.at(2)<<endl;
    cout<<"Is Array Empty:"<<arr.empty()<<endl;
    cout<<"Front Element:"<<arr.front()<<endl;
    cout<<"Back Element:"<<arr.back()<<endl;

    return 0;
}