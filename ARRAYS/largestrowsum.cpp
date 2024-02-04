
// ********** FIND THE SUM OF EACH ROW AND RETURN THE LARGEST SUM AND ITS ROW NUMBER***************
#include <iostream>
using namespace std;
void largestRowSum(int arr[3][4]){
    int sum = 0, maxi = INT16_MIN, idx = -1;
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            sum+=arr[i][j];
        }
        if(sum>maxi){
            maxi = sum;
            idx = i;
        }
        sum=0;
    }
    cout<<"Largest Sum is "<<maxi<<" of "<<idx+1<<" row"<<endl;

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
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    largestRowSum(arr);
    return 0;

}