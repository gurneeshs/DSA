#include <iostream>
using namespace std;
int factorial(int n){
    int fact = 1;
    for(int i = n;i>=1;i--){
        fact = fact * i;
    }
    return fact;
}
void findnCr(int n, int r){
    int num = factorial(n);
    int deno = factorial(r) * factorial(n-r);
    int result = num/deno;
    cout<<result<<endl;
}
int main(){
    int n,r;
    cout<<"Enter the Value of n";
    cin>>n;

    cout<<"Enter the value of r";
    cin>>r;

    findnCr(n,r);
    return 0;
}