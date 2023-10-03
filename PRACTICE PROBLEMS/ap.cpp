#include <iostream>
using namespace std;

int aP(int n){
    return 3*n+7;
}

int main(){
    int n;
    cout<<"AP: 3n + 7"<<endl;
    cout<<"Enter the value on n";
    cin>>n;
    int result = aP(n);
    cout<<result<<endl;
    return 0;
}