#include <iostream>
using namespace std;

int setBit(int n){
    int cnt =0;
    while(n>0){
        int bit = n%2;
        if(bit==1){
            cnt++;
        }
        n=n/2;
    }
    return cnt;
}

int main(){
    int a,b,sum;
    cout<<"Enter a";
    cin>>a;
    cout<<"Enter b";
    cin>>b;
    sum = setBit(a) + setBit(b);
    cout<<"Result:"<<sum<<endl;

    return 0;
}