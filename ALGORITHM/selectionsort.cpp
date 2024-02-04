// ****************************************************************************
// STABLE ALGORITHM
// BEST TIME COMPLEXITY: O(n^2)
// WORST TIME COMPLEXITY: O(n^2)
// USE CASE:- Small size array/list, when Const. space is needed
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
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
    for(int itm:arr){
        cout<<itm<<" ";
    }
    cout<<endl;
    return 0;
}