// ***************TO PRINT THE 2D ARRAY IN SPIRAL PATTERN********************
/*
1 2 3 
4 5 6 ==>>  1 2 3 6 9 8 7 4 5  
7 8 9
*/

#include <iostream>
using namespace std;

void printArray(int arr[][4], int r, int cl){
    for (int i=0;i<r;i++){
        for(int j=0;j<cl;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void spiralPrint(int arr[][4], int r, int cl){
    int count = r*cl;
    int str = 0, stcl = 0, endr = r-1, endcl = cl-1;
    int el = 0;

    while(el<count){
        // starting row
        for(int idx = stcl;el<count && idx<=endcl;idx++){
            cout<<arr[str][idx]<<" ";
            el++;
            
        }
        str++;
        // ending column
        for(int idx = str;el<count && idx<=endr;idx++){
            cout<<arr[idx][endcl]<<" ";
            el++;
        }
        endcl--;
        // ending row
        for(int idx = endcl;el<count && idx>=stcl;idx--){
            cout<<arr[endr][idx]<<" ";
            el++;
        }
        endr--;
        // starting column
        for(int idx = endr;el<count && idx>=str;idx--){
            cout<<arr[idx][stcl]<<" ";
            el++;
        }
        stcl++;
    }

}

int main(){
    int arr[3][4] = {};
    cout<<"Enter Elements for array"<<endl;
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    printArray(arr, 3 , 4);
    spiralPrint(arr,3,4);
    return 0;
}