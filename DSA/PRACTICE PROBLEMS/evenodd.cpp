#include <iostream>
using namespace std;

void evenOdd(int num){
    if(num%2==0){
        cout<<"Even Number"<<endl;
    }
    else{
        cout<<"Odd Number"<<endl;
    }
}

int main(){
    int num;
    cout<<"Enter Any Number:";
    cin>>num;
    evenOdd(num);
    return 0;
}