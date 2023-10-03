#include <iostream>
using namespace std;

int main(){
    int num;
    bool notprime = false;
    cout<<"Enter any Number: ";
    cin>>num;

    for (int i=2;i<num;i++){
        if(num%i==0){
            notprime = true;
            break;
        }
    }
    if(notprime){
        cout<<"Given Number is not Prime";
    }
    else{
        cout<<"Given Number is Prime";
    }
}