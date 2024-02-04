#include <iostream>
using namespace std;

int Power(int n){
    if(n==0)
        return 1;
    
    return 2 * Power(n-1);
}

int main(){
    int n;
    cout<<"Enter the Number: ";
    cin>>n;
    cout<<"Power of 2^"<<n<<" is: "<<Power(n);
    return 0;
}