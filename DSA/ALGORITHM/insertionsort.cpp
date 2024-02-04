// ****************************************************************************
// STABLE ALGORITHM
// BEST TIME COMPLEXITY: O(n)
// WORST TIME COMPLEXITY: O(n^2)
// USE CASE:- Small size array/list, when Const. space is needed
// ****************************************************************************

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {8,6,12,10,14,7,9,2};
    int n = arr.size();

    for(int itm:arr){
        cout<<itm<<" ";
    }
    cout<<endl;

    for(int i=1;i<n;i++){
        int temp = arr[i];
        int loc = i;
        int j = i-1;
        while(j>=0)
        {
            if(temp<arr[j])
            {
                loc = j;
                arr[j+1]=arr[j];
            }
            j--;
        }
        arr[loc]=temp;
    }

    for(int itm:arr){
        cout<<itm<<" ";
    }
    cout<<endl;
    return 0;
}