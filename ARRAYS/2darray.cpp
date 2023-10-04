#include <iostream>
using namespace std;

int main(){
    // METHOD 1
    int arr[3][4] = {{10,20,30,40},{50,60,70,80},{51,61,71,81}};
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    // METHOD 2
    int arr1[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    // METHOD 3
    int arr2[3][4] = {};
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr2[i][j];
        }
    }
    cout<<endl;
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    // METHOD 4
    int arr3[3][4] = {};
    for (int j=0;j<4;j++){
        for(int i=0;i<3;i++){
            cin>>arr3[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
