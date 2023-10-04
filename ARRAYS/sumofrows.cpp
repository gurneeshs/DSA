// **********TO FIND THE SUM OF EACH ROW IN A 2D ARRAY***********************

#include <iostream>
using namespace std;

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
    int sum = 0;
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            sum+=arr[i][j];
        }
        cout<<"Sum is:"<<sum<<endl;
        sum = 0;
    }
    cout<<endl;
    
    return 0;
}