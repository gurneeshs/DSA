// ****************************************************************************
// STABLE ALGORITHM
// BEST TIME COMPLEXITY: O(n)
// WORST TIME COMPLEXITY: O(n^2)
// USE CASE:-
// ****************************************************************************

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {54,48,12,79,2,0};
    int n = arr.size();

    for(int itm:arr){
        cout<<itm<<" ";
    }
    cout<<endl;
    bool swaped = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swaped = true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(!swaped){
            break;
        }
    }

    for(int itm:arr){
        cout<<itm<<" ";
    }
    cout<<endl;
    return 0;
}